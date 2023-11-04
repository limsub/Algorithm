#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>


// 15649 N과 M 백트래킹

int N, M;
int arr[10];    // 출력할 배열
int isused[10]; // 방문했는지 확인할 배열

void backTracking(int p) {

    if (p == M) {
        // 현재 arr 배열 원소들 모두 출력
        for (int i = 0; i < M; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 1; i < N+1; i++) {
        if (isused[i] == 0) {

            arr[p] = i;
            isused[i] = 1;
            backTracking(p+1);


            isused[i] = 0;  // 나왔으면 다시 0으로 설정
        }
    }


}

int main() {

    cin >>  N >> M;

    backTracking(0);

    return 0;
}