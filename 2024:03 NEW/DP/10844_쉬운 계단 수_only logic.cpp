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


// 10844

// 1. 로직 구상
// d[i][j] : i번째 자리수가 j가 될 수 있는 경우의 수
// i = 1 -> d[1][0] = 0, d[1][1] ~ d[1][9] = 1
// d[i][0] = d[i-1][1], d[i][9] = d[i-1][8]
// d[i][j] = d[i-1][j-1] + d[i-1][j+1]

// 2. 정답 확인
// 1과 동일.
// 저 로직을 짤 때 이런 방식으로 간결하게
// if (j != 0) { d[i][j] += d[i-1][j-1]; }
// if (j != 9) { d[i][j] ++ d[i-1][j+1]; }


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 




    return 0;
}