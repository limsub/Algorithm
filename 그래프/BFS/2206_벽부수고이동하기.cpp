#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>


// 2206 벽 부수고 이동하기
// 18% 틀
// 2% 메모리 초과가 나길래 v1 때문에 그런줄 알았는데, 생각해보니까 bfs에서 메모리 초과는 q에 계속 들어갈 때 생기는데...?

// 굿노트에 반례 적어둠 (9, 9)
// 이미 방문한 곳이더라도, 한 번 부수고 방문했던 경로라면 가다가 막혀서 더이상 의미없는 길이 될 수 있어
// 따라서 현재 내가 안부순 상태라면 그 경로도 탐색해야 함
// continue 해줬다

// 메모리 초과라고 해서 무작정 배열 하나 없애려고 하지 말고, 큐에 무한대로 쌓이는 게 아닐지 생각하자. 백퍼인듯 하다


int N, M;
int arr[1001][1001];
int v1[1001][1001] = {0, };
int v2[1001][1001] = {0, };

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};



int bfs() {

    queue< pair<int, int> > q;
    // (0, 0) 초기설정
    q.push(make_pair(0, 0));
    v1[0][0] = 1;
    v2[0][0] = 1;


    while (!q.empty() ) {
        int startY = q.front().first;
        int startX = q.front().second;
        q.pop();

        // N, M에 도착했다 -> v2값 리턴
        if (startY == N-1 && startX == M-1) {
            return v2[startY][startX];
        }

        for (int dir = 0; dir < 4; dir++) {
            int nextY = startY + dy[dir];
            int nextX = startX + dx[dir];

            // 예외처리
            // 0. 
            if (nextY >= N || nextY < 0 || nextX >= M || nextX < 0) { continue;}
            // 1. arr이 1인데, 한 번 부수고 온 경우 continue
            if (arr[nextY][nextX] == 1 && v1[startY][startX] == 2) { continue; }
            // if (arr[nextY][nextX] == 1 && arr[startY][startX] == -1) { continue; }

            // 2. 애초에 그냥 방문했던 곳이면 continue
            // if (v2[nextY][nextX] != 0) { continue; }
            // if (v2[nextY][nextX] < v2[startY][startX] + 1) { continue; }
            // if (v2[nextY][nextX] != 0 && v2[nextY][nextX] < v2[startY][startX] + 1) { continue; }

            // 그런데 부수고 방문했던 곳이라면, 거기서 더이상 갈 수가 없기 때문에 내가 도전해봐도 괜찮을듯. (만약 내가 안부셨다면)
            // 즉, 이미 방문한 곳이고, 나도 부시고 왔고, 걔도 부셔서 방문한 곳이라면?

            // 부심 vs 안부심으로 해서 다르기만 하면 다시 방문할 수 있도록 하는 건?


            // if (v1[startY][startX] == 2) {
            //     if (v2[nextY][nextX] != 0 && v1[nextY][nextX] == 2) { continue; }
            // }
            // else if (v1[startY][startX] == 1) {
            //     if (v2[nextY][nextX] != 0 && v1[nextY][nextX] == 1) { continue; }
            // }


            if (v2[nextY][nextX] != 0 && v1[nextY][nextX] == 1 && v1[startY][startX] == 1) { continue; }
            if (v2[nextY][nextX] != 0 && v1[startY][startX] == 2) { continue; }


            // 방문
            if (arr[nextY][nextX] == 1) {
                // (1). 부수고 들어가려고 함 -> v1 값 증가
                v1[nextY][nextX] = 2;  // 만약 부셨으면, +1    
                // arr[nextY][nextX] = -1;
            } else {
                // (2). 그냥 방 들어가 -> v1 값 유지
                v1[nextY][nextX] = v1[startY][startX];
                // arr[nextY][nextX] = arr[startY][startX];
            }
            
            v2[nextY][nextX] = v2[startY][startX] + 1;  // 방문 카운트
            q.push(make_pair(nextY, nextX));

            // cout << nextY << " " << nextX << endl;
        }
    }


    return -1;
}

int main() {
    // 입력
    cin >> N >> M;

    for (int i = 0; i < N; i++) {

        string s;
        cin >> s;

        for (int j = 0; j < M; j++) {

            string ss = "";
            ss += s[j];

            arr[i][j] = stoi(ss);


        }
    }

    cout << bfs() << endl;



    return 0;
}