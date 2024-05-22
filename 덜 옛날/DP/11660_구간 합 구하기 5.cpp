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

// 11660 구간 합 구하기 5


int arr[1030][1030];
int d[1030][1030];

int N, M;

void printD() {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }
}

void printArr() {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    vector<int> ans;
    

    // 입력
    cin >> N >> M;
    // (입력) N x N
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            // 인덱스 하나씩 플러스 해서 받는다
            cin >> arr[i][j];
        }
    }

    // d[][] 계산
    // i = 1, j = 1
    d[1][1] = arr[1][1];
    for (int k = 2; k <= N; k++) {
        d[1][k] = arr[1][k] + d[1][k-1];
        d[k][1] = arr[k][1] + d[k-1][1];
    }
    // dp 시작
    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= N; j++) {
            d[i][j] = arr[i][j] + d[i-1][j] + d[i][j-1] - d[i-1][j-1];
        }
    }

    // printD();



    // (입력 및 계산) M (x1 y1 x2 y2)
    int x1, y1, x2, y2;
    int ansNum;
    for (int i = 0; i < M; i++) {
        cin  >> x1 >> y1 >> x2 >> y2;

        ansNum = d[x2][y2] - d[x1-1][y2] - d[x2][y1-1] + d[x1-1][y1-1];
        ans.push_back(ansNum);
    }


    // 정답 출력
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}