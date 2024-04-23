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

// 2583 영역 구하기

// 좌표 상태가 좀 이상하긴 한데, (1사분면 생각) - 배열 뒤집었다고 생각.

// 연습삼아 dfs로 해보았지만, bfs로 해도 무방

int graph[110][110];
int v[110][110];

int M, N, K;


int dy[] = {-1, 1, 0, 0 };
int dx[] = {0, 0, -1, 1 };

int cnt;

int d(int y, int x, int depth) {
    cnt++;
    int c_y = y; 
    int c_x = x;
    v[c_y][c_x] = depth;

    for (int dir = 0; dir < 4; dir++) {
        int n_y = c_y + dy[dir];
        int n_x = c_x + dx[dir];

        if (n_y >= M || n_y < 0 || n_x >= N || n_x < 0) continue;

        if (v[n_y][n_x]) continue;
        if (graph[n_y][n_x]) continue;

        d(n_y, n_x, depth + 1);
    }


    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    cin >> M >> N >> K;

    for (int i = 0; i < K; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                graph[y][x] = 1;
            }
        }
    }

    vector<int> ans;

    // 사각형의 넓이 찾기 -> dfs가 더 적절해보인다.
    // 이렇게 할거면 bfs했어도 상관 없다. (cnt 이용)
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (graph[i][j] == 0 && v[i][j] == 0) {
                cnt = 0;
                int x = d(i, j, 1);
                // cout << x << " ";
                ans.push_back(x);
                
            }
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int k = 0; k < ans.size(); k++) {
        cout << ans[k] << " ";
    }


    return 0;
}