#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>

// 15654 N과 M(6)
// 조합으로 나오는 케이스
// 맨 먼저 배열 소팅해주기
// 출력할 때도 오름차순 출력

int N, M;

int arr[10];
int v[10];
int ansArr[10];

void backTracking(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << ansArr[i] << " ";
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++) {
        if (v[i] != 0) { continue; }

        // 다음에 넣을 애가 오름차순이 맞는지 여기서 확인
        if (depth > 0 && arr[i] <ansArr[depth-1]) { continue; }

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