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


// 5567 결혼식

vector<int> adj[510];
int v[510];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 


    int N; cin >> N;
    int M; cin >> M;

    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

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

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (v[i] <= 3 && v[i] != 0) cnt++;        
    }

    cout << cnt - 1 << "\n";

    return 0;
}