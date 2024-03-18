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


// 2617 구슬 찾기

// 바킹독

int N, M;
vector<int> adj[110];           // 본인보다 가벼운거 저장
vector<int> reverse_adj[110];   // 본인보다 무거운거 저장

bool v[110];

bool solve1(int start) {

    fill(v, v + N + 1, 0);

    queue<int> q;
    q.push(start);
    v[start] = 1;

    int cnt = 0;

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int j = 0; j < adj[cur].size(); j++) {
            int next = adj[cur][j];

            if (v[next]) { continue; }

            q.push(next);

            v[next] = 1;

            cnt++;
        }
    }

    return cnt >= (N+1)/2;
}

bool solve2(int start) {

    fill(v, v + N + 1, 0);

    queue<int> q;
    q.push(start);
    v[start] = 1;

    int cnt = 0;

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int j = 0; j < reverse_adj[cur].size(); j++) {
            int next = reverse_adj[cur][j];

            if (v[next]) { continue; }

            q.push(next);

            v[next] = 1;

            cnt++;
        }
    }

    return cnt >= (N+1)/2;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    cin >> N >> M;

    int x, y;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        
        adj[y].push_back(x);
        reverse_adj[x].push_back(y);
    }

    int ans_cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (solve1(i) || solve2(i)) { ans_cnt ++; }
    }

    cout << ans_cnt << "\n";

    return 0;
}