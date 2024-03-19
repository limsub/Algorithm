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

// dfs로 본인보다 가벼운거 저장
// 역방향 dfs로 본인보다 무거운거 저장
// => 시간 초과

int N, M;
vector<int> adj[110];
vector<int> reverse_adj[110];

int light[110];
int heavy[110];


void dfs(int cur) {

    for (int j = 0; j < adj[cur].size(); j++) {

        int next = adj[cur][j];

        light[next] += light[cur] + 1;

        dfs(next);
    }
}

void reverse_dfs(int cur) {
    
    for (int j = 0; j < reverse_adj[cur].size(); j++) {
        int next = reverse_adj[cur][j];
        heavy[next] += heavy[cur] + 1;

        // cout << "cur : " << cur << " next : " << next << " heavy[cur] : " << heavy[cur] << " heavy[next] : " << heavy[next] << "\n";

        reverse_dfs(next);
    }

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

    for (int i = 1; i <= N; i++) {

        if (adj[i].empty()) { reverse_dfs(i); }
        if (reverse_adj[i].empty()) { dfs(i); }
    }

    int ans_cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (light[i] >= (N+1)/2) { ans_cnt ++; }
        if (heavy[i] >= (N+1)/2) { ans_cnt ++; }
    }

    cout << ans_cnt << "\n";

    return 0;
}