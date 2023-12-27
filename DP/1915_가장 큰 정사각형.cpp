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

// 1915 가장 큰 정사각형
int arr[1001][1001];
int d[1001][1001];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    int n, m;
    cin >> n >> m;


    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j] - '0';
        }
    }


    int ans = 0;

    // 0 라인은 따로
    for (int i = 0; i < n; i++) {
        // d[i][0]
        d[i][0] = arr[i][0];
        if (d[i][0] > ans ) { ans = d[i][0]; }
    }
    for (int j = 0; j < m; j++) {
        // d[0][j];
        d[0][j] = arr[0][j];
        if (d[0][j] > ans) { ans = d[0][j]; }
    }

    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {

            if (arr[i][j] == 0) { 
                d[i][j] = 0; 
                continue;
            }

            d[i][j] = min( min(d[i-1][j], d[i][j-1]), d[i-1][j-1]) + 1;

            if (d[i][j] > ans) { ans = d[i][j]; }
        }
    }

    

    cout << ans * ans << "\n";

    return 0;
}