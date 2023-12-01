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


// 11055 가장 큰 증가하는 부분 수열
// 1% 틀
// 반례 : 앞에 작은게 아무것도 없는 경우 => sum[i] = arr[i]로 초기화

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    int N;
    cin >> N;
    vector<int> arr(N);
    vector<long long> sum(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sum[i] = 0;
    }


    sum[0] = arr[0];
    for (int i = 1; i < N; i++) {
        int k = arr[i];

        long long  maxSum = 0;    // 여태까지 가장 큰 합.
        sum[i] = arr[i];    // sum의 초기값. 앞에 더 작은게 없는 경우

        // 다시 앞으로 돌아가면서 본인보다 작은 수 중 최대 합을 찾는다.
        for (int j = i-1; j >= 0; j--) {

            // 일단 arr[i]보단 값이 작아야 함 (증가하는 수열)
            if (arr[j] >= arr[i] ) { continue; }

            // 가장 최대 합을 찾아야 함
            if (sum[j] <= maxSum) { continue; }

            maxSum = sum[j];
            sum[i] = arr[i] + maxSum;
        }
    }

    // for (int i = 0; i < N; i++) {
    //     cout << sum[i] << "  ";
    // }

    sort(sum.begin(), sum.end());

    cout << sum[N-1];

  
    return 0;
}