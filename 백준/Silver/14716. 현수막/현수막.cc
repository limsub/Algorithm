#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long

// 14716 현수막

int M, N;
int arr[255][255];
int v[255][255];
int dy[] = {0, 0, -1, 1, 1, 1, -1, -1};
int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};


void bfs(int sY, int sX) {
    queue< pair<int, int> > q;
    q.push({sY, sX});
    v[sY][sX] = 1;

    while (!q.empty()) {
        int cY = q.front().first;
        int cX = q.front().second;
        q.pop();

        for (int dir = 0; dir < 8; dir++) {
            int nY = cY + dy[dir];
            int nX = cX + dx[dir];

            if (nY >= M || nY < 0 || nX >= N || nX < 0) continue;
            if (v[nY][nX]) continue;
            if (!arr[nY][nX]) continue;

            q.push({nY, nX});
            v[nY][nX] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 입력
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    // 2. BFS
    int cnt = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!v[i][j] && arr[i][j]) {
                bfs(i, j);
                cnt++;
            }
        }
    }    

    cout << cnt;
    


    return 0;
}

