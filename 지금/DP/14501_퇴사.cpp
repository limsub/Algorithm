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


// 14501

// 1. 로직 구상
// 실패.

// 2. 정답 확인
// d[i] : i 번째에 상담을 하든 안하든, 얻을 수 있는 최대 수익!
// i = n ~ 1 역순으로 내려와!!
// 기존에 풀었던 방법은 다른 방식.

int tArr[20];
int pArr[20];
int dp[20];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    cin >> n;

    for (int i = 1; i <= n; i++) { cin >> tArr[i] >> pArr[i]; }

    for (int i = n; i >= 1; i--) {

        if (tArr[i] + i <= n + 1) {
            dp[i] = max(dp[i + tArr[i]] + pArr[i], dp[i+1]);
            // 상담을 했다 : pArr[i]만큼 수익 + tArr[i]만큼 이후 상담에 대한 수익
            // 상담을 하지 않았다. : dp[i+1]만큼 수익
        }

        else dp[i] = dp[i+1];

    }

    cout << *max_element(dp, dp+n+1);


    return 0;
}