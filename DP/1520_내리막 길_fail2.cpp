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

int N, M;
int arr[502][502];
int v[502][502][2]; // [0] - 이전 값, [1] - 현재 값 저장

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void dfs(int y, int x) {

    // cout << "y, x : " << y << " " << x << "\n";

    int curValue = arr[y][x];
    
    // cout << "v[0] v[1] : " << v[y][x][0] << "  " << v[y][x][1] << "\n";

    // 상하좌우 탐색
    for (int dir = 0; dir < 4; dir++) {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];


        if (nextY >= N || nextY < 0 || nextX >= M || nextX < 0) { continue; }
        int nextValue = arr[nextY][nextX];
        if (curValue >= nextValue) { continue; }

        // v 업데이트 + 재귀함수(dfs)
        v[nextY][nextX][0] = v[nextY][nextX][1];
        v[nextY][nextX][1] += (v[y][x][1] - v[y][x][0]);
        dfs(nextY, nextX);
    }

    return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    
    // 입력
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }


    // 맨 마지막 1
    v[N-1][M-1][1] = 1;

    // dfs 시작
    dfs(N-1, M-1);

 
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << v[i][j][0] << "  ";
    //     }
    //     cout << "\n";
    // }

    // cout << "------" << "\n";

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << v[i][j][1] << "  ";
    //     }
    //     cout << "\n";
    // }

    cout << v[0][0][1] << "\n";

    return 0;
}