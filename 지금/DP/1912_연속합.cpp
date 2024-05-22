#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;
#include <queue>
#include <cstdio>
#include <set>


// 1912

// 1. 로직 구상
// 처음부터 돌면서 cur, max 저장
// cur : 현재위치까지 합 중 최댓값. 이 때, - 나오면 0으로 초기화
// max : 여태까지 최댓값
// arr[] = 10 -4 3 1 5 6 -35 12 21 -1
// cur   = 10  0 3 4 9 15  0 12 33  0
// max   = 10 10 10 ...15 ....  33 33


// 2. 정답 확인
// d[i] : i번째 항으로 끝나는 합 중 최댓값
// 사실상 로직은 똑같음. max값만 가져가는 상황


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int n;
    int arr[100010];
    int dp[100010];

    cin >> n;
    for (int i = 1; i <= n; i++) { cin >> arr[i]; }

    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i-1], 0) + arr[i];
    }

    cout << *max_element(dp + 1, dp + n + 1);

    return 0;
}