#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>

#include <set>


int N, M;
int arr[301][301];
int v[301][301] = {0, };

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void printArr() {
    printf("====print====\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << arr[i][j] << " ";
        }
        printf("\n");
    }
}

int bfs() {

    queue< pair<int, int> > q;
    
    // 현재 빙산의 개수를 미리 센다. bfs돌면서 하나씩 까고, cnt가 0이 되지 않으면 덩어리가 여러 개 있다고 판단한다
    // 시작할 지점 하나만 큐에 넣는다
    int binCnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] != 0) { 
                if (q.empty()) {
                    q.push(make_pair(i, j));
                    v[i][j] = 1;
                }
                binCnt++;
            }
        }
    }

    // printf("bfs 전 빙산 카운트 : %d\n", binCnt);

    // 빙산이 없으면 그냥 모두 녹았다는 뜻
    if (binCnt == 0) {  return -1; }

    // bfs 시작
    while (!q.empty() ) {

        pair<int, int> start = q.front();
        q.pop();
        binCnt--;

        for (int dir = 0; dir < 4; dir ++) {
            int nextY = start.first + dy[dir];
            int nextX = start.second + dx[dir];

            if (nextY >= N || nextY < 0 || nextX >= M || nextX < 0) { continue; }
            if (arr[nextY][nextX] == 0) { continue; }
            if (v[nextY][nextX] == 1) { continue; }

            q.push(make_pair(nextY, nextX));
            v[nextY][nextX] = 1;
        }    
    }

    // printf("bfs 후 빙산 카운트 : %d\n", binCnt);

    // cnt 여부에 따라 빙산이 한 덩어리인지 여러 덩어리인지 판단
    return (binCnt == 0) ? 0 : 1;
}

// 현재 arr 기준으로 주변에 0이 몇개 있는지 체크
int checkNearZero(int y, int x) {
    int cnt = 0;

    for (int dir = 0; dir < 4; dir++) {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (nextY >= N || nextY < 0 || nextX >= M || nextX < 0) { continue; }

        if (arr[nextY][nextX] == 0) { cnt++; }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }


    int ansCnt = 0;
    while (true) {
        int state = bfs();
        if (state == -1) {
            // printf("hi\n");
            cout << 0 << endl;
            return 0;
        }
        else if (state == 1) {
            // printf("hiaaaa\n");
            cout << ansCnt << endl;
            return 0;
        }
        else if (state == 0) {
            // printf("hi213231\n");

            int tmpArr[N][M];

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    tmpArr[i][j] = arr[i][j] - checkNearZero(i, j);
                    if (tmpArr[i][j] < 0) { tmpArr[i][j] = 0; }
                }
            }

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    arr[i][j] = tmpArr[i][j];
                }
            }

            // printArr();

            // v 초기화
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M ;j++) {
                    v[i][j] = 0;
                }
            }
        }


        ansCnt++;
    }

    
    
    return 0;
}