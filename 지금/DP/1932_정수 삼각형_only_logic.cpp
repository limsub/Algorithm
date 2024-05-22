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


// 1932

// 1. 로직 구상
// arr[i][j]에 저장
// for i
// for j
//  1). (j == 0) dp[i][0] = dp[i-1][0] + arr[i][0];
//  2). (j == i) dp[i][i] = dp[i-1][i-1] + arr[i][i];
//  3). dp[i][j] = max{ dp[i-1][j-1], dp[i-1][j] } + arr[i][j];


// 2. 정답 확인
// 1과 동일
// 인덱스 처리에 예외처리하지 않기 위해 j를 1부터 저장하는 스킬

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 




    return 0;
}