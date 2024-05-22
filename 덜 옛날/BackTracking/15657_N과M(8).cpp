#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>

// 15657 N과 M(8)

int N, M;
int arr[10];
int ansArr[10];
int v[10] = {0, };

void backTracking(int depth) {

    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << ansArr[i] << " ";
        }
        printf("\n");
        return;
    }

    // 중복 가능(v 필요x), 대신 더 작은 것만 불가능
    for (int i = 0; i < N; i++) {
        int next = arr[i];

        if (depth > 0 && ansArr[depth-1] > next ) { continue; }

        
        ansArr[depth] = next;
        backTracking(depth+1);
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