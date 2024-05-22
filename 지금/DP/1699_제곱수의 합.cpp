#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;
#include <queue>
#include <cstdio>
#include <set>


// 1699 


// 1. 로직 구상
// i 이하의 제곱수들을 파악함. (ex. 18 : 16, 9, 4, 1)
// 각 제곱수를 뺀 값 (i - k) 에 대한 dp[] 값 + 1 하면 된다.
// dp[18] = min{ 1 + dp[2], 1 + dp[9], 1 + dp[14], 1 + dp[17] }


// 2. 정답 확인
// 1과 동일

int n;
int d[100010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    cin >> n;

    for (int i = 1; i <= n; i++) {
        // 최댓값
        d[i] = i;

        // 각 제곱수를 뺀 값 처리
        for (int j = 1; j * j < i; j++) {
            int k = i - j * j;
            d[i] = min(d[i], d[k] + 1);
        }
    }
    cout << d[n];




    return 0;
}