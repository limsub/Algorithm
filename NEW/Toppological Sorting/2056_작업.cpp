#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;
#include <queue>
#include <cstdio>


// 2056 작업
// 위상정렬 + DP
// 4% 틀

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 0. 변수
    int N;
    cin >> N;


    // 1. 입력
    vector< vector<int> > adj(N+1, vector<int>());
    vector<int> timeArr(N+2);
    vector<int> indegree(N+1);
    vector<int> dp(N+1);

    for (int i = 1; i <= N; i++) {
        cin >> timeArr[i];

        int prevCnt;
        cin >> prevCnt;

        for (int j = 0; j < prevCnt; j++) {
            int prevNode;
            cin >> prevNode;
            adj[prevNode].push_back(i);
            indegree[i]++;
        }
    }

    
    // 2. 위상정렬 + DP
    queue<int> q;
    // 2 - 1. 선행 관계가 없는 노드들 큐에 삽입
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) { q.push(i); }
    }
    // 2 - 2. 탐색
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int j = 0; j < adj[cur].size(); j++) {
            int next = adj[cur][j];

            dp[next] = max(dp[next], dp[cur] + timeArr[cur]);

            indegree[next]--;

            if (indegree[next] == 0) { q.push(next); }
        }
    }

    
    // 3. 출력
    // cout << dp[N] + timeArr[N];

    int max = -1;
    for (int i = 1; i <= N; i++) {
        if (dp[i] + timeArr[i] > max) { 
            max = dp[i] + timeArr[i];
        }
    }

    cout << max;

    return 0;
}