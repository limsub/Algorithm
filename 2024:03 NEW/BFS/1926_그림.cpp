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


// 1926 그림
// - 여러 개의 그래프. 
// - 좌표 bfs.

// 1. 2차원 배열 돌면서 v 탐색 안된거에 대해 bfs 실행. - count 증가
// 2. bfs 결과값 저장 -> max
// 3. 다 돌고 결과 출력


int N, M;
int arr[510][510];
int v[510][510];

int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

int bfs(int y, int x) {
    queue< pair<int, int> > q;
    q.push(make_pair(y, x));
    v[y][x] = 1;

    int size = 1;
    
    while(!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nY = curY + dy[dir];
            int nX = curX + dx[dir];

            if (nY >= N || nY < 0 || nX >= M || nX < 0) continue;
            if (v[nY][nX]) continue;
            if (arr[nY][nX] == 0) continue;

            q.push(make_pair(nY, nX));
            v[nY][nX] = 1;
            size++;
        }
    }

    return size;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    // 1. 입력
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }


    // 2. bfs
    int cnt = 0;
    int max_size = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (v[i][j] == 0 && arr[i][j] == 1) { 

                int size = bfs(i, j);
                
                max_size = max(max_size, size);
                cnt ++;
            }
        }
    }

    cout << cnt << "\n" << max_size << "\n";

    
    return 0;
}