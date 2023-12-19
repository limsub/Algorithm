#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <cmath>
#include <set>
using namespace std;
#include <string.h>
// #include <bits/stdc++.h>

// 9456 스티커
// 1% 틀

int arr[100001][2] = {0, };

void dp(int n) {
    int d[n][2];

    // 초기값(n = 1, 2)
    d[0][0] = arr[0][0];
    d[0][1] = arr[0][1];
    if (n >= 2) {
        d[1][0] = arr[0][1] + arr[1][0];
        d[1][1] = arr[0][0] + arr[1][1];
    }

    // dp 계산
    for (int i = 2; i < n && n >= 3; i++) {
        d[i][0] = max(/*d[i-2][0] + arr[i-1][1]*/ d[i-1][1] + arr[i][0], d[i-2][1] + arr[i][0]);
        d[i][1] = max(/*d[i-2][1] + arr[i-1][0]*/ d[i-1][0] + arr[i][1], d[i-2][0] + arr[i][1]);
    }

    cout << max(d[n-1][0], d[n-1][1]) << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    int T, n;
    cin >> T;


    while (T--) {

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i][0];
        }
        for (int i = 0; i < n; i++) {
            cin >> arr[i][1];
        }
        
        dp(n);
    }
    return 0;
}