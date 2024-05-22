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

// 2667 단지번호 붙이기
// 결국 BFS
int N;

int v[30][30];
string arr[30];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int bfs(int y, int x) {

    int cnt = 0;

    queue< pair<int, int> > q;
    q.push(make_pair(y, x));
    v[y][x] = 1;

    while (!q.empty()) {

        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        cnt++;

        for (int dir = 0; dir < 4; dir++) {

            int nextY = curY + dy[dir];
            int nextX = curX + dx[dir];

            if (nextY >= N || nextX >= N || nextY < 0 || nextX < 0) { continue; }
            if (v[nextY][nextX] == 1) { continue;}
            if (arr[nextY][nextX] == '0') { continue; }

            q.push(make_pair(nextY, nextX));
            v[nextY][nextX] = 1;
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> ans;

    // 아직 탐색 안한 곳 있으면 탐색 시작
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            if (arr[i][j] == '1' && v[i][j] == 0) {
                ans.push_back(bfs(i, j));
            }
        }
    }


    // 출력
    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
}