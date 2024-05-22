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

// 2303 극장 좌석. 디피
// 79% 틀

int d[41] = {0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    int N, M;
    cin >> N >> M;
    
    d[1] = 1;
    d[2] = 2;
    for (int i = 3; i < N+1; i++) {
        d[i] = d[i-1] + d[i-2];
    }




    int x = 0;
    int ans = 1;
    int pre;
    for (int i = 0; i < M; i++) {
        pre = x + 1;
        cin >> x;

        int size = x - pre;

        if (size != 0) {
            ans *= d[size];
        }
    }
    // 마지막은 따로 처리해준다
    int pre3 = x + 1;   // 마지막 x 저장
    int last = N + 1;
    int size3 = last - pre3;
    // cout << "size 3 " << size3 << "  " << d[size3] <<  "\n";
    if (size3 != 0) { ans *= d[size3]; }
    

    cout << ans << "\n";

    return 0;
}