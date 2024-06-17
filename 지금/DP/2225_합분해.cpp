#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long

// 2225 합분해

// N까지 수가 있을 때, K개를 선택해서 합이 N이 되게 하기.

// K = 1이면, 1개만 선택할 수 있기 때문에 N 하나만 선택해서 만드는 경우밖에 없다 => 1.

// dp[i][j] : i(N)까지 수가 있을 때 j(K)개를 선택해서 합이 i가 되게 하기
// dp[1][1] = 1 (1), dp[1][2] = 2 (0 + 1, 1 + 0),       dp[1][3] = 3 (1+0+0, 0+1+0, 0+0+1)
// dp[2][1] = 1 (2), dp[2][2] = 3 (0 + 2, 2 + 0, 1 + 1) dp[2][3] = (2+0+0, 0+2+0, 0+0+2, 0+1+1, 1+0+1, 1+1+0)

int dp[201][201];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;

    for (int i=0;i<=k;i++)
        dp[1][i] = i;
    
    for (int i=2;i<=n;i++)
        for (int j=1;j<=k;j++)
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000000;
        
    cout << dp[n][k] << endl;

    return 0;
    

    return 0;
}

