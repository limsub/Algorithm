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

// 2468 안전 영역
// max, min값을 찾고, min ~ max까지 비가 올 때 모두 탐색

int N;
int min_r = 102;
int max_r = -1;
int graph[110][110];
int v[110][110];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void initV() {
    for (int i = 0; i < N; i++) {
        fill(v[i], v[i] + N, 0);
    }
}





void bfs(int startY, int startX, int limit) {
    queue< pair<int, int> > q;

    q.push(make_pair(startY, startX));
    v[startY][startX] = 1;


    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        
        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny >= N || ny < 0 || nx >= N || nx < 0) continue;
            if (v[ny][nx]) continue;
            if (graph[ny][nx] <= limit) continue;
            
            q.push(make_pair(ny, nx));
            v[ny][nx] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];

            min_r = min(graph[i][j], min_r);
            max_r = max(graph[i][j], max_r);
        }
    }

    int max_ans = 0;
    

    for (int k = max_r; k >= 0; k--) {  //

        initV();

        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (v[i][j] == 0 && graph[i][j] > k) {
                    bfs(i, j, k);
                    cnt++;
                }
            }
        }
        
        max_ans = max(cnt, max_ans);
    }

    cout << max_ans << "\n";
    

    return 0;
}