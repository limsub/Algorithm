#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;
#include <queue>
#include <cstdio>


// 2623 음악 프로그램
// 위상 정렬 + DFS(사이클 유무 확인)

vector< vector<int> > adj(1002);
vector<int> indegree(1002, 0);


// * 사이클 유무 판단 (dfs)
bool visited[1002];
bool dfs(int cur) {

    visited[cur] = true;

    for (int i = 0; i < adj[cur].size(); i++) {

        int next = adj[cur][i];

        if (!visited[next]) {   // 아직 방문하지 않았다면 한 번 더 탐색해서 그 결과 그대로 받아오기
            return dfs(next);
        }
        else {  // 이미 방문한 노드라면 사이클 존재
            cout << "방문!!" << cur << " " << next << "\n";
            return true;
        }
    }

    return false;   // 혹시나 연결된 노드가 없다면 그건 false
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    string s1;  // 첫 엔터 먹게 하기 위함
    cin >> N >> M;
    getline(cin, s1);
    // cout << "******" << "\n";

    

    // 1. 입력
    while (M--) {    
        int cnt;
        cin >> cnt;

        vector<int> singerArr(cnt);

        for (int i = 0; i < cnt; i++) { cin >> singerArr[i]; }
        
        // 1 - 1. 그래프 + indegree 저장
        for (int i = 0; i < singerArr.size() - 1; i++) {
            int x = singerArr[i];
            int y = singerArr[i+1];

            adj[x].push_back(y);
            indegree[y]++;
        }
    }



    // 2. dfs 이용해서 사이클 없는지 확인하기
    for (int i = 1; i <= N; i++) {
        // // 탐색을 하지 않은 노드에 대해서만 시작하면 된다
        // if (visited[i] == true) { continue; }

        for (int j = 1; j <= N; j++) { visited[j] = false; }

        if (dfs(i)) {
            cout << "0" << "\n";
            return 0;
        }
    }
    

    // 3. 위상 정렬 결과 출력
    queue<int> q;
    vector<int> ans;
    // 3 - 1. 들어오는 간선이 없는 노드가 start point
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) { q.push(i); }
    }
    // 3 - 2.
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        ans.push_back(cur);

        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i];

            indegree[next]--;

            if (indegree[next] == 0) { q.push(next); }
        }
    }
    // 3 - 3. 출력
    for (int i = 0; i < N; i++) {
        cout << ans[i] << "\n";
    }





    return 0;
}