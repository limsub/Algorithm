#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;
#include <queue>
#include <cstdio>


// 2252 줄 세우기
// 위상 정렬

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector< vector<int> > adj(N+1, vector<int>());
    vector<int> indegree(N+1, 0);
    
    // 1. 방향 입력
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);    // x -> y 방향
        indegree[y] ++;         // y로 들어오는 간선 추가
    }


    // 2. 위상 정렬 + 방문한 순서 배열 저장
    vector<int> ans;    
    queue<int> q;
    // 2 - 1. 들어오는게 없는 노드 먼저 큐에 추가
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) { q.push(i); }
    }
    // 2 - 2. 
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        ans.push_back(cur);

        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i];

            // cur 방문을 했기 때문에 cur에서 나가는 간선은 의미가 없어짐
            indegree[next]--;

            if (indegree[next] == 0) { q.push(next); }
        }
    }


    // 3. 정답 출력
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}