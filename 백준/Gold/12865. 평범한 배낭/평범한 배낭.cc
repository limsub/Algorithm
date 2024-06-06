#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long

// 12865 평범한 배낭

// Knapsack 문제
// dp[i][j] : i번째 물건까지 탐색했을 때, 용량이 j인 가방에 담을 수 있는 최댓값
// 1). dp[i-1][j] : i-1번째 가방까지 탐색했을 때의 값은 기본으로 가져갈 수 있다.
// 2). (만약 i번째 물건을 선택한다면) 
//      - w[i] 만큼의 용량을 차지하게 된다. 즉, 남은 용량 : j - w[i]
//      - 내가 궁금한 것 : j - w[i]만큼의 용량이 남았을 때, (i번째 물건을 선택하지 않은 경우) 담을 수 있는 최댓값
//                      = dp[i-1][j - w[i]];

// 위에서 말하는 i는 1부터 시작, 즉, dp[0][j]는 모두 0으로 초기화
// j = 0일 때는 용량이 0이기 때문에 가져갈 수 있는 가치가 없다. 즉, dp[i][0] 역시 0으로 초기화


pair<int, int> arr[110];    // {용량, 가치}
// vector< vector<int> > dp(110, vector<int>(100010) );
int dp[110][100010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    

    // 1. 입력
    int N, K; cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        int x, y; cin >> x >> y;
        arr[i] = {x, y};
    }

    // 2. Knapsack DP
    for (int i = 1; i <= N; i++) {
        // i번째 물건까지 탐색한 경우

        for (int j = 1; j <= K; j++) {
            // 현재 최대 용량 : j

            // - 1). dp[i-1][j] 값은 기본으로 가져갈 수 있다.
            dp[i][j] = dp[i-1][j];

            // - 2). (i번째 물건을 가져간다고 할 때)
            // int w = arr[i].first;
            // i-1번째 물건까지 탐색했을 때, j - w만큼의 용량으로 가져갈 수 있는 최댓값
            if (j >= arr[i].first) {
                dp[i][j] = max(dp[i][j], dp[i-1][j - arr[i].first] + arr[i].second);
            }
            
        }
    }

    cout << dp[N][K];
}

