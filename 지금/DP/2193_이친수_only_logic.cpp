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


// 2193

// 1. 로직 구상
// 1 0 까지는 자명함
//  1). 그 다음이 0으로 시작 : i-1에서 두번째 위치부터 시작하는거랑 개수 동일 (자리수가 같음)
//  2). 그 다음이 1로 시작 : i-2에서 첫번째 위치부터 시작하는거랑 개수 동일 (자리수가 같음)
// 즉, dp[i] = dp[i-1] + dp[i-2];


// 2. 정답 확인


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 




    return 0;
}