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

// 2133 타일 채우기
// 1% 틀 -> 계산 실수. d[4]를 9라고 하고 있었다.

int N;

int d[31];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    // 1. N이 홀수면 불가능 -> 0
    // 2. N이 짝수이면, N 미만의 짝수의 덧셈 (순서O) 경우의 수 찾기 -> 백트래킹
    // 3. 각 경우에서, 짝수가 2이면 값은 3, 2 이외의 수에 대한 값은 2 -> 싹 곱해주기
    // 4. 마지막 N 자체의 경우 2 더해주기

    // -> 이렇게 하면 DP가 아님.. 다시 생각하기. 경우의 수 구하는 과정만 DP로 좀 다시 생각

    // d 배열 이용해서, 경우의 수 계산하는 방법만 DP 방식으로 한다.

    // 입력
    cin >> N;
    // 1. 
    if (N % 2 != 0) { cout << 0 << "\n"; return 0; }

    // 2. 
    // backTracking(0);


    // DP 방식
    d[2] = 3;
    d[4] = 11;

    for (int i = 6; i <= N; i += 2) {
        int sum = 0;
        for (int j = 2; j < i; j += 2) {
            if (j == 2) { sum += 3*d[i-j]; }
            else { sum += 2*d[i-j]; }
        }
        sum += 2;
        d[i] = sum;
    }
    
    // for (int i  = 0; i <= N; i++) {
    //     cout << i << " : " << d[i] << "\n";
    // }

    cout << d[N] << "\n";
    

    
    

    return 0;
}