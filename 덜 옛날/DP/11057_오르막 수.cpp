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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    
    int N;
    cin >> N;

    int d[1001][10] = {0, };
    
    // N == 1
    for (int j = 0; j < 10; j++) { d[1][j] = 1; }

    // N >= 2
    for (int i = 2; i <= N; i++) {

        for (int j = 0; j < 10; j++) {
            // d[i][j] = ( d[i-1][0] + d[i-1][1] + ... + d[i-1][j] )
            int sum = 0;
            for (int k = 0; k <= j; k++) { 
                sum += d[i-1][k]; 
                sum = sum % 10007;
            }

            d[i][j] = sum;
        }
    }

    // ans
    int ans = 0;
    for (int j = 0; j < 10; j++) {
        ans += d[N][j];
        ans = ans % 10007;
    }
    cout << ans << "\n";
   
    return 0;
}