// 9663

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int N; // (1 <= N < 15)

int p[20][20];

int cnt;


/*
void DFS(int depth) {

    // 깊이가 M이면, r(result)에 M개의 값이 저장되었으므로 출력할 준비가 됨.
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            printf("%d ", r[i]);
        }
        printf("\n");
    }

    else {
        for (int i = 1; i < N+1; i++) {

            if (c[i] == 0) {
                r[depth] = i;
                if (i > 1) {
                    for (int j = 1; j < i; j++) {
                        c[j] = 1;
                    }
                }

                DFS(depth + 1);

                if (i > 1) {
                    for (int j = 1; j < i; j++) {
                        c[j] = 0;
                    }
                }
            }
        }
    }
}

*/

int dfs(int x, int y, int depth) {


    // depth가 N개일 때는 cnt를 하나 추가해준다. 퀸 N개를 모두 놓았다는 뜻.
    if (depth == N) {
        printf("마지막 좌표 : (%d, %d)\n", x, y);
        cnt ++;
                for (int i = 0; i < N; i++) {
            p[x][i] ++; // 세로
            p[i][y] ++; // 가로
            
            
            if ( x - i >= 0 && y - i >= 0){
                p[x-i][y-i] ++;
            }
                
            if ( x + i < N && y + i < N) {
                p[x+i][y+i] ++;
            }

            if (x - i >= 0 && y + i < N) {
                p[x-i][y+i] ++;
            }

            if (x + i < N && y-i >= 0) {
                p[x+i][y-i] ++;
            }

            //printf("좌표 : (%d, %d), 현재 배열값 : (%d) \n", x, y, p[x][y]);
        }
        // 문제는 가로, 세로, 대각 하면서 p[x][y]값을 3번 + 시켜주고 있으니까 2번 빼주는걸로 하자.
        p[x][y] = p[x][y] - 2;
        //printf("%d %d\n", x, y);
    }

    else {
        // 가로, 세로, 대각선은 불가능  --> 불가능하다는 걸 양수인 걸로 표현하자. +1씩 계속 해주기.
        for (int i = 0; i < N; i++) {
            p[x][i] ++; // 세로
            p[i][y] ++; // 가로
            
            
            if ( x - i >= 0 && y - i >= 0){
                p[x-i][y-i] ++;
            }
                
            if ( x + i < N && y + i < N) {
                p[x+i][y+i] ++;
            }

            if (x - i >= 0 && y + i < N) {
                p[x-i][y+i] ++;
            }

            if (x + i < N && y-i >= 0) {
                p[x+i][y-i] ++;
            }

            //printf("좌표 : (%d, %d), 현재 배열값 : (%d) \n", x, y, p[x][y]);
        }
        // 문제는 가로, 세로, 대각 하면서 p[x][y]값을 3번 + 시켜주고 있으니까 2번 빼주는걸로 하자.
        p[x][y] = p[x][y] - 2;


        //printf("현재 : (%d, %d) 완료 -> (3, 3) 배열값 출력 : %d\n", x, y, p[3][3]);

        // 가능한 칸을 찾아서 다시 dfs 돌린다.
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (p[i][j] == 0) { // 0이라는건 한번도 +를 안했으니까 둘 수 있다는 뜻
                    
                    printf("실시 좌표 : (%d, %d)\n", i, j);

                    
                    
                    dfs(i, j, depth + 1);

                    printf("탈출. 좌표 : (%d, %d)\n", i, j);
                    
                    // dfs를 하고 나왔으면 이제 걘 취소해줘야 하니까 가로세로대각을 1씩 빼준다.
                    for (int k = 0; k < N; k++) {
                        p[i][k] --;
                        p[k][j] --;
                    

                        if (i - k >= 0 && j - k >= 0)  // 왼쪽 위
                            p[i-k][j-k]--;
                        if (i + k < N && j+ k < N) // 오른쪽 아래
                            p[i+k][j+k]++;
                        if (i - k >= 0 && j + k < N)
                            p[i-k][j+k]++;
                        if (i+k < N && j-k >= 0)
                            p[i+k][j-k]++;
                        
                    }
                    p[i][j] = p[i][j] + 2;

                    

                }
            }
        }

    }

    return cnt;
}

int main() {

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            p[i][j] = 0;
        }
    }
    cnt = 0;


    // 맨 윗줄에 대해서만 진행해보자 -> 거의 비슷할 것 같다는 생각

    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N; j++) {
            for (int t = i; t < N; t++) {
                for (int q = 0; q < N; q++) {
                    p[t][q] = 0;
                }
            }  
            printf("dfs 시작합니다. 시작 좌표 : (%d, %d)\n", i, j);
            dfs(i, j, 1);
        }

        for (int t = 0; t < N; t++) {
            p[i][t] = 10000;
        }
    }
    
    printf("%d", cnt);

    
    return 0;
}
