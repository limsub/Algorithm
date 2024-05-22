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

// 11052 카드 구매하기

int d[1001][1001];

int main() {
	ios::sync_with_stdio(false);    
	cin.tie(0);

    int N;
    cin >> N;

    vector<int> arr(N+1, 0);
    for (int i = 1; i <= N; i++ ){
        cin >> arr[i];
    }

    // d[i][1] ~ d[i][i] 까지 저장될 예정.
    // d[i]를 계산할 때는 d[i-1]부터 d[i/2]까지 고려. 마지막에 Pi만 추가 고려
    // d[i][j] : i를 구매하려고 할 때, (오름차순) 최솟값 j를 살 때 드는 최대 비용

    // base case
    d[1][1] = arr[1];

    d[2][1] = arr[1] + d[1][1];
    d[2][2] = arr[2];

    d[3][1] = arr[1] + *max_element(d[2], d[2] + 2); // max(d[2][1], d[2][2]);
    d[3][3] = arr[3];

    // cout << *max_element(d[3], d[3] + 3) << "\n";

    // for (int i = 1; i <= 3; i++) {
    //     for (int j = 1; j <= 3; j++) {
    //         cout << d[i][j] << "  ";
    //     }
    //     cout << "\n";
    // }


    // DP 시작
    for (int i = 4; i <= N; i++) {

        // int maxAns = 0;
        for (int j = i/2; j <= i-1; j++) {

            // d[i][j] = arr[i-j] + max_element(d[j][i-j], j - (i-j));

            int maxT = 0;
            for (int k = i-j; k <= j; k++) {
                if (d[j][k] > maxT) { maxT = d[j][k]; }
            }

            d[i][j] = arr[i-j] + maxT;

        }

        d[i][i] = arr[i];


    }

    
    // 최댓값.
    int maxPrice = 0;
    for (int j = 1; j <= N; j++) {
        if (d[N][j] > maxPrice) { 
            maxPrice = d[N][j];
        }
    }
    cout << maxPrice << "\n";




    return 0;
}