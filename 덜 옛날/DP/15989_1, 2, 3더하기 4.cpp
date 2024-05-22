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

// 15988 1, 2, 3 더하기 4


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    int T, N;
    cin >> T;

    int d[10001][3] = {0, };
    d[1][0] = 1;

    d[2][0] = 1;
    d[2][1] = 1;

    d[3][0] = 2;
    d[3][2] = 1;


    for (int i = 0; i < T; i++) {
        cin >> N;

        for (int t = 4; t <= N; t++) {

            d[t][0] = d[t-1][0] + d[t-1][1] + d[t-1][2];
            d[t][1] = d[t-2][1] + d[t-2][2];
            d[t][2] = d[t-3][2];
        }

        cout << d[N][0] + d[N][1] + d[N][2] << "\n";
    }

    return 0;
}