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


// 2156

// 1. 로직 구상
// 2차원 배열 이용 [1] : 현재 연속으로 1개 마셨을 때 / [2] : 현재 연속으로 2개 마셨을 때
// d[i][1] = max{ d[i-2][1], d[i-2][2] } + arr[i];
// d[i][2] = d[i-1][1] + arr[i]
// 최종적으로 d[i][j] 중 최댓값


// 2. 정답 확인
// d 1차원 배열 이용
// d[i] : i번째까지 왔을 때 최댓값
//  - 1). i에서 안마시는 경우 = d[i-1]
//  - 2). i-2에서 마시고 i-1 안마시고 i에서 마시는 경우 = d[i-2] + arr[i]
//  - 3). i-3까지 값 +  i-1 마시고 i에서 마시는 경우 (최대 연속은 2개이기 때문에 i-3 제약조건) = d[i-3] + arr[i-1] + arr[i]

// 1도 되지 않을까 -> 틀림 : 반례 : 중간에 2개를 건너뛸 수도 있음!


int arr[10010];
int dp[10010];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    cin >> n;

    for (int i = 0; i < n; i++)  cin >> arr[i];

    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];    // 일단 무조건 최댓값을 저장하고, 연속인지 아닌지는 i를 계산하면서 직접 처리
    for (int i = 2; i < n; i++) {
        dp[i] = dp[i-1];    // 안마시는 경우
        dp[i] = max(dp[i], dp[i-2] + arr[i]);
        dp[i] = max(dp[i], dp[i-3] + arr[i-1] + arr[i]);
    }

    cout << *max_element(dp, dp + n + 1);



    return 0;
}