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


// 6118 숨바꼭질
// - 1번에서 가장 멀리 떨어진 위치 구하기?


int N, M;

vector<int> adj[20010];
int v[20010];


void bfs() {
    queue<int> q;
    q.push(1);
    v[1] = 1;


    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i];

            if (v[next]) continue;

            v[next] = v[cur] + 1;
            q.push(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    // 1. 입력
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }


    // 2. bfs
    bfs();


    // 3. 최댓값 찾기
    // int max_dist = *max_element(v, v + N+1);
    int max_dist = -1;
    for (int i = 1; i <= N; i++) {
        if (v[i] > max_dist) {
            max_dist = v[i];
        }
    }

    vector<int> max_arr;
    for (int i = 1; i <= N; i++) {
        if (v[i] == max_dist) {
            max_arr.push_back(i);
        }
    }
    sort(max_arr.begin(), max_arr.end());


    // 4. 출력
    cout << max_arr[0] << " " << max_dist - 1 << " " << max_arr.size();



    
    return 0;
}