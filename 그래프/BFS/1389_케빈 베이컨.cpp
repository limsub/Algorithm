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

// 1389 케빈 베이컨
// 다익스트라..? 하면 될 것 같은데
// 거리 cost가 없기 때문에 그냥 BFS로도 가능

#define INF 0x7F7F7F7F

vector< vector<int> > arr;

vector< vector<int> > v;
int N, M;


void dijkstra(int start) {
    queue<int> q;

    q.push(start);
    v[start][start] = 1;

    while (!q.empty()) {
        
        int cur = q.front();
        q.pop();

        for (int i = 0; i < arr[cur].size(); i++) {
            int next = arr[cur][i];

            if (v[start][next] != 0) { continue; }

            q.push(next);
            v[start][next] = v[start][cur] + 1;

        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;


    // 초기화
    arr.resize(N+1);
    v.resize(N+1);
    for (int i = 0; i <= N; i++) {
        v[i].resize(N+1);
        for (int j = 0; j <= N; j++) {
            v[i][j] = 0;
        }
    }

    // 배열 입력
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        arr[x].push_back(y);
        arr[y].push_back(x);

    }

    // 다익스트라 실행
    for (int i = 1; i <= N; i++) {
        dijkstra(i);
    }

    // for (int i = 1; i <= N; i++) {
    //     cout << i << "번째 : ";

    //     for (int j = 1; j <= N; j++) {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    

    // dist 비교
    int ansIdx = -1;
    int minCnt = INF;
    for(int i = N; i >= 1; i--) {
        int sum = 0;
        for (int j = 1; j <= N; j++) {
            sum += v[i][j];
        }

        if (sum <= minCnt) { minCnt = sum; ansIdx = i;}
    }

    cout << ansIdx << "\n";

}