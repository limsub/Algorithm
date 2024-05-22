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

// 2294 동전2

// 런타임 에러..? OutofBounds....??
// -> d 크기 조절.
// 3% 틀림
// -> 예외처리!!

int d[100001];
int arr[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    // 입력 및 초기화
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        d[arr[i]] = 1;  // 동전 1개만 필요한 경우이므로 바로 값 지정
    }

    d[0] = 0;

    // dp 시작
    for (int i = 1; i <= k; i++) {
        int minA = 0x7F7F7F7F; // 걸릴 때 사용할 최솟값

        // 동전 종류
        for (int j = 0; j < n; j++) {
            int coin = arr[j];
            
            // 큰 경우만 체크. 같은 경우는 이미 1로 초기화 완료
            if (i - coin > 0) { 
                
                // 불가능한 경우 -> 고려하지 않는다.
                if (d[i - coin] == 0) { continue; }

                minA = min(minA, 1 + d[i - coin]);
                d[i] = minA;    // 걸릴 때만 값을 바꿔줘야 함. 한 번도 안걸리면 d[i] = 0;
            }

            // 같은 경우가 걸릴 가능성도 있기 때문에 바로 1 쥐어주고 탈출
            if (i == coin) {
                d[i] = 1;
                break;
            }
        }
    }

    // for (int i = 0; i <= k; i++) {
    //     cout << d[i] << "  ";
    // }

    if (d[k] == 0) {
        cout << -1 << "\n";
    } else {
        cout << d[k] << "\n";
    }
    

    return 0;
}