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

// 9084 동전


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        // 입력
        int N, M;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++)  { cin >> arr[i]; }
        cin >> M;

        // for (int p = 0; p < arr.size(); p++) {
        //     cout << arr[p] << "  ";
        // }
        // cout << "\n";
        // cout << "M : " << M << "\n";


        // 배열 초기화
        int d[21][10001];   // 사실상 (d[N][M])

        // 처음 값 초기화 (d[0])
        int sNum = arr[0];
        d[0][0] = 1;
        for (int i = 1; i <= M; i++) {
            if (i % sNum == 0) {
                d[0][i] = 1;
            }
            else { 
                d[0][i] = 0;
            }
        }


        // 이후 값들 초기화 (d[1] ~ d[N-1])
        for (int i = 1; i < N; i++) {
            int nNum = arr[i];

            // d[i]
            d[i][0] = 1;
            for (int j = 1; j <= M; j++) {
                // d[i][1] ~ d[i][M]
                int sum = 0;
                for (int k = 0; nNum * k <= j; k++) {
                    sum += d[i-1][j - nNum * k];
                    // if (i == 1 && j == 2) {
                    //     cout << "k : " << k << "\n";
                    //     cout << "d[i-1][j-nNum * k] : " << d[i-1][j - nNum * k] <<  "\n";
                    // }
                }
                d[i][j] = sum;
            }
        }

        // for (int i = 0; i < N; i++) {
        //     cout << "i : " << i << " arr[i] : " << arr[i] << "\n";
        //     for (int j = 0; j <= 20; j++) {
        //         cout << "j : " << j << " d[i][j] : " << d[i][j] << "\n";
        //     }
        //     cout << "\n";
        // }

        cout << d[N-1][M] << "\n";
    }

  


    return 0;
}