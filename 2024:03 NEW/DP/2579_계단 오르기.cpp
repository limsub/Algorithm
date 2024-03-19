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


// 2579

// 1. 로직 구상
// dp[i] : i번째 계단을 밟기 직전까지, 가능한 점수의 최댓값 (i 순차적으로 업데이트 가능) pair<int, int> (점수, 누적 연속 계단 수)

// 2. 정답 확인
// - 거의 비슷. pair 대신 2차원 배열 이용
// dp[i][j] : j개의 누적 계단을 밟았을 때, 최댓값 (j = 1 or 2)
// 누적 계단 수를 저장하는 게 아니라, 그 경우 점수를 저장한다. (누적 계단 수는 어차피 정해져 있으니까)

int arr[305];
int n;
int dp[305][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    cin >> n;
    for (int i = 1; i <= n; i++) { cin >> arr[i]; }
    
    if (n == 1) { cout << arr[1]; return 0;}

    // i = 1
    dp[1][1] = arr[1];
    dp[1][2] = 0;   // 2개를 밟을 수 없음

    // i = 2
    dp[2][1] = arr[2];
    dp[2][2] = arr[1] + arr[2];   // 1, 2

    for (int i = 3; i <= n; i++) {
        // 1). i - 2에서 점프 뛰어서 온 경우. [1], [2] 모두 가능
        dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + arr[i];

        // 2). i - 1에서 연속으로 온 경우. [2]는 불가능
        dp[i][2] = dp[i-1][1] + arr[i];
    }

    cout << max(dp[n][1], dp[n][2]);


    return 0;
}