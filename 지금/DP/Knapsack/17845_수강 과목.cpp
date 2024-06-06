#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long


// 17845 수강 과목

// Knapsack

// 과목의 중요도 합이 최대.


int N, K;   // 최대 공부시간 N, 과목 수 K
vector< pair<int, int> > arr;   // i번째(1부터 시작) 과목의 (중요도, 필요 시간)


int dp[1010][10010];
// dp[i][j] : i번째 과목까지 고려했을 때, j만큼의 공부시간이 있을 때 얻을 수 있는 최대 중요도


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    // 1. 입력
    cin >> N >> K;
    arr.push_back({0, 0});  // 인덱스 밀기 위함
    for (int i = 0; i < K; i++) {
        int x, y; cin >> x >> y;
        arr.push_back({x, y});
    }


    // 2. Knapsack DP
    for (int i = 1; i <= K; i++) {

        for (int j = 1; j <= N; j++) {

            // - 1). i번째 과목을 선택하지 않았을 때 : dp[i-1][j]와 값이 동일 (i-1번째 과목까지만 고려한 결과)
            dp[i][j] = dp[i-1][j];

            // - 2). i번째 과목을 선택했을 때 (일단, j > arr[i].second 조건 만족해야 함)
            // (i번째 과목의 중요도) + (i-1번째까지만 고려했을 때, j - arr[i].second 시간 있을때 최대 중요도)
            if (j >= arr[i].second) {
                dp[i][j] = max(dp[i][j], arr[i].first + dp[i-1][j - arr[i].second]);
            }
        }
    }

    // for (int i = 0; i <= K; i++) {
    //     for (int j = 50; j <= N; j++) {
    //         cout << dp[i][j] << "  ";
    //     }
    //     cout << "\n";
    // }

    cout << dp[K][N];

    return 0;
}

