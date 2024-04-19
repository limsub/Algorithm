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

// 1766 문제집
// 위상정렬.

// 우선순위큐 이용하는 위상정렬
// bfs나 위상정렬 시 큐에 들어간 순간, 어차피 탐색이 예정된 애들이기 때문에 순서가 상관이 없다.
// 이 문제는 여기에 대해 순서를 지정함. "숫자가 작은 것"
// 따라서 이걸 우선순위큐를 이용해서 해결

// 위상정렬 시 v는 따로 필요 없다. 

int indegree[32010];
vector<int> adj[32010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int N, M; cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;

        adj[x].push_back(y);
        indegree[y]++;
    }

    // 위상정렬 + priority queue
    priority_queue<int, vector<int>, greater<int>  > pq;

    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int cur = pq.top(); pq.pop();

        cout << cur << " ";

        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i];

            // if (v[next]) continue;

            indegree[next]--;

            if (indegree[next] == 0) { 
                pq.push(next);
                // v[next] = 0;    // v가 필요한가..?
            }
        }
    }

    return 0;
}