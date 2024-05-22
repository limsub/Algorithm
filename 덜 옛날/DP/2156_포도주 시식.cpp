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

// 2156 포도주 시식
// 2% 틀

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    
    int N;
    cin >> N;
    int arr[10002] = {0, };
    int d[10002][2] = {0, };

    // 1. arr 입력
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    // 2. d[0] 계산
    d[1][0] = arr[1];
    d[2][0] = arr[1] + arr[2];
    d[3][0] = max(arr[1] + arr[3], arr[2] + arr[3]);

    // 2.5 d[1] 계산
    d[1][1] = d[1][0];
    d[2][1] = max(d[2][0], d[1][1]);
    d[3][1] = max(d[3][0], d[2][1]);

    for (int i = 4; i <= N; i++) {
        d[i][0] = max(d[i-2][1] + arr[i], d[i-3][1] + arr[i-1] + arr[i]);
        d[i][1] = max(d[i][0], d[i-1][1]);
    }
    
    // 3. 출력
    cout << d[N][1] << "\n";
  
    return 0;
}