#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

// 2072 오목

// 오목이 된 순간 단계 출력
// 육목은 인정x



bool check_o(int arr[20][20], int x, int y) {

    // 가로
    // 범위 조절
    int start_x, end_x;
    if (x - 4 < 1) {
        start_x = 1;
    }
    else {
        start_x = x - 4;
    }

    if (x + 4 > 19) {
        end_x = 19;
    }
    else {
        end_x = x + 4;
    }

    for (int i = start_x; i <= end_x - 4; i++) {
        if (arr[y][i] == 1
            && arr[y][i] == arr[y][i+1]
            && arr[y][i+1] == arr[y][i+2]
            && arr[y][i+2] == arr[y][i+3]
            && arr[y][i+3] == arr[y][i+4]) {
                //return true;
                //printf("현재 i는 %d 입니다\n", i);
                //printf("현재 end_x - 4는 %d 이고, arr[y][i+5]는 %d 입니다\n", end_x - 4, arr[y][i+5]);
                if ( i < 15 && arr[y][i+5] != 1) {
                    return true;    
                }
                
            }
    }



    // 세로
    int start_y, end_y;
    if (y - 4 < 1) {
        start_y = 1;
    }
    else {
        start_y = y - 4;
    }
    if (y + 4 > 19) {
        end_y = 19;
    }
    else {
        end_y = y + 4;
    }

    for (int i = start_y; i <= end_y - 4; i++) {
        if (arr[i][x] == 1
            && arr[i][x] == arr[i+1][x]
            && arr[i+1][x] == arr[i+2][x]
            && arr[i+2][x] == arr[i+3][x]
            && arr[i+3][x] == arr[i+4][x]) {
                

                if (i < 15 && arr[i+5][x] != 1) {
                    return true;
                }
                
                
            }
    }

    // 대각선 우하향
    int a = (x>y) ? y : x;  // 둘 중에 작은 값
    int b = (x>y) ? x : y;  // 둘 중에 큰 값
    int start_d;
    int end_d;

    if (a <= 4) {   // 작은 게 4 이하일 때
        start_d = a - 1;
    }
    else {
        start_d = 4;
    }
    if (b >= 16) { // 큰 게 16 이상일 때
        end_d = 19 - b;
    }
    else {
        end_d = 4;
    }

    int s_x1, s_y1, e_x1, e_y1;
    s_x1 = x - start_d;
    s_y1 = y - start_d;
    e_x1 = x + end_d;
    e_y1 = y + end_d;
    for (int i = s_x1, j = s_y1; i <= e_x1-4, j <= e_y1-4; i++, j++) {
        if (arr[j][i] == 1
            && arr[j][i] == arr[j+1][i+1]
            && arr[j][i] == arr[j+2][i+2]
            && arr[j][i] == arr[j+3][i+3]
            && arr[j][i] == arr[j+4][i+4]) {

                if (i < 15 && j < 15 &&arr[j+4][i+4] != 1) {
                    return true;
                }

                
            }
    }
    
    // 대각선 우상향
    int s_x2, s_y2, e_x2, e_y2;
    if (x <= 4) {
        e_x2 = 1;
    }
    else {
        e_x2 = x;
    }
    if (y <= 4) {
        s_y2 = 1;
    }
    else {
        s_y2 = y;
    }

    if (x >= 16) {
        s_x2 = 19;
    }
    else {
        s_x2 = x + 4;
    }
    if (y >= 16) {
        e_y2 = 19;
    }
    else {
        e_y2 = y + 4;
    }
    for (int i = s_x2, j = s_y2; i >= e_x2+4, j <= e_y2-4; i--, j++) {
        if (arr[j][i] == 1
            && arr[j][i] == arr[j+1][i-1]
            && arr[j][i] == arr[j+2][i-2]
            && arr[j][i] == arr[j+3][i-3]
            && arr[j][i] == arr[j+4][i-4])
            {
                if (i > 5 && j < 15 && arr[j+5][i-5] != 1) {
                    return true;
                }
                
            }
    }

    return false;
}

int main() {

    int ans_num = -1;
    
    int N;
    scanf("%d", &N);

    int arr[20][20] = {0, };
    int arr2[20][20] = {0, };


    for (int i = 1; i < N+1; i++) {
        
        if (i % 2 == 0) {   // 짝수인 경우
            int x1, y1;
            scanf("%d %d", &x1, &y1);
            arr2[x1][y1] = 1;
            if (check_o(arr2, y1, x1)) {
                ans_num = i;
            }
            //cout << "i : " << i << "  " << check_o(arr2, y1, x1) << endl;
        }
        else {              // 홀수인 경우
            int x2, y2;
            scanf("%d %d", &x2, &y2);
            arr[x2][y2] = 1;
            if (check_o(arr, y2, x2) ) {
                ans_num = i;
            }
            //cout << "i : " << i << " " <<  check_o(arr2, y2, x2) << endl;
        }
        
        

    }

    printf("%d\n", ans_num);

    return 0;
}