#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>

// 15656 N과 M(7) 
// 같은 수 중복 가능 -> v가 필요하지 않을수도?

int N, M;

int arr[10];
int ansArr[10];
int v[10] = {0, };

void backTracking(int depth) {

    // printf("===%d\n", depth);
    
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << ansArr[i] << " ";
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < N; i++) {

        ansArr[depth] = arr[i];
        backTracking(depth + 1);
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