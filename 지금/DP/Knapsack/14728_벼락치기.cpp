#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long


// 14728 벼락치기

// 0% 틀 -> dp[i][j] = dp[i][j-1]이라고 씀. 바보임 그냥

int N, K;
vector< pair<int, int> > arr;   // (공부 소요 시간, 문제 배점) - 인덱스 1부터 시작 예정
int dp[102][10010]; // dp[i][j] : i번째 단원까지 고려했을 때, j만큼의 시간으로 얻을 수 있는 최대 배점

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    arr.push_back({0, 0});

    // 1. 입력
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;

        arr.push_back({x, y});
    }


    // Knapsack DP
    for (int i = 1; i <= N; i++) {

        for (int j = 1; j <= K; j++) {
            // - 1).
            dp[i][j] = dp[i-1][j];

            // - 2).
            if (j >= arr[i].first) {
                dp[i][j] = max(dp[i][j], arr[i].second + dp[i-1][j - arr[i].first]);
            }
        }
    }

    cout << dp[N][K];


    return 0;
}

