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


// 12852

// 1. 로직 구상
// dp[i][0] = min{ dp[i/3], dp[i/2], dp[i-1] } + 1 : 값 저장
// dp[i][1] : 이전 인덱스 저장 (i/3 or i/2 or i-1)


// 2. 정답 확인
// 거의 비슷함.
// dp 자체를 2차원 배열로 사용하지 않고, 
// prev배열을 따로 만들어서 인덱스는 아예 따로 저장


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 






    return 0;
}