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


// 1781 컵라면

// (데드라인, 컵라면) pair 이용
// pq1 : 데드라인 우선 제일 큰거 넣고, 그 다음 컵라면 큰거 넣기
// pq2 : 컵라면 우선 제일 큰거 넣고, 데드라인은 상관 없음 (역순으로 돌기 때문 - 이 다음에도 어차피 들어갈 수 있는 애)
// 가장 마지막 데드라인 (max) 기준으로 역순 for loop 실행.
// 각 loop 마다 들어갈 수 있는 애들을 pq1에서 다 꺼내서 pq2에 넣는다.
//          그 다음에 pq2.top()을 빼서 사용한다. 
// pq2에 들어가는 순간 deadline은 의미가 없어지기 때문에 계속 가능한 최댓값을 찾아서 넣는 식.

struct compare1 {
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
        if (p1.first == p2.first) { 
            return p1.second < p2.second;
        }

        return p1.first < p2.first;
        }
};

struct compare2 {
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
        return p1.second < p2.second;
    }
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int N; cin >> N;

    priority_queue< pair<int, int>, vector< pair<int, int> >, compare1> pq1;
    priority_queue< pair<int, int>, vector< pair<int, int> >, compare2> pq2;

    int max_d = -1;

    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;

        max_d = max(max_d, x);

        pq1.push(make_pair(x, y));
    }

    int sum = 0;
    for (int i = max_d; i > 0; i--) {

        // 데드라인이 i ~ max_d인 애들을 모조리 다 빼서 pq2로 넣는다.
        
        while (pq1.top().first >= i && !pq1.empty()) {
            pq2.push(pq1.top());
            pq1.pop();
        }
        
        // // pq2의 top을 빼서 사용한다.
        if (!pq2.empty()) {
            sum += pq2.top().second;
            pq2.pop();
        }
        
    }

    cout << sum << "\n";

    
    return 0;
}