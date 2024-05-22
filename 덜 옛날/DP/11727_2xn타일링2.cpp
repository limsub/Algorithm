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


// 11727 2xn 타일링2 DP

int D[10001];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    int N;
    cin >> N;

    D[1] = 1;
    D[2] = 3;
    D[3] = 1 * 2 + 3;

    for (int i = 4; i <= N; i++) {
        D[i] = (D[i-2] * 2 + D[i-1]) % 10007;
    }

    cout << D[N] << "\n";

    return 0;
}