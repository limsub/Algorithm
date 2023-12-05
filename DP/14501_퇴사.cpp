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

// 14501 퇴사

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    int N;
    cin >> N;

    vector<int> T(N + 1, 0);
    vector<int> P(N + 1, 0);

    vector<int> d(N + 1, 0);

    for (int i = 1; i < N+1; i++) {
        cin >> T[i] >> P[i];
    }


    // 디피 시작
    for (int i = 1; i < N+1; i++) {

        int max = 0;

        // Pi를 포함하는 값만 d[]에 저장한다. (어차피 j로 한번 다시 돌기 때문)
        // Ti를 넣었을 때 N이 초과하지만 않도록 해준다.


        if (i + T[i] - 1 > N) { 
            // cout << "컨티뉴  " << i << "\n";
            continue; 
        }

        // 1. Pi
        if (P[i] > max) { max = P[i]; }

        // 2. i침범x + P[i] 
        for (int j = 1; j < i; j++) {

            if (j + T[j] - 1 < i) {    // 침범x
                // cout << j << "  " << i << "\n";
                if (d[j] + P[i] > max) { max = d[j] + P[i]; }
            }
        }

        d[i] = max;
    }

    // 출력
    int maxAns = -1;
    for (int i = 1; i <= N; i++) {
        if (d[i] > maxAns) { maxAns = d[i]; }
    }

    cout << maxAns << "\n";

 
    return 0;
}