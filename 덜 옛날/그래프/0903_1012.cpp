#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>

// 1012 유기농 배추

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int bachu[51][51] = {0};


void printBachu() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", bachu[i][j]);
        }
        printf("\n");
    }
}


void initBachu(int M, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            bachu[i][j] = 0;
        }
    }
}



void dfsBachu2(int x, int y, int M, int N) {

    bachu[y][x] = -1;

    for (int p = 0; p < 4; p++) {
        int nextX = x + dx[p];
        int nextY = y + dy[p];

        // 돌 수 있으면 들어가
        if ( bachu[nextY][nextX] == 1 
            && nextX >= 0 && nextX < M 
            && nextY >= 0 && nextY < N) {
                dfsBachu2(nextX, nextY, M, N);
            }
    }
    
}


int main() {

    int T;
    cin >> T;

    vector<int> ansCount;

    // 테스트 케이스
    for (int t = 0; t < T; t++) {

        int M, N, K;
        cin >> M >> N >> K;

        // 배추 위치 개수
        for (int i = 0; i < K; i++) {

            int x, y;
            cin >> x >> y;

            bachu[y][x] = 1;
        }   // 배추 배열 저장 완료

        
        // 배열값이 1이면 dfs 들어가고 count + 1.
        // dfs 돌면서 방문한 곳은 배열값 -1로 변경
        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {

                if (bachu[i][j] == 1) {
                    count ++;
                    dfsBachu2(j, i, M, N);
                }
            }
        }

        // 정답 벡터에 추가
        ansCount.push_back(count);

        // 초기화
        initBachu(M, N);
    }

    
    for (int t = 0; t < ansCount.size(); t++) {
        printf("%d\n", ansCount[t]);
    }


    return 0;
}