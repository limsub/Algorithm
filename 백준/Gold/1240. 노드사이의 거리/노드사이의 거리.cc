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

// 1240 노드사이의 거리
// 트리라고 해서 크게 다를 거 없음. BFS 이용

// "최단 거리" - 간선의 weight가 있는 경우.
// 다익스트라.. 써야 하지 않나...?

// 만약 그래프라면, 다익스트라를 사용하지만, 
// 트리이기 때문에. 트리의 특성 : acyclic. "경로가 정해져 있다".

// 즉, 방문하기만 하면, 그 거리가 그냥 최단 거리가 된다.


int N, M;

vector< pair<int, int> > adj[1010]; // (거리, 노드)
int v[1010];

// 트리이기 때문에, 특정 노드를 방문했다 = 그게 그냥 바로 최단거리임.
// => v에 저장. 마지막에 1 빼주기.

void bfs(int start, int end) {
    queue<int> q;
    q.push(start);
    v[start] = 1;


    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i].second;

            // cout << "next : " << next << "\n";

            if (v[next]) continue;

            q.push(next);
            v[next] = v[cur] + adj[cur][i].first;   // next를 방문하기 위해 필요한 비용.

            if (next == end) return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    cin >> N >> M;

    for (int i = 0; i < N-1; i++) {
        int x, y, z; cin >> x >> y >> z;  // z : 거리

        adj[x].push_back(make_pair(z, y));
        adj[y].push_back(make_pair(z, x));
    }

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;

        fill(v, v + N + 1, 0);

        bfs(a, b);
        cout << v[b] - 1 << "\n";
    }

    return 0;
}