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


// 11659

// 1. 로직 구상
// 일단 앞에서부터 다 더한걸 dp[i]에 저장. dp[i] : 1 ~ i까지 다 더한 값
// i, j -> cout << dp[j] - dp[i] + arr[i];


// 2. 정답 확인
// 1과 동일. 그냥 dp[j] - dp[i-1] 하면 더 깔끔


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 






    return 0;
}