#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;
#include <queue>
#include <cstdio>





// 1005
// ACM CRAFT 
// 위상 정렬 + DP

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    
    
    int T;
    cin >> T;
    // scanf("%d", &T);

    while(T--) {
        int N, K;
        cin >> N >> K;
        int target_point;

        vector<int> dp(N+1);    // dp
        vector<int> bt(N+1);    // build time
        vector< vector<int> > v(N+1, vector<int>());    // graph
        vector<int> indegree(N+1, 0);    // topological sorting


        // 1. build time 입력
        for (int i = 1; i <= N; i++) {
            cin >> bt[i];
        }


        // 2. graph, indegree 입력
        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;

            v[x].push_back(y);  // graph
            indegree[y]++;      // indegree
        }


        // 3. target point 입력
        cin >> target_point;


        // 4. topological sorting
        queue<int> q;
        for (int i = 1; i <= N; i++) {
            // 자신한테 들어오는 edge가 없으면 start_point
            if (indegree[i] == 0) { q.push(i); }
        }

        while (!q.empty()) {

            int cur = q.front();
            q.pop();

            for (int i = 0; i < v[cur].size(); i++) {
                int next = v[cur][i];

                dp[next] = max(dp[next], dp[cur] + bt[cur]);

                // cout << "next : " << next << "  " <<  "dp : " << dp[next] << "\n";

                
                indegree[next]--;

                if (indegree[next] == 0) { q.push(next); }
            }
        }

        cout << dp[target_point] + bt[target_point] << "\n";
    }

    return 0;
}