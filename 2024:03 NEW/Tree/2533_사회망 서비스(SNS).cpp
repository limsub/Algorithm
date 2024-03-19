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


// 2533 사회망 서비스 (SNS)

int N;
vector<int> adj[1000010];

int dp[1000010][2]; 
// [0] : i가 EA라면 i가 루트일 때의 트리에서 최소 EA 수
// [1] : i가 EA가 아니라면 i가 루트일 때의 트리에서 최소 EA 수

int v[1000010];

void dfs(int cur) {
    v[cur] = 1;

    // 만약 자식이 하나도 없는 노드라면, [0] = 1. [1] = 0
    if (adj[cur].empty()) { dp[cur][0] = 1; dp[cur][1] = 0; return; }

    // 자식이 있다면, dfs 들어가
    else {

        for (int j = 0; j < adj[cur].size(); j++) {
            int next = adj[cur][j];

            if (v[next] == 1) { continue; }

            dfs(next);  // 들어가서 dp[next] 값을 받아옴

            dp[cur][0] += min(dp[next][0], dp[next][1]);
            dp[cur][1] += dp[next][0];
        }

        dp[cur][0] += 1;    // 본인이 EA인 것도 카운트해야 함.
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> N;

    for (int i = 0; i < N-1; i++) {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // 트리이기 때문에 시작 지점을 내 임의로 잡을 수 있다 -> root node로 간주한다
    dfs(1);

    cout << min(dp[1][0], dp[1][1]) << "\n";

    return 0;
}