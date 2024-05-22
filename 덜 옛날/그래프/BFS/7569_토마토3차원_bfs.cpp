#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>

// 7569

// 토마토
int arr[101][101][101];
int v[101][101][101];

// int dy[] = {-1, 1, 0, 0 };
// int dx[] = {0, 0, -1, 1 };
// int dz[] = {1, -1};

int d[6][3] = {{-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}};
 
int m, n, h;

queue< pair< int, pair<int, int> > > q;


void printArr() {
    printf("printf arr 시작\n");
    for (int p = 0; p < h; p++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout <<  arr[p][i][j] << " ";
            }
            cout << endl;
        }
    }

    printf("printf v 시작\n");
    for (int p = 0; p < h; p++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout <<  v[p][i][j] << " ";
            }
            cout << endl;
        }
    }
}

bool checkZero() {
    // printf("check 시작\n");
    for (int p = 0; p < h; p++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[p][i][j] == 0) {
                    // printf("false\n");
                    return false;
                }
            }
        }
    }
    // printf("true\n");
    return true;
}

int bfs() {

    // int max = 0;

    int cnt = -1;

    while (! q.empty() ) {
        cnt++;
        int size = q.size();

        // cnt++;  // 여기에 이게 있어야 하는 이유???!?!?!?

        // 다른 방식으로 해보자
        // 현재 큐에 넣어두었던 애들은 다 빼 -> cnt += 1 
        // 한 뭉텅이 (사이클)이 끝나면 cnt + 1 해주는 느낌으로

        for (int i = 0; i < size; i++) {

            pair< int, pair<int, int> > data = q.front();
            q.pop();

            // 한번에 6번
            for (int dir = 0; dir < 6; dir++) {
                int nextZ = data.first + d[dir][0];
                int nextY = data.second.first + d[dir][1];
                int nextX = data.second.second + d[dir][2];

                if (nextY >= n || nextY < 0 || nextX >= m || nextX < 0 || nextZ >= h || nextZ < 0) {continue;}
                if (v[nextZ][nextY][nextX] != 0) { continue; }
                if (arr[nextZ][nextY][nextX] != 0) { continue; }

                q.push(make_pair(nextZ, make_pair(nextY, nextX)));
                int newV = v[data.first][data.second.first][data.second.second] + 1;
                v[nextZ][nextY][nextX] = newV;
                arr[nextZ][nextY][nextX] = 1;
            }
            
            // 좌우 4번 먼저, 그 다음 상하 2번
            // for (int dir = 0; dir < 4; dir++) {
            //     int nextZ = data.first;
            //     int nextY = data.second.first + dy[dir];
            //     int nextX = data.second.second + dx[dir];

            //     if (nextY >= n || nextY < 0 || nextX >= m || nextX < 0 || nextZ >= h || nextZ < 0) {continue;}
            //     if (v[nextZ][nextY][nextX] != 0) { continue; }
            //     if (arr[nextZ][nextY][nextX] != 0) { continue; }

            //     q.push(make_pair(nextZ, make_pair(nextY, nextX)));
            //     int newV = v[data.first][data.second.first][data.second.second] + 1;
            //     v[nextZ][nextY][nextX] = newV;
            //     arr[nextZ][nextY][nextX] = 1;

            //     // if (newV > max) {
            //     //     max = newV;
            //     // }
            // }

            // for (int dir = 0; dir < 2; dir++) {
            //     int nextZ = data.first + dz[dir];
            //     int nextY = data.second.first;
            //     int nextX = data.second.second;

            //     if (nextY >= m || nextY < 0 || nextX >= n || nextX < 0 || nextZ >= h || nextZ < 0) {continue;}
            //     if (v[nextZ][nextY][nextX] != 0) { continue; }
            //     if (arr[nextZ][nextY][nextX] != 0) { continue; }

            //     q.push(make_pair(nextZ, make_pair(nextY, nextX)));
            //     int newV = v[data.first][data.second.first][data.second.second] + 1;
            //     v[nextZ][nextY][nextX] = newV;
            //     arr[nextZ][nextY][nextX] = 1;

            //     // if (newV > max) {
            //     //     max = newV;
            //     // }
            // }

        }

    }

    // 0인 토마토가 있는지 체크 -> 있으면 return 0
    if (!checkZero()) { return -1; }

    return cnt ;
}

int main() {

    
    cin >> m >> n >> h;

    for (int p = 0; p < h; p++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[p][i][j];
                // 익은 토마토는 미리 큐에 모두 추가
                if (arr[p][i][j] == 1) {
                    q.push(make_pair(p, make_pair(i, j)));
                }

            }
        }
    }

    

    cout << bfs() << endl;

    // printArr();


    return 0;
}

