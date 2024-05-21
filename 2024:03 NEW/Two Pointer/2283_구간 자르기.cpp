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

// 2283 구간 자르기

// 각 구간의 정보를 어떻게 저장할지?
// 1차원 배열 하나로 저장한다.
// 즉, 인덱스가 좀 밀리게 되는데, 굿노트 확인해보자

int arr[1000010];   // 1,000 * 1,000,000 해도 int로 커버 가능

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    // * A, B가 없으면 0, 0 출력.

    // 1. 입력
    int N, K; cin >> N >> K;
    int max_length = 0;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        max_length = max(max_length, y);
        // 3, 10이면 [3] ~ [9]까지 ++;
        for (int k = x; k < y; k++) {
            arr[k]++;
        }
    }

    // 2. 투 포인터
    int en = 1;
    int sum = arr[0];
    for (int st = 0; st < max_length; st++) {
        // cout << "st : " << st << "\n";
        while (sum < K && en < max_length) {
            // en 위치의 값을 더해준다
            sum += arr[en];

            en++;
        }

        if (sum == K) {
            cout << st << " " << en;
            return 0;
        }

        // st 넘어가기 전에 sum에서 빼준다
        sum -= arr[st];

        // 만약 둘다 끝까지 왔다면 답 없다
        if (st == max_length-1 && en == max_length) {
            cout << "0 0\n";
            return 0;
        }
    }


    return 0;
}