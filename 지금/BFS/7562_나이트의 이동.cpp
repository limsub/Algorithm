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
#include <map>
// #include <pair>
// #include <bits/stdc++.h>

// 7562 나이트의 이동


// 기존 좌표 bfs의 변형. -> dy, dx를 새롭게 만들기.
// 나머지는 동일.


int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int graph[310][310];    // 필요 없을듯.
int v[310][310];

int N;
int start_y, start_x; 
int end_y, end_x; 

void initGraph() {
    for (int i = 0; i < N; i++) {
        fill(graph[i], graph[i] + N, 0);
        fill(v[i], v[i] + N, 0);
    }
}

void bfs() {
    queue< pair<int, int> > q;
    q.push(make_pair(start_y, start_x));
    v[start_y][start_x] = 1;


    while (!q.empty()) {
        int cur_y = q.front().first;
        int cur_x = q.front().second; 
        q.pop();

        for (int dir = 0; dir < 8; dir++) {
            int next_y = cur_y + dy[dir];
            int next_x = cur_x + dx[dir];

            if (next_y >= N || next_y < 0 || next_x >= N || next_x < 0) continue;
            if (v[next_y][next_x]) continue;


            q.push(make_pair(next_y, next_x));
            v[next_y][next_x] = v[cur_y][cur_x] + 1;

            if (next_y == end_y && next_x == end_x) return ;
        }
    }

    
  
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int T; cin >> T;

    while (T--) {
        cin >> N;

        cin >> start_y >> start_x;
        cin >> end_y >> end_x;

        bfs();

        if (v[end_y][end_x]) {
            cout << v[end_y][end_x] - 1 << "\n";
        }
        else { 
            cout << "0\n";
        }

        initGraph();
    }

   
    return 0;
}