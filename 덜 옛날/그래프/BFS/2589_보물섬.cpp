#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;
#include <queue>


// 2589
// 보물섬

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

char arr[50][50];
int v[50][50];

int N, M;

int bfs(int y, int x) {

    int maxDist = -1;

    queue< pair<int, int> > q;

    q.push(make_pair(y, x));

    v[y][x] = 0;    // 초기 거리 카운트 0

    while (!q.empty()) {

        // 꺼내고
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        // 탐색 가능한 곳 찾기
        for (int dir = 0; dir < 4; dir++) {
            int nextY = curY + dy[dir];
            int nextX = curX + dx[dir];

            // 걸러주기
            if (nextY >= N || nextY < 0 || nextX >= M || nextX < 0) { continue; }
            if (arr[nextY][nextX] == 'W') { continue; }
            if (v[nextY][nextX] != -1) { continue; }

            // 탐색 
            q.push(make_pair(nextY, nextX));
            v[nextY][nextX] = v[curY][curX] + 1;

            // 최댓값 비교
            if (v[nextY][nextX] > maxDist) { maxDist = v[nextY][nextX]; }
        }
    }

    return maxDist;
}

void initV() {
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            v[i][j] = -1;
        }
    }
}

int main() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    // 1. 모든 위치에 대해 bfs
    // 2. bfs() 리턴값으로 최대 거리
    // 3. 가장 큰 값 출력


    // 1. 
    int ans = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 'L') {

                initV();    // v 배열 -1로 모두 초기화

                // 2. 
                int maxDist = bfs(i, j);

                if (maxDist > ans) { ans = maxDist; }

                
            }
        }
    }

    cout << ans;

    return 0;
}
