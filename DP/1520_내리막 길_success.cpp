#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <cmath>
#include <set>
using namespace std;
#include <string.h>
// #include <bits/stdc++.h>

// 1520 내리막 길 (재도전)
// 16% 시간초과 -> 시간초과 날 것 같았음. 저번에 BFS로 푼거랑 다를게 별로 없다
// DP를 어떻게 이용해야 하는지 감이 안온다

// 바킹독 풀이 봤는데... 이 생각을 어떻게 하냐. 진짜 말이 안되는 풀이가 있어버리네..

int N, M;
int arr[502][502];
int d[502][502]; 

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int dp(int y, int x) {
    // cout << y << "  " << x << "\n";

    // 만약 -1이 아니라면 다른 경로 통해서 이미 최종값이 결정된 상태 -> 굳이 더 타고 들어가지 않는다.
    if (d[y][x] != -1) { return d[y][x]; }

    // 맨 끝은 값이 1. (N, M)부터 (N, M)까지 가는 경우의 수는 1개
    if (y == N-1 && x == M-1) { return 1; }

    // 이렇게 계산하는 방법 처음봤음
    d[y][x] = 0;
    int &ret = d[y][x];
    for (int dir = 0; dir < 4; dir++) {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        // 예외처리
        if (nextY >= N || nextY < 0 || nextX >= M || nextX < 0) { continue; }
        if (arr[nextY][nextX] >= arr[y][x]) { continue; }

        // 재귀 + dp
        ret += dp(nextY, nextX);
        // cout << "ret : " << ret << "\n";
    }
    
    // for문 다 돈다 -> d[y][x] 값이 최종적으로 결정된다. -> return해서 얘랑 붙어있는 더 큰 애의 값 더할 때 사용 가능
    return ret;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    
    // 입력
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j], d[i][j] = -1;
            // d[i][j]는 초기값이 -1이고, 값이 정해지면 -1이 아님.
            // 재귀 타고 들어가면서 만약 값이 정해져있다면 (-1이 아니라면)
            // 이미 그 위치는 최종 값이 결정된 상태임 -> 굳이 더 타고 들어갈 필요가 없다.
        }
    }

    
    

    int ans = dp(0, 0);
    cout << ans << "\n";


    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << d[i][j] << "  ";
    //     }
    //     cout << "\n";
    // }



    return 0;
}