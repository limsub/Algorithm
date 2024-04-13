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
// #include <pair>



// 18352
// 1. 모든 최단 거리 탐색 -> v에 저장
// 2. v for loop -> count 맞는거 출력

int N, M, K, X;

vector<int> adj[300010];
int v[300010];

void bfs() {
    queue<int> q;
    q.push(X);
    v[X] = 1;


    while (!q.empty()) {

        int cur = q.front();
        q.pop();

        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i];

            if (v[next]) continue;

            q.push(next);
            v[next] = v[cur] + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
    // 1. 입력
    cin >> N >> M >> K >> X;

    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;

        adj[x].push_back(y);
    }


    // 2. X에서 BFS 시작
    bfs();


    // 3. 출력
    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        if (v[i] - 1 == K) { 
            ans.push_back(i);
        }
    }
    if (ans.empty()) {
        cout << -1 << "\n";
    }
    else {
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << "\n";
        }
    }




    return 0;
}