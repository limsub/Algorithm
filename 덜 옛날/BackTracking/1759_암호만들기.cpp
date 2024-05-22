#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>

// 15654 N과 M(5)
// 조합으로 나오는 케이스
// 맨 먼저 배열 소팅해주기

int N, M;

int arr[10];
int ansArr[10];
int v[10] = {0, };

void backTracking(int depth) {

    if (depth == M) {
        // ansArr 모두 출력
        for (int i = 0; i < M; i++) {
            cout << ansArr[i] << " ";
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++) {
        
        if (v[i] != 0) { continue; }

        v[i] = 1;
        ansArr[depth] = arr[i];
        backTracking(depth+1);
        v[i] = 0;
    }

}

int main() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    backTracking(0);

    return 0;
}
