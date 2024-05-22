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


// 2302

// 1. 로직 구상
// d[i] : i명의 사람이 연속으로 앉았을 때, 앉을 수 있는 경우의 수.
// 중간에 VIP 빼고 3, 2, 2명씩 앉으면, return d[3] * d[2] * d[2] 

// d[i]를 구하는 방법... dp 방식으로 해야 하는데 생각이 안남.
// 뭔가 그냥 1, 2, 3, 5, 7, 9, ... 방식인 거 같기도 하고


// 2. 정답 확인
// d[i]는 1과 동일
// d[i] = d[i-1] + d[i-2];
// <- 마지막에 (i-1, i)순으로 앉기 + 마지막에 (i, i-1) 순으로 앉기


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 



    return 0;
}