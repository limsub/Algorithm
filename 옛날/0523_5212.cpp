#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;


int main()
{
    int R, C;
    scanf("%d %d", &R, &C);

    char arr[R+2][C+2];
    for (int i = 0; i < R+2; i++ ){
        arr[i][0] = '.';
        arr[i][C+1] = '.';
    }
    for (int j = 0; j < C+2; j++) {
        arr[0][j] = '.';
        arr[R+1][j] = '.';
    }

    char y;
    scanf("%c", &y);

    // 바다 + 섬 입력
    for (int i = 0; i< R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%c", &arr[i+1][j+1]);
        }
        char x;
        scanf("%c", &x);
    }

    // 똑같은거 하나 만들어
    char arr2[R+2][C+2];
    for (int i = 0; i < R+2; i++) {
        for (int j = 0; j < C+2; j++) {
            arr2[i][j] = arr[i][j];
        }
    }

    

    // 3면 or 4면이 바다인 섬 -> 바다
    for (int i = 1; i < R+1; i++) {
        for (int j = 1; j < C+1; j++ ){
            if (   (arr[i][j-1] == '.' &&
                        arr[i][j+1] == '.' &&
                        arr[i+1][j] == '.') ||
                        (arr[i][j-1] == '.' &&
                        arr[i][j+1] == '.' &&
                        arr[i-1][j] == '.') ||
                        (arr[i-1][j] == '.' &&
                        arr[i+1][j] == '.' &&
                        arr[i][j+1] == '.') ||
                        (arr[i-1][j] == '.' &&
                        arr[i+1][j] == '.' &&
                        arr[i][j-1] == '.')
                        ) {
                            arr2[i][j] = '.';
                        }
        }
    }


    


    // 모두 바다인 줄은 지워서 출력하기 위해
    int start_x = 0;
    int end_x = R+1;
    int start_y = 0;
    int end_y = C+1;

    for (int i = 0; i < R+2; i++) {

        int flag = 0;

        for (int j = 0; j < C+2; j++) {
            if (arr2[i][j] == 'X') {
                flag = 1;
            }
        }
        if (flag == 0) {
            start_x++;
        }
        if (flag == 1 ) {
            break;
        }
    }

    for (int i = R+1; i >= 0; i--) {
        int flag = 0;
        for (int j = 0; j < C+2; j++) {
            if (arr2[i][j] == 'X') {
                flag = 1;
            }
        }
        if (flag == 0) {
            end_x--;
        }
        if (flag == 1) {
            break;
        }
    }

    for (int j = 0; j < C+2; j++) {
        int flag = 0;
        for (int i = 0; i < R+2; i++) {
            if (arr2[i][j] == 'X') {
                flag = 1;
            }
        }
        if (flag == 0) {
            start_y++;
        }
        if (flag == 1) {
            break;
        }
    }

    for (int j = C+1; j >= 0; j--) {
        int flag = 0;
        for (int i = 0; i < R+2; i++) {
            if (arr2[i][j] == 'X') {
                flag = 1;
            }
        }
        if (flag == 0) {
            end_y--;
        }
        if (flag == 1) {
            break;
        }
    }

    //printf("%d %d %d %d\n", start_x, end_x, start_y, end_y);

    for (int i = start_x; i <= end_x; i++) {
        for (int j = start_y; j <= end_y; j++) {
            printf("%c", arr2[i][j]);
        }
        printf("\n");
    }

/*
    // 섬만 탐색해서 세 면 또는 네 면이 바다인 건 배열에 -1로 표시
    int forRemove[R][C];
    for (int i = 0; i < R; i++) {
        for (int j =0; j < C; j++) {
            forRemove[i][j] = 0;

            if (arr[i][j] == 'X') {
                // 위 아래 왼 오 공간이 없는 건 따로 
                // 맨 위에 붙어있는 경우
                if (i == 0 && j > 0 && j < C-1) {
                    if (arr[i][j-1] == '.' &&
                        arr[i][j+1] == '.' &&
                        arr[i+1][j] == '.') {
                            forRemove[i][j] = -1;
                        }
                }
                // 맨 아래에 붙어있는 경우
                else if (i == R-1 && j > 0 && j < C-1) {
                    if (arr[i][j-1] == '.' &&
                        arr[i][j+1] == '.' &&
                        arr[i-1][j] == '.') {
                            forRemove[i][j] = -1;
                        }
                }
                // 맨 왼쪽에 붙어있는 경우
                else if (j == 0 && i > 0 && i < R-1) {
                    if (arr[i-1][j] == '.' &&
                        arr[i+1][j] == '.' &&
                        arr[i][j+1] == '.') {
                            forRemove[i][j] = -1;
                        }
                }
                else if (j == C-1 && i > 0 && i < R-1) {
                    if (arr[i-1][j] == '.' &&
                        arr[i+1][j] == '.' &&
                        arr[i][j-1] == '.') {
                            forRemove[i][j] = -1;
                        }
                }


                // 공간이 넉넉한 건 4개 한꺼번에
                else {
                    if (   (arr[i][j-1] == '.' &&
                        arr[i][j+1] == '.' &&
                        arr[i+1][j] == '.') ||
                        (arr[i][j-1] == '.' &&
                        arr[i][j+1] == '.' &&
                        arr[i-1][j] == '.') ||
                        (arr[i-1][j] == '.' &&
                        arr[i+1][j] == '.' &&
                        arr[i][j+1] == '.') ||
                        (arr[i-1][j] == '.' &&
                        arr[i+1][j] == '.' &&
                        arr[i][j-1] == '.')

                        ) {
                            forRemove[i][j] = -1;
                        }

                }

            }


        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%d ", forRemove[i][j]);
        }
        printf("\n");
    }
    */
}