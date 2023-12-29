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

// 1520 내리막 길
// 시간 초과... DP 말고 BFS로 풀어서 그런거 같음..
// 틀렸습니다도 아니고 시간 초과....?



int v[501][501][2];  // 경로 개수를 저장하기 위한 배열. 이걸로 방문 여부 판단x
// v[0] : 현재 값. v[1] : 이전 값. 둘 차이를 계산해서 다음 v 업데이트할 때 사용
int arr[501][501]; // 방문 여부는 무조건 arr 값이 더 작은지 여부로 판단

int dy[] = {-1, 1, 0, 0 };
int dx[] = {0, 0, -1, 1 };

int N, M;



void bfs() {
    
    queue< pair<int, int> > q;

    // start index
    q.push(make_pair(0, 0));
    v[0][0][0] = 1;
    v[0][0][1] = 0;

    // bfs start
    while (!q.empty()) {
        // 탐색 index (이름을 cur로 지었어야지...하)
        int firstY = q.front().first;
        int firstX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextY = firstY + dy[i];
            int nextX = firstX + dx[i];

            // 탐색이 가능한지 확인
            // 1. index out of range
            if (nextY >= N || nextY < 0 || nextX >= M || nextX < 0) { continue; }
            // 2. arr 배열 더 작은지 ("항상 내리막길")
            if (arr[nextY][nextX] >= arr[firstY][firstX]) { continue; }

            // 탐색 ok
            q.push(make_pair(nextY, nextX));
            int dist = v[firstY][firstX][0] - v[firstY][firstX][1];
            v[nextY][nextX][1] = v[nextY][nextX][0];
            v[nextY][nextX][0] = v[nextY][nextX][0] + dist;
        }
    }
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    // 분명 DP 문제인데 생각나는 풀이는 BFS. 
    // DP 도저히 풀이가 생각이 안남

    // 1. 입력
    cin >> N >> M;  // 문제에서는 M, N이라고 했는데 내 맘대로 바꿈
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    bfs();

    cout << "\n";
   
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << v[i][j][0] << "  ";
        }
        cout << "\n";
    }

    cout << "\n";

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << v[i][j][1] << "  ";
        }
        cout << "\n";
    }

    // cout << v[N-1][M-1][0]<< "\n";

    return 0;
}