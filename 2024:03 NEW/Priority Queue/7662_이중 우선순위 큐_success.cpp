#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;
#include <queue>
#include <cstdio>
#include <set>
#include <map>
// #include <pair>
// #include <bits/stdc++.h>



// 7662 이중 우선순위 큐

// 연산
// - 삽입
// - 삭제 - 제일 높은거 (원래)
// - 삭제 - 제일 낮은거 (-> 이걸 어떻게 구현할지)

// 큐 두 개 활용.
// 각 숫자가 몇 개 남았는지 map에 저장. (몇 개라기보다는, 유효한 숫자인지 판단하기 위함)


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int T; cin >> T;

    while (T--) {

        int k; cin >> k;

        priority_queue<int, vector<int>, less<int> > pq1;    // 값이 큰 게 맨 위
        priority_queue<int, vector<int>, greater<int> > pq2;       // 값이 작은 게 맨 위

        map<int, int> num_cnt;

        for (int i = 0; i < k; i++) {
            char x; int y;
            cin >> x >> y;

            switch (x) {
                case 'I':
                pq1.push(y);
                pq2.push(y);
                num_cnt[y]++;
                break;

                case 'D':
                // 삭제 시 num_cnt 이용해서 유효한 숫자인지 판단한다.
                switch (y) {
                    case 1:
                    if (!pq1.empty() && num_cnt[pq1.top()] > 0) {
                        num_cnt[pq1.top()]--;
                        pq1.pop();
                    }

                    break;

                    case -1:
                    if (!pq2.empty() && num_cnt[pq2.top()] > 0) {
                        num_cnt[pq2.top()]--;
                        pq2.pop();
                    }
                    
                    break;
                }                
                
                break;
            }

            // 만약 현재 큐의 맨 위에 있는 애가 유효하지 않은 수라면, 유효한 수가 나올 때까지 pop
            while (!pq1.empty() && num_cnt[pq1.top()] == 0) {
                pq1.pop();
            }

            while (!pq2.empty() && num_cnt[pq2.top()] == 0) {
                pq2.pop();
            }

        }

        if (!pq1.empty()) { 
            cout << pq1.top() << " " << pq2.top() << "\n";
        } 
        else {
            cout << "EMPTY\n";
        }
    }
    return 0;
}