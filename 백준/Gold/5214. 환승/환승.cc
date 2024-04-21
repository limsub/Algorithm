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

// 모든 노드에 대해 간선 탐색을 하려고 하면, 간선이 너무 많아진다.
// 하이퍼튜브 하나를 하나의 노드라고 생각하고 탐색해야 한다.

// => 95% 틀

vector<int> adj[101010];    // 노드 개수 + 하이퍼튜브 개수
int v[101010];


void bfs() {
    queue<int> q;
    q.push(1); 
    v[1] = 1;

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i];

            if (v[next]) continue;

            q.push(next);
            v[next] = v[cur] + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int N, K, M; cin >> N >> K >> M;

    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < K; j++) {
            int x; cin >> x;

            // i번째 하이퍼튜브 (1 <= i <= M)
            // = N + i 번째 노드
            adj[x].push_back(i+N);
            adj[i+N].push_back(x);
        }
    }

    bfs();

    int ans = v[N];  
    // ans = 2 * m + 1 형태 (1 : start node, m : 방문한 실제 노드)
    // 진짜 정답 = m + 1

    if (ans == 0) { cout << "-1"; }
    else {
        cout << (ans - 1) / 2 + 1 << "\n";
    }
    

    return 0;
}