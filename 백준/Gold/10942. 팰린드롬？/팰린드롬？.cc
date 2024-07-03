#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long
#define INF 0x3F3F3F3F // INF + INF 연산할 일이 생길 수 있기 때문에 7로 안했다.

// 10942 펠린드롬?

int n;
int arr[2020];
int m;

int dp[2020][2020]; 
// dp[i][j] : i ~ j 까지가 펠린드롬인지 여부 저장
// i ~ j 까지가 펠린드롬이기 위해서는, 1). i+1 ~ j-1까지 펠린드롬. 2). arr[i] == arr[j]

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 입력
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;   // i~i는 무조건 펠린드롬
    }
    for (int i = 0; i < n-1; i++) {
        if (arr[i] == arr[i+1]) {
            dp[i][i+1] = 1; // 두 수가 같으면, i~i+1은 펠린드롬
        }
    }

    for (int i = n-2; i >= 0; i--) {
        for (int j = i+2; j < n; j++) {
            if (dp[i+1][j-1] && arr[i] == arr[j]) {
                dp[i][j] = 1;
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }


    cin >> m;
    while (m--) {
        int x, y; cin >> x >> y;

        x--; y--;

        cout << dp[x][y] << "\n";
    }


    return 0;
}

