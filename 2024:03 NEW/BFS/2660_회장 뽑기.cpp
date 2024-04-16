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



// 2660 회장 뽑기
// 1. 모든 노드에 대해 bfs
// 2. bfs 최대 거리가 가장 작은 노드 및 그 거리 저장


int N;

vector<int> adj[52];
int v[52];

int bfs(int start) {
    queue<int> q;
    q.push(start);
    v[start] = 1;

    int max_dist = 0;

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i];

            if (v[next]) continue;

            q.push(next);
            v[next] = v[cur] + 1;

            max_dist = max(max_dist, v[next]);
        }
    }

    // cout << start << " - " << max_dist << "\n";

    return max_dist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int N; cin >> N;

    while(1) {
        int x, y; cin >> x >> y;

        if (x == -1 && y == -1) break;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int dist_arr[52];
    int min_dist = 0x7F7F7F;
    for (int i = 1; i <= N; i++) {
        fill(v, v + N + 1, 0);

        int dist = bfs(i);
        min_dist = min(min_dist, dist);

        dist_arr[i] = dist;
    }


    vector<int> min_node;
    for (int i = 1; i <= N; i++) {
        if (dist_arr[i] == min_dist) {
            min_node.push_back(i);
        }
    }

    sort(min_node.begin(), min_node.end());


    cout << min_dist - 1 << " " <<  min_node.size() << "\n";
    for (int i = 0; i < min_node.size(); i++) {
        cout << min_node[i] << " ";
    }

    
    return 0;
}