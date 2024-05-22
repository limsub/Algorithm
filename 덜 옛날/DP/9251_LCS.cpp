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

// 9251 LCS
// 알고리즘 수업 강의자료 보고 공부 먼저 함

int b[1001][1001];
int c[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    // 입력 및 초기화
    string A;
    string B;
    cin >> A;
    cin >> B;

    int m = A.size();
    int n = B.size();

    // int b[m+1][n+1];
    // int c[m+1][n+1];

    for (int i = 0; i <= m; i++) 
        c[i][0] = 0;
    for (int j = 0; j <= n; j++) 
        c[0][j] = 0;

    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int is = i + 1;
            int js = j + 1;

            if (A[i] == B[j]) {
                // 같다. 대각선 가리키게 하고, c값 +1
                b[is][js] = 2;
                c[is][js] = c[is-1][js-1] + 1;
            }
            else if (c[is - 1][js] >= c[is][js - 1]) {
                // 다른데 위가 더 큼. 위 가리키게 하고 c값 동일
                b[is][js] = 1;
                c[is][js] = c[is - 1][js];
            }
            else {
                // 다른데 왼쪽이 더 큼. 왼쪽 가리키게 하고 c값 동일
                b[is][js] = 0;
                c[is][js] = c[is][js-1];
            }
        }
    }
    

    // for (int i = 0; i <= m; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         cout << b[i][j] << " ";
    //     }
    //     cout << "\n";
    // }


    // cout << "-----" << "\n";

    // for (int i = 0; i <= m; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         cout << c[i][j] << " ";
    //     }
    //     cout << "\n";
    // }


    cout << c[m][n] << "\n";

   
    return 0;
}