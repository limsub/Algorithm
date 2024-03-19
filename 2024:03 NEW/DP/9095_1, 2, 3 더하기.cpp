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


// 9095

// 1. 로직 구상
// dp[n] = dp[n-1] + dp[n-2] + dp[n-3]

// 2. 정답 확인
// 1과 동일

int dp[12];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int T;
    cin >> T;

    while (T--) {

        cin >> n;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;

        for (int i = 4; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        cout << dp[n] << "\n";; 
    }

    

    return 0;
}