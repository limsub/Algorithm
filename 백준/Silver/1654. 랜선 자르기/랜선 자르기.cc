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


// 1654 랜선 자르기
// 이분탐색


// 등식은 만들겠는데, 이걸 어떻게 이분탐색으로 푼다는걸까..?

// 포기 후 구글링.

int K, N;
int arr[10010];


long long bs(int max_val) {


    long long st = 1; long long en = max_val;

    long long ans = en;

    while (st <= en) {
        long long mid = (st + en)/2;

        // 모든 수에 대해 몫의 합
        long long q = 0;

        // 만약 st와 en이 같아졌다면,
        // 이 때 en의 en값에 대해 테스트해보고,
        // 성공하면 en이 답이고, 실패하면 en - 1이 답이다.
        if (en == st) {
            for (int i = 0; i < K; i++) {
                q += arr[i]/mid;
            }

            if (q >= N) ans = mid;
            else ans = mid - 1;
            break;
        }

        for (int i = 0; i < K; i++) {
            q += arr[i]/mid;
        }

        if (q >= N) {
            // 최댓값을 찾는 게 목표이기 때문에, 계속해서 st를 키워본다.
            st = mid + 1;
        }
        else {
            en = mid;
        }
    }

    return ans;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    // 1. 입력
    cin >> K >> N;
    int max_val = 0;
    for (int i = 0; i < K; i++) {
        cin >> arr[i];
        max_val = max(max_val, arr[i]);
    }
    // int max_val = *max_element(arr, arr + K);


    cout << bs(max_val);

    return 0;
}