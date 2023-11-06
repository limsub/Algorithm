#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>

// 1759 암호 만들기

int N, C;

char arr[20];
char ansArr[20];
int v[20] = {0, };

// 모음 최소 1개, 자음 최소 2개 있는지 확인
bool checkAnsArr() {
    int moCnt = 0;
    for (int i = 0; i < N; i++) {
        if (ansArr[i] == 'a' 
            || ansArr[i] == 'e'
            || ansArr[i] == 'i'
            || ansArr[i] == 'o'
            || ansArr[i] == 'u' ) {
                moCnt++;
            }
    }

    if (moCnt < 1) { return false; }
    if (N - moCnt < 2 ) { return false; }

    return true;
}


void backTracking(int depth) {

    if (depth == N) {
        // 모음 1개, 자음 2개 있을 때만 출력해주기
        if (!checkAnsArr()) { return; }

        for (int i = 0; i < N; i++) {
            printf("%c", ansArr[i]);
        }
        printf("\n");

        return;
    }

    for (int i = 0; i < C; i++) {

        // 이미 방문했는지 체크
        if (v[i] == 1) { continue; }

        // 사전순서가 맞는지 체크 
        // 가장 마지막에 들어있는 문자 : ansArr[depth-1]
        // 넣을 예정인 문자 : arr[i];
        if ( arr[i] < ansArr[depth-1] ) { continue; }

        // 방문 시작
        v[i] = 1;
        ansArr[depth] = arr[i];
        backTracking(depth+1);
        v[i] = 0;

    }
}

int main() {

    
    cin >> N >> C;

    for (int i = 0; i < C; i++) {
        cin >> arr[i];
    }
    
    // arr에 대한 sort
    sort(arr, arr + C);

    backTracking(0);

    return 0;
}