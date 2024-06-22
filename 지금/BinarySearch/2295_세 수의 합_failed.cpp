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

// 2295 세 수의 합

// 중복해서 선택 가능. 즉 5 + 5 + 5 = 15 이런것도 가능.

// 방식
// - 1. 합이 되는 수를 선택 -> 세 합이 이게 되는 수가 있는지 탐색
// - 2. 세 수를 선택 -> 합이 배열 안에 있는지 탐색

// 일단 -2 채택. 근데 세 수의 경우의 수를 다 찾으려면 o(n^3). -> 시간 초과
// 3-pointer 느낌으로 해야 할 것 같은데...
// s1, s2, s3라고 하는데, s1은 그냥 for loop 돌리고, s2 s3에 대해 투포인터 진행 -> o(n^2)
// 각각 합 나올 때마다 binary search -> o(logn)


// 가능한 sum의 경우의 수를 찾는게 제일 힘들다. o(n^3)에서 줄여야 함.

int arr[1010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    // 1. 입력
    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    // 2. 정렬
    sort(arr, arr + N);

    // 2.5 최댓값 저장
    int max_val = arr[N-1];

    // 2. 
    // int sum = 0;
    // int ans = 0;


    /* ===== 이렇게 하면 시간 초과 ===== */
    // for (int s1 = 0; s1 < N; s1++) {
    //     for (int s2 = s1; s2 < N; s2++) {
    //         for (int s3 = s2; s3 < N; s3++) {
    //             int sum = arr[s1] + arr[s2] + arr[s3];

    //             if (binary_search(arr, arr + N, sum)) {
    //                 ans = max(ans, sum);
    //             }
    //         }
    //     }
    // }
    // cout << ans;


    // int sum = 0;
    // int ans = 0;
    // for (int s1 = 0; s1 < N; s1++) {

    //     sum += arr[s1];

    //     int en = s1;
    //     for (int st = s1; st < N; st++) {

    //         while (!binary_search(arr, arr + N, sum) && en < N) {
                

    //             sum += arr[en];

    //             en++;

    //         }

    //     }


    //     for (int s2 = s1; s2 < N; s2++) {
    //         int s3 = s2;

    //         sum += arr[s2];

    //         while (sum < max_val && s3 < N) {

    //             sum += arr[s3];

    //             // sum이 배열 안에 있는지 체크
    //             if (binary_search(arr, arr + N, sum)) {
    //                 ans = max(sum, ans);
    //             }

    //             s3++;

    //         }
    //     }
    // }
    

    return 0;
}