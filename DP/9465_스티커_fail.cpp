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

// 9465 스티커 DP

vector<int> arr1;
vector<int> arr2;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n;
    cin >> T;

    while(T--) {
        cin >> n;
        arr1.resize(n);
        arr2.resize(n);
        vector<int> dp(n, 0);
        vector<int> v(n, -10);


        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> arr2[i];
        }

        // 초기 세팅
        // i = 0;
        if (arr1[0] == arr2[0]) { dp[0] = arr1[0]; v[0] = -1; }
        if (arr1[0] > arr2[0]) { dp[0] = arr1[0]; v[0] = 0; }
        if (arr1[0] < arr2[0]) { dp[0] = arr2[0]; v[0] = 1; }

        if (n == 1) { 
            cout << dp[0] << "\n";
            continue;
        }

        // i = 1;
        if (arr1[0] + arr2[1] == arr1[1] + arr2[0]) { dp[1] = arr1[0] + arr2[1]; v[1] = -1; }
        if (arr1[0] + arr2[1] > arr1[1] + arr2[0]) { dp[1] = arr1[0] + arr2[1]; v[1] = 1; }
        if (arr1[0] + arr2[1] < arr1[1] + arr2[0]) { dp[1] = arr1[1] + arr2[0]; v[1] = 0; }

        if (n == 2) {
            cout << dp[1] << "\n";
            continue;
        }
        
        for (int i = 2; i < n; i++) {
            // 3가지 케이스 비교

            // 1.
            int v1; // 현재 v;
            if (v[i-1] == -1) { // 이전 값이 동일한 경우였다면, 나한테서 큰 걸로 선택
                if (arr1[i] == arr2[i]) { v1 = -1; }    // 나도 같으면 또 보류.
                if (arr1[i] > arr2[i]) { v1 = 0; }
                else { v1 = 1; }
            }
            else {  // 그게 아니라면, 이전 값과 반대로
                v1 = (v[i-1] == 1) ? 0 : 1; 
            }
            int d1;
            if (v1 == 0) { 
                d1 = dp[i-1] + arr1[i];
            }
            else {
                d1 = dp[i-1] + arr2[i];
            }

            // 2, 3. 이 때는 이전 v가 뭔지 필요x
            int v2, d2, v3, d3;
            v2 = 0; v3 = 1;
            d2 = dp[i-2] + arr1[i];
            d3 = dp[i-2] + arr2[i];
            // 일단 얘네 중에 큰거 골라주기
            int tmpD, tmpV;
            if (d2 == d3) { tmpV = -1; tmpD = dp[i-2] + arr1[i]; }
            if (d2 > d3) { tmpV = 0; tmpD = dp[i-2] + arr1[i]; }
            if (d2 < d3) { tmpV = 1; tmpD = dp[i-2] + arr2[i]; }


            // 이제 최종 큰거 골라주기
            if (d1 == tmpD) {
                dp[i] = d1;
                // 값이 같은데 v가 다르면 -1로 감
                if (v1 != tmpV) { v[i] = -1; }

                else { v[i] = v1; }
            }
            if (d1 > tmpD) { 
                dp[i] = d1;
                v[i] = v1;
            }
            if (d1 < tmpD) {
                dp[i] = tmpD;
                v[i] = tmpV;
            }

            // cout << dp[i] << "  " << v[i] <<  "\n";
            
            // // 셋 중에 가장 큰 걸 dp[i]에 저장, 위치도 v에 저장
            // dp[i] = 0;
            // if (d1 > dp[i]) { dp[i] = d1; v[i] = v1; }
            // if (d2 > dp[i]) { dp[i] = d2; v[i] = v2; }
            // if (d3 > dp[i]) { dp[i] = d3; v[i] = v3; }
        }

        cout << dp[n-1] << "\n";
        arr1.clear();
        arr2.clear();
        dp.clear();
        v.clear();
    }

    
    
    return 0;
}