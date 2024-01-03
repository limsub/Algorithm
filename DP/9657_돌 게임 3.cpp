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

int d[1002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    int n;
    cin >> n;

    // SK : 0, CY : 1
    d[1] = 0;
    d[2] = 1;
    d[3] = 0;
    d[4] = 0;

    // d 계산 시작.
    for (int t = 5; t <= n; t++) {
        // n에서 4, 3, 1을 각각 빼고 난 값에서 이길 수 있는 가능성이 있으면 무조건 이김.
        int k1 = t - 4;
        int k2 = t - 3;
        int k3 = t - 1;

        // 빼고 난 나머지는 CY 입장이니까 SK 입장에서는 값이 1일 때 이길 수 있음
        if (d[k1] == 1 || d[k2] == 1 || d[k3] == 1) {
            d[t] = 0;
        } else {
            d[t] = 1;
        }
    }


    if (d[n] == 0) {
        cout << "SK" << "\n";
    } else {
        cout << "CY" << "\n";
    }
    
    return 0;
}