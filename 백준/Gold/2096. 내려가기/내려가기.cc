#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long


// 2096 내려가기
// 바로 아래로 내려가거나 대각선으로만 내려갈 수 있음. 더 옆에는 불가능
// 전형적인 DP

// 3차원 배열 생각하면, 0, 1, 2 잡고
// dp[i][0] = max(dp[i-1][0], dp[i-1][1]) + arr[i][0]
// dp[i][1] = max(dp[i-1][0], dp[i-1][1], dp[i-1][2]) + arr[i][1]
// dp[i][2] = max(dp[i-1][1], dp[i-1][2]) + arr[i][2]

// 아놔 메모리 초과

// int dp_max[3][100010];
// int dp_min[3][100010];
// int arr[3][100010];

int dp_max[3];
int dp_min[3];
int arr[3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 입력
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[0] >> arr[1] >> arr[2];

        int m1, m2, m3;

        m1 = dp_max[0]; m2 = dp_max[1]; m3 = dp_max[2];
        dp_max[0] = max(m1, m2) + arr[0];
        dp_max[1] = max(max(m1, m2), m3) + arr[1];
        dp_max[2] = max(m2, m3) + arr[2];

        m1 = dp_min[0]; m2 = dp_min[1]; m3 = dp_min[2];
        dp_min[0] = min(m1, m2) + arr[0];
        dp_min[1] = min(min(m1, m2), m3) + arr[1];
        dp_min[2] = min(m2, m3) + arr[2];
    }

    cout << *max_element(dp_max, dp_max + 3) << " " << *min_element(dp_min, dp_min + 3);


    return 0;
}

