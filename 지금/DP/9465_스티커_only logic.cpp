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


// 9465

// 1. 로직 구상
// d[i][0] : 위 스티커 뗌. d[i][1] : 아래 스티커 뗌. 최댓값
// d[i][0] : max{ d[i-1][1], d[i-2][0], d[i-2][1] } + arr[i][0]
// d[i][1] : max{ d[i-1][0], d[i-2][0], d[i-2][1] } + arr[i][1]

// 2. 정답 확인
// 1과 동일

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 



    return 0;
}