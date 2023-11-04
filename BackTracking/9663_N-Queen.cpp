#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>


// 9663 N-queen

int cnt = 0;
int v1[40] = {0, }; // 세로 방향
int v2[40] = {0, }; // 우측 상단 방향의 대각선
int v3[40] = {0, }; // 좌측 상단 방향의 대각선

int N;

void backTracking(int p) {

    if (p == N) {
        cnt++;  // 끝까지 도착한 경우. 성공을 의미
    }

    for (int i = 0; i < N; i++) {
        if (v1[i] == 0 && v2[i+p] == 0 && v3[p-i + N] == 0) {   
            // 이 조건문에서 원래는 현재 두었던 모든 위치를 탐색하면서 내가 둘 곳이 가능한지를 봐야 하는데, 
            // 그렇게 하면 시간적으로 너무 비효율적이기 때문에
            // 일반적인 백트래킹 문제처럼 v 배열을 두고 미리미리 가능 여부를 설정해둔다.
            // 세로를 나타내는 배열 1개, 대각선을 나타내는 배열 2개를 미리 설정한다

            v1[i] = 1;
            v2[i+p] = 1;
            v3[p-i+N] = 1;

            backTracking(p+1);

            v1[i] = 0;
            v2[i+p] = 0;
            v3[p-i+N] = 0;

        }

    }

}

int main() {

    cin >> N;

    backTracking(0);

    cout << cnt << endl;

    return 0;
}