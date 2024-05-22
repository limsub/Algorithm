#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>

// 6603 로또

int arr[15] = {0, };    
int ansArr[15] = {0, }; // 앞에서부터 차곡차곡 저장
int v[50] = {0, };      // 해당 숫자가 인덱스가 된다. 1 or 0

void backTracking(int depth, int k) {
    // 끝까지 도달했을 때, 현재 arr 모두 출력
    if (depth == 6) {
        for (int i = 0; i < 6; i++) {
            printf("%d ", ansArr[i]);
        }
        printf("\n");
    }

    // v가 0인 곳 (아직 방문하지 않은 곳) 으로 백트래킹
    for (int i = 0; i < k; i++) {
        int testPos = arr[i];

        if (v[testPos] != 0) { continue; }
        if (depth > 0 && testPos < ansArr[depth-1] ) { continue; }  // 오름차순으로 넣어주기

        v[testPos] = 1;
        ansArr[depth] = testPos;
        backTracking(depth+1, k);
        v[testPos] = 0;

    }
    
}


int main() {

    bool isFirst = true;    // 테스트 케이스 사이에 빈 문자열을 출력해주기 위함 (첫 테스트에는 출력하면 안되기 때문에 분기 처리)

    while(true) {
        int k;
        cin >> k;

        // k가 0이면 프로그램 종료
        if (k == 0) {
            return 0;
        }

        if (!isFirst) {
            printf("\n");
        }

        // 아니면, k개만큼 받아서 그대로 arr 배열에 저장
        for (int i = 0; i < k; i++) {
            cin >> arr[i];
        }

        // 현재 arr에 대해 dfs 백트래킹 시작
        backTracking(0, k);


        // 다음 테스트 케이스를 위해 arr 배열과 v 배열 초기화
        for (int i = 0; i < 15; i++) {
            arr[i] = 0;
        }
        for (int i = 0; i < 50; i++) {
            v[i] = 0;
        }

        isFirst = false;

    }


    return 0;
}