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
// indegree 없는 애들 큐에 넣고, 큐에 들어있는 순서부터 탐색.
// 이 때, 큐에 있는 애들을 꺼낼 때 가장 숫자가 작은 애를 꺼내야 한다.
// 그럼 우선순위큐를 써야 하는가...? 근데 이러면 탐색 순서가 좀 엉킬수도

// 우선순위큐 쓰는 게 맞는듯 싶다
// 큐에 들어간 순간, 그 안에 있는 애들끼리의 탐색 순서는 의미가 없음
// 유일하게 있는 조건인 숫자 작은걸 써야 하니까, 애초에 큐 자체를 우선순위 큐 사용.

int indegree[32010];
vector<int> adj[32010];
int v[32010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int N, M; cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;

        adj[x].push_back(y);
        indegree[y]++;
    }

    // 위상정렬 bfs + priority queue
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

            if (v[next]) continue;

            indegree[next]--;

            if (indegree[next] == 0) { 
                pq.push(next);
                v[next] = 0;    // v가 필요한가..?
            }
        }
    }

    return 0;
}