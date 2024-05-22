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

// 10844 쉬운 계단 수

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    int N;
    cin >> N;

    long long  d[101][10] = {0, };

    // i = 1;
    for (int j = 1; j < 10; j++) {
        d[1][j] = 1;
    }

    for (int i = 2; i <= N; i++) {
        // j = 0;
        d[i][0] = d[i-1][1];

        // j = 9;
        d[i][9] = d[i-1][8];

        // j = 1 ~ 8
        for (int j = 1; j <= 8; j++) {
            d[i][j] = (d[i-1][j-1] + d[i-1][j+1]) % 1000000000;
        }
    }

    long long ansSum = 0;
    for (int j = 0; j < 10; j++ ) {
        ansSum += d[N][j];
        ansSum %= 1000000000;
    }
    cout << ansSum << "\n";

    
    return 0;
}