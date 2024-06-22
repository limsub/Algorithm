#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long


// 16493 최대 페이지 수

// Knapsack
// 각 챕터 : (소요되는 일 수), (페이지 수)
// 최대 N일 제공.

// -> dp[i][j] : i번째 챕터까지 고려했을 때, 최대 j일 동안 읽을 수 있는 페이지 수

// 1). dp[i][j] = dp[i][j-1]
//     : i번째 챕터를 선택하지 않는다면, i-1번째 챕터까지 선택했을 때 최댓값과 동일하다

// 2). dp[i][j] = max(dp[i][j], arr[i].second + dp[i-1][j - arr[i].first))
//     : i번째 챕터를 선택한다면, (i번째 챕터의 페이지 수) + (i-1번째까지 고려했을 때, (j - i번째 소요일수) 일 동안 읽을 수 있는 페이지 수 )



// 1% 틀 -> 인덱스가 애매해. dp[i-1]에 접근하기 때문에 i = 1부터 시작하는게 맞는 것 같아



int dp[22][202];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 입력
    int N, M; cin >> N >> M;
    vector< pair<int, int> > arr;
    arr.push_back({0, 0});
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        arr.push_back({x, y});
    }


    // 2. Knapsack DP
    for (int i = 1; i <= M; i++) {

        for (int j = 1; j <= N; j++) {

            // - 1.
            dp[i][j] = dp[i-1][j];

            // - 2.
            if (j >= arr[i].first) {
                dp[i][j] = max(dp[i][j], arr[i].second + dp[i-1][j - arr[i].first]);
            }
                
        }
    }

    // for (int i = 0; i <= M; i++) {
    //     for (int j = 0; j <= N; j++) {
    //         cout << dp[i][j] << "      ";
    //     }
    //     cout << "\n";
    // }


    cout << dp[M][N];


}

