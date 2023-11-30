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


// 2193 이친수

int D[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    int N;
    cin >> N;

    pair<long, long> arr[100];

    arr[1] = make_pair(1, 0);
    arr[2] = make_pair(1, 0);

    arr[3] = make_pair(1, 1);
    for (int i = 4; i <= N; i++) {
        arr[i] = make_pair(arr[i-1].first + arr[i-1].second, arr[i-1].first);
    }

    cout << arr[N].first + arr[N].second << "\n";



    return 0;
}