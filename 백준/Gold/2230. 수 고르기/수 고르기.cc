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

// 2230
// 투 포인터

// 실패 후 바킹독 풀이

int N, M;
int arr[100010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    // 1. 입력
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i];

    // 2. 정렬
    sort(arr, arr + N);

    // 3. 투 포인터 알고리즘
    int en = 0; // 처음 en은 0에서 시작
    int m = 0x7FFFFFFF;
    for (int st = 0; st < N; st++) {    // 각 st마다 최솟값을 갖는 en을 찾는다.
        // 차이가 M 이상이 될 때까지 en을 늘린다.
        while (arr[en] - arr[st] < M && en <= N-1) {
            en++;
        }

        // 만약 en이 배열 범위를 넘어섰다면, 그건 그 st에 대해 최솟값을 갖는 en이 존재하지 않음을 의미한다.
        if (en == N) break;

        m = min(arr[en] - arr[st], m);
    }

    cout << m;



    return 0;
}