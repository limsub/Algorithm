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
// #include <pair>
// #include <bits/stdc++.h>



// 7662 이중 우선순위 큐

// 연산
// - 삽입
// - 삭제 - 제일 높은거 (원래)
// - 삭제 - 제일 낮은거 (-> 이걸 어떻게 구현할지)


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int T; cin >> T;

    while (T--) {

        int k; cin >> k;


        priority_queue<int, vector<int>, greater<int> > pq1;    // 값이 큰 게 맨 위
        priority_queue<int, vector<int>, less<int> > pq2;       // 값이 작은 게 맨 위

        int q_size = 0; // 큐의 사이즈 (공통)


        for (int i = 0; i < k; i++) {
            char x; int y;
            cin >> x >> y;

            switch (x) {
                case 'I':
                pq1.push(y);
                pq2.push(y);
                q_size++;
                break;

                case 'D':
                if (q_size > 0) {
                    q_size--;
                    switch (y) {
                        case 1:
                        pq1.pop();
                        break;

                        case -1:
                        pq2.pop();
                        break;
                    }
                }
                
                
                break;
            }

        }

        if (q_size > 0) { 
            cout << pq1.top() << " " << pq2.top() << "\n";
        } 
        else {
            cout << "EMPTY\n";
        }

    }


    

    return 0;
}