#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long

// 1535 안녕

// Knapsack 문제
// 1. 체력은 100에서 시작. 음수가 되지 않게 조심
// 2. 기쁨은 0에서 시작. 최대한 많은 기쁨 얻기

// Knapsack DP 할 때. dp[i]
// 1). dp[i-1]은 기본으로 깔고 감. (i번째 요소를 선택하지 않을 수 있기 때문)
// 2). i번째 요소 (arr) 을 선택하는 경우, 그걸 선택하고 남은 여유분만큼의 dp값을 더해줌.

// 즉,
// dp[i] = dp[i-1];
// dp[i] = max(dp[i], arr[i] + dp[남은체력])???

// dp[i]를 뭐로 정의할지
// - 1). dp[i] : i번째 애를 선택할 때까지 최대 기쁨, 남은 체력
// - 2). dp[i] : i만큼의 체력이 있을 때, 얻을 수 있는 최대 기쁨.
// 2)가 더 맞을 것 같아...




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    // 1. 입력
    int N; cin >> N;
    vector<int> l;  // 잃. 체
    vector<int> k;  // 얻. 기
    for (int i = 0; i < N; i++) {
        int x; cin >> x; l.push_back(x);
    }
    for (int i = 0; i < N; i++) {
        int y; cin >> y; k.push_back(y);
    }


    // 어차피 N 최대 20개밖에 안됨. 그냥 다 돌아도 될듯
    int dp[101]; // 체력이 i 남았을 때 얻을 수 있는 최대 기쁨
    for (int i = 0; i < 101; i++) dp[i] = 0;


    // // dp 시작
    // for (int i = 1; i < 101; i++) {
        
    //     // 1. 일단 i-1만큼 기본으로 가져감
    //     dp[i] = dp[i-1];


    //     // 2. 업데이트가 가능하다면 업데이트한다.
    //     for (int j = 0; j < N; j++) {
    //         // 만약, i - j번째 소요 체력 >= 1 이면 얘 사용이 가능함.

    //         if (i - l[j] > 0) {
    //             dp[i] = max(dp[i], k[j] + dp[i - l[j]]);
    //         }
    //     }

    // }

    for (int i = 0; i < N; ++i) {

        for (int j = 100; j >= l[i]; --j) {
            dp[j] = max(dp[j], dp[j - l[i]] + k[i]);
        }
    }


    // for (int i = 0; i < 101; i++) {
    //     cout << i << " : " << dp[i] << "\n";
    // }

    cout << *max_element(dp, dp + 100);
    

}

