#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <cmath>
#include <set>
using namespace std;
#include <string.h>
// #include <bits/stdc++.h>

// 14940 쉬운 최단거리
// 쉬운 BFS

int N, M;
int v[1001][1001]; // 초기값 -1로 하기. arr이 0인 곳은 초기값 0
int arr[1001][1001];

int dy[] = {-1, 1, 0, 0 };
int dx[] = {0, 0, -1, 1 };

int startY, startX;

void bfs() {
    cout << "hi" << "\n";
    queue< pair<int, int> > q;
    q.push(make_pair(startY, startX));

    while (!q.empty() ) {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        cout << curY << " " << curX << "\n";

        for (int dir = 0; dir < 4; dir++) {
            int nextY = curY + dy[dir];
            int nextX = curX + dx[dir];

            if (nextY >= N || nextY < 0 || nextX >= M || nextX < 0) { continue; }
            // if (v[nextY][nextX] == -1) { continue; }    // 갈 수 없는 곳 (arr == 1)
            // if (v[nextY][nextX] > 0) { continue; }      // 이미 방문한 곳

            if (v[nextY][nextX] != -1) { continue; }

            q.push(make_pair(nextY, nextX));
            v[nextY][nextX] = v[curY][curX] + 1;
        }
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 0) { v[i][j] = 0; }
            else if (arr[i][j] == 1) { v[i][j] = -1; }
            else { startY = i; startX = j; v[i][j] = 0;}
        }
    }

    bfs();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}