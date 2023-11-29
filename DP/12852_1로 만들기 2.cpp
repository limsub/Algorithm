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

// 12852 1로 만들기 2

// 99% 런타임 에러


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    long long N;
    cin >> N;

    int arr[3*N+2];

    vector<int> v(3*N + 2, 0);

    arr[2] = 1;
    arr[3] = 1;
    v[2] = 1;
    v[3] = 1;

    for (int i = 2; i <= N; i++) {
        // 1 더한거
        int n1 = i + 1;
        if (v[n1] == 0 || v[n1] > v[i] + 1) {
            v[n1] = v[i] + 1;
            arr[n1] = i;
        }
        // 2 곱한거
        int n2 = i * 2;
        if (v[n2] == 0 || v[n2] > v[i] + 1) {
            v[n2] = v[i] + 1;
            arr[n2] = i;
        }
        // 3 곱한거
        int n3 = i * 3;
        if (v[n3] == 0 ||  v[n3] > v[i] + 1) {
            
            v[n3] = v[i] + 1;
            arr[n3] = i;
        }

    }

    cout << v[N] << "\n";

    // cout << arr[N] << "\n";

    cout << N << " ";

    if (N != 1) {
        int k = arr[N];
        while (k != 1) {
            cout << k << " ";
            int a = arr[k];
            k = a;
        }
        cout << "1" << "\n";
    }

    return 0;
}