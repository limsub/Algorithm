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


// 11055

// 1. 로직 구상
// i 번째에 도착하면, 다시 거꾸로 돌아간다
// i-1번째부터 시작해서 i-1, i-2, i-3 순으로 간다
// arr[i]보다 작은 값이 나오는 순간 stop 해당 인덱스를 k라고 하면
// dp[i] = dp[k] + arr[i];


// 2. 정답 확인
// 1과 거의 비슷
// 정답 코드에서는 stop 없이 j = 0 ~ i까지 모든 값을 비교함


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 



    return 0;
}