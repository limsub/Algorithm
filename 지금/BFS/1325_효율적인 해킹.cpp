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


// 1325 효율적인 해킹
// 1. 모든 컴퓨터에 대해 bfs
// 2. 각 bfs 결과를 vector에 저장
// 3. 최댓값 결과를 갖는 ans vector 저장
// 4. 출력

vector<int> adj[10010];
int v[10010];

int N, M;

int bfs(int start) {
    queue<int> q;
    q.push(start);
    v[start] = 1;

    int ansCnt = 1;

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i];

            if (v[next]) continue;

            q.push(next);
            v[next] = 1;
            ansCnt++;
        }
    }

    return ansCnt;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    // 1. 입력
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;

        adj[y].push_back(x);
    }

    // 2. bfs 실행
    int max_cnt = 0;
    int count[10010];
    for (int i = 1; i <= N; i++) {
        count[i] = bfs(i);

        if (count[i] > max_cnt) max_cnt = count[i];

        fill(v, v + N+1, 0);
    }


    // 3. 최대 count 탐색
    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        if (count[i] == max_cnt) {
            ans.push_back(i);
        }
    }

    // 4. 출력
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }


    // cout << bfs(2);

    
    return 0;
}