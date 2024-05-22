#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>


// 1926 그림. BFS 2차원 배열

int N, M;

int arr[501][501];
int v[501][501];

int dy[] = {-1, 1, 0, 0 };
int dx[] = {0, 0, -1, 1 };

int cnt = 0;
int maxWidth = 0;

int bfs(int y, int x) {
    int width = 0;

    queue< pair<int, int> > q;

    q.push(make_pair(y, x));
    v[y][x] = 1;

    while (!q.empty()) {

        pair<int, int> next = q.front();
        q.pop();
        width++;


        for (int dir = 0; dir < 4; dir++) {
            int nextY = next.first + dy[dir];
            int nextX = next.second + dx[dir];

            if (nextY >= N || nextY < 0 || nextX >= M || nextX < 0) { continue; }
            if (arr[nextY][nextX] != 1 ) { continue; }
            if (v[nextY][nextX] != 0 ) { continue; }

            q.push(make_pair(nextY, nextX));
            v[nextY][nextX] = 1;

            // cout << nextY <<  "h" << nextX << endl;
        }
    }
    return width;
}

int main() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    // cout << bfs(0, 0) << endl;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            if (arr[i][j] == 1 && v[i][j] ==0 ) {
                int width = bfs(i, j);

                if (width > maxWidth) { maxWidth = width; }
                cnt++;
            }

        }
    }

    cout << cnt << endl;
    cout << maxWidth << endl;


    return 0;
}