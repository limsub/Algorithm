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

// 11659 구간 합 구하기


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> arr;
    vector<int> sumArr(N);
    int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        arr.push_back(x);

        sumArr[i] = (i > 0) ? x + sumArr[i-1] : x;
    }

    int p, q;
    for (int i = 0; i < M; i++) {
        cin >> p >> q;

        int ans = (p > 1) ? sumArr[q-1] - sumArr[p-2] : sumArr[q-1];

        cout << ans << "\n";
    }

    return 0;
}