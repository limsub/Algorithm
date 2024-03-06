#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;
#include <queue>
#include <cstdio>


// 2637 장난감 조립


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    int dp[101][101];
    vector< vector< pair<int, int> > > adj(101);    // nextNode, cost

    int indegree[101];
    int isBase[101];    // 기본 부품인지 확인하기 위한 배열. 기본 부품이라면 값이 1
    vector<int> baseElement;    // 기본 부품 저장


    int N;
    cin >> N;

    int M;
    cin >> M;
    while (M--) {
        int x, y, k;
        cin >> x >> y >> k;

        // x로 가려면 y가 k개 필요해
        adj[y].push_back(make_pair(x, k));

        // indegree에는 동일한게 몇개 필요한지는 관계x. 
        indegree[x]++;
    }


    // 위상정렬 + DP
    queue<int> q;
    // - 1.
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) { 
            isBase[i] = 1;  // 기본 부품이라는 뜻
            baseElement.push_back(i);
            q.push(i); 
        }
    }
    // - 2.
    while(!q.empty()) { 
        int cur = q.front();
        q.pop();

        for (int j = 0; j < adj[cur].size(); j++) {
            int next = adj[cur][j].first;
            int cnt = adj[cur][j].second;

            // cur가 기본 부품인 경우
            dp[next][cur] += cnt;

            // cur가 중간 부품인 경우 - cur가 가진 모든 기본 부품들 * cnt
            for (int k = 0; k < baseElement.size(); k++) {
                int baseE = baseElement[k];

                dp[next][baseE] += dp[cur][baseE] * cnt;
            }

            indegree[next]--;

            if (indegree[next] == 0) { q.push(next); }
        }
    }

    for (int i = 0; i < baseElement.size(); i++) {
        cout << baseElement[i] << " ";
        cout << dp[N][baseElement[i]] << "\n";
    }
    

    return 0;
}