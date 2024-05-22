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

// 5214 환승

// 1. cur 방문
// 2. cur가 속한 하이퍼튜브 찾기.
// 3. 해당 하이퍼튜브에 속한 노드들 탐색 (next)

// => 시간 초과



vector<int> hyper[1010];
int v[100010];
unordered_map<int, vector<int> > m;

void bfs() {
    queue<int> q;
    q.push(1); 
    v[1] = 1;

    while (!q.empty()) {
        // 1. cur 방문
        int cur = q.front(); q.pop();

        // 2. cur가 속한 하이버튜브 찾기
        // int hyper_num = m[cur];

        for (int k = 0; k < m[cur].size(); k++) {
            int hyper_num = m[cur][k];
            // cout << "cur : " << cur << " hyper_num : " << hyper_num << "\n";
            
            // 3. 해당 하이퍼튜브에 속한 노드들 탐색
            for (int i = 0; i < hyper[hyper_num].size(); i++) {
                if (hyper[hyper_num][i] == cur) continue;  // cur은 패스

                int next = hyper[hyper_num][i];

                if (v[next]) continue;

                q.push(next);
                v[next] = v[cur] + 1;
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int N, K, M; cin >> N >> K >> M;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            int x; cin >> x;
            hyper[i].push_back(x);  // i번 하이퍼튜브에 속한 노드들
            // m[x] = i;               // x 노드는 i번 하이퍼튜브에 속한다.
            m[x].push_back(i);
        }
    }

    bfs();

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(v[i], ans);
        // cout << i << " : " <<  v[i] << "\n";
    }

    cout << ans << "\n";


    



    return 0;
}