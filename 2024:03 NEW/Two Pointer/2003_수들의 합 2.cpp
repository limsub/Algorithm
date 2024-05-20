#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;
#include <queue>
#include <cstdio>
#include <set>
#include <map>
// #include <pair>
// #include <bits/stdc++.h>

// 2003 수들의 합 2
// 투포인터

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    // 1. 입력
    int N, M; cin >> N >> M;
    int arr[N+1];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int ansCnt = 0;

    // 2. 투 포인터 알고리즘
    int en = 0;
    int sum = arr[0];   // arr[st] ~ arr[en]까지 합
    for (int st = 0; st < N; st++){ 
        while (sum < M) {
            en++;
            sum += arr[en];
        }

        if (sum == M) {
            ansCnt++;
        }

        sum -= arr[st];
    }

    cout << ansCnt;

    return 0;
}