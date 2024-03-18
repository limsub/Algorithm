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


// 6118 숨바꼭질



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> adj[20010];
    int v[20010];

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // bfs 시작
    queue<int> q;
    q.push(1);
    v[1] = 1;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int j = 0; j < adj[cur].size(); j++) {
            int next = adj[cur][j];

            if (v[next] != 0) { continue; }

            v[next] = v[cur] + 1;
            q.push(next);
        }
    }

    

    // 결과 확인
    vector<int> ans;
    int max_distance = 0;
    for (int i = 1; i <= N; i++) {

        if (v[i] == max_distance) {
            ans.push_back(i);
        }

        if (v[i] > max_distance) { 
            ans.clear();
            max_distance = v[i]; 
            ans.push_back(i);
        }


    }
    sort(ans.begin(), ans.end());

    cout << ans[0] << " " << max_distance - 1 << " " << ans.size() << "\n";

    return 0;
}