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


// 2805 나무 자르기
// 이분탐색

// 2% 틀

int N, M;
int arr[1000010];
int large;

int bs() {
    int st = 0; 
    int en = large;

    int ans;

    while (st <= en) {
        int mid = (st + en)/2;
        long long sum = 0;

        for (int i = 0; i < N; i++) {
            int d = arr[i] - mid;
            sum += (d > 0) ? d : 0;
        }

        // cout << mid << "  " << sum << "\n";

        if (st == en) {
            if (sum >= M) ans = mid;
            if (sum < M) ans = mid - 1;

            break;
        }

        if (sum >= M) st = mid + 1;
        else en = mid;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    // 1. 입력
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i];
    large = *max_element(arr, arr + N);

    // 2. 정렬
    sort(arr, arr + N);

    // 3. 이분탐색
    cout << bs();



    return 0;
}