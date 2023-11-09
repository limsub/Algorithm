#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>


// 4179 불!

// 61% 틀
// 가장자리에 도착했더라도, 다음에 꺼내서 보니 먹혔으면 안되는거다
// -> return 시점 바꿔주자
// while 조건 추가. !fireQ가 empty일 때 뿐만 아니라 !JQ empty도 추가

// https://forward-gradually.tistory.com/52 여기서 반례 확인

int N, M;
char arr[1001][1001];
int v[1001][1001];

queue< pair<int, int> > fireQ;

queue< pair<int, int> > jQ;

int dy[] = {-1, 1, 0, 0 };
int dx[] = {0, 0, -1, 1 };


void bfs() {

    int cnt = 0;

    // fire 큐를 뭉텡이로 빼자
    while(!fireQ.empty() || !jQ.empty()) {
        cnt++;


        // J 역시 뭉텡이로 가자
        // 2. J 경로 탐색
        if (jQ.empty()) { 
            printf("IMPOSSIBLE\n");
            return;
        }
        
        int jSize = jQ.size();
        for (int i = 0; i < jSize; i++) {
            pair<int, int> startJ = jQ.front();
            jQ.pop();

            // 꺼냈는데 startJ가 이미 먹혔어 -> 탐색 불가
            if (arr[startJ.first][startJ.second] == 'F') { continue; };

            // (return 시점 변경) 꺼냈더니 가장자리야. 먹히지도 않았어 -> return
            if (startJ.first == N-1 || startJ.first == 0 || startJ.second == M-1 ||  startJ.second == 0) {
                cout << cnt << endl;
                return;
            }

            // 다음 길 탐색
            for (int dir = 0; dir < 4; dir++) {
                int nextY = startJ.first + dy[dir];
                int nextX = startJ.second + dx[dir];

                if (nextY >= N || nextY < 0 || nextX >= M || nextX < 0) { continue; }

                // . 인 곳만 탐색 가능
                if (arr[nextY][nextX] != '.') { continue; }

                jQ.push(make_pair(nextY, nextX));
                arr[nextY][nextX] = 'J';

                // // 만약 가장자리에 도착했다 -> return
                // if (nextY == N-1 || nextY == 0 || nextX == M-1 || nextX == 0) {
                //     cout << cnt + 1 << endl;
                //     return;
                // }
            }
        }

        // 한 번의 뭉텡이
        // 1. fire 확산
        int fireSize = fireQ.size();
        for (int i = 0; i < fireSize; i++) {
            pair<int, int> startFire = fireQ.front();
            fireQ.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nextY = startFire.first + dy[dir];
                int nextX = startFire.second + dx[dir];

                if (nextY >= N || nextY < 0 || nextX >= M || nextX < 0) { continue; }

                // 이미 F이거나 #이면 갈필요 x, 못가
                if (arr[nextY][nextX] == 'F') { continue; }
                if (arr[nextY][nextX] == '#') { continue; }

                fireQ.push(make_pair(nextY, nextX));
                arr[nextY][nextX] = 'F';
            }
        }
    }
    printf("IMPOSSIBLE\n");
}

int main() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 'F') { fireQ.push(make_pair(i, j)); }
            if (arr[i][j] == 'J') { jQ.push(make_pair(i, j)); }
        }
    }

    bfs();



    return 0;
}