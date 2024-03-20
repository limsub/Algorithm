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


// 2133

// 1. 로직 구상
// 실패

// 2. 정답 확인 
// 고유하게 있는거. i = 2 -> 3개. 나머지 i = 짝수 -> 2개씩
// d[i]. j = 2 ~ i 이전까지 짝수들
// d[i] += d[i - j] * 2 or 3 (j == 2이면 3, 나머지는 2)
// 마지막 d[i] += 2

// * 즉, d[i-j]로 걸리는 짝수는 d값을 넣고, 
//      앞에 세워두려고 j로 걸리는 짝수는 * 2를 해주면 된다.


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 


    return 0;
}