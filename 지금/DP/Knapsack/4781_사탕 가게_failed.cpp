#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long


// 4781 사탕 가게

// 사탕 쪼개기 불가 -> DP

// 사탕 칼로리의 합이 최대가 되게 하기 위함.
// * 같은 사탕을 여러 개 구매할 수 있다...!

// dp[i][j] : i번째 사탕까지 고려했을 때, j만큼의 돈이 있다면 최대 칼로리 값


// * 이건, 2차원 배열을 쓰면 안되는 문제인 듯 하다.. failed


// 12% 틀

double mm;
int N, M;   // 사탕 수 N, M은 돈의 양인데 입력값 * 100 해서 int로 생각

vector< pair<int, int> > arr;   // {사탕의 칼로리, 사탕의 가격}
int dp[5010][10010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 


    while (1) {
        // 0. 초기화
        arr.clear();
        memset(dp, 0, sizeof(dp));
        // for (int i = 0; i <= N; i++) for (int j = 0; j <= M; j++) dp[i][j] = 0;


        // 1. 입력
        cin >> N >> mm;
        // M = 100 * mm;
        M = (int)(mm * 100.0 + 0.5);

        // if (N == 0 && M == 0) break;
        if (N == 0 && mm < 0.001) break;

        arr.push_back({0, 0});
        for (int i = 0; i < N; i++) {
            int x; double yy; cin >> x >> yy;
            // int y = yy * 100;
            int y = (int)(yy * 100.0 + 0.5);

            arr.push_back({x, y});
        }



        // 2. Knapsack DP
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {

                // - 1
                dp[i][j] = dp[i-1][j];


                // - 2
                if (j >= arr[i].second) {
                    // 같은 사탕을 여러 번 구매할 수 있기 때문에 dp[i-1][j - arr[i].second]]로 하지 않았다.
                    dp[i][j] = max(dp[i][j], arr[i].first + dp[i][j - arr[i].second]);
                }
            }
        }

        cout << dp[N][M];
    }


    return 0;
}

