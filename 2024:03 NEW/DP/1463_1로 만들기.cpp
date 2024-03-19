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


// 1463

// 1. 로직 구상
// dp[n] = min{ dp[n/3], dp[n/2], dp[n-1] } + 1


// 2. 정답 확인
// 1과 동일

int dp[1000002];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    cin >> n;
    dp[1] = 0;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + 1;    // 모든 값에 대해 기본

        if (i % 2 == 0) { dp[i] = min(dp[i/2] + 1, dp[i]); }
        if (i % 3 == 0) { dp[i] = min(dp[i/3] + 1, dp[i]); }
    }

    cout << dp[n]; 

    return 0;
}