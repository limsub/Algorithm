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

// 15988 1, 2, 3 더하기 3

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


    int T, N;
    cin >> T;


    long long d[1000001] = {0, };
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;


    for (int i = 0; i < T; i++) {
        cin >> N;
        for (int i = 4; i <= N; i++) {
            d[i] = (d[i-3] + d[i-2] + d[i-1]) % 1000000009;
        }

        cout << d[N] << "\n";
    }


    return 0;
}