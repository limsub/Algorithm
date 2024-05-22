#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;
#include <queue>
#include <cstdio>


// 20955 민서의 응급 수술
// 5% 틀.

int N, M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 입력
    cin >> N >> M;

    vector<int> p(N+1, 0);
    vector< vector<int> > adj(N+1, vector<int>() );
    
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // // 2. p[i] == 0인 i의 개수
    // int ans = -1;   // 최종 root 노드 고려
    // for (int i = 1; i <= N; i++) {
    //     if (p[i] == 0) { ans ++; }
    // }


    // 2. bfs 돌면서 p[] 설정
    
    vector<int> v(N+1);
    for (int i = 1; i <= N; i++) {

        if (v[i] == 0) {

            queue<int> q;
            q.push(i);

            while(!q.empty()) {
                int cur = q.front();
                q.pop();
                v[cur] = 1;

                for (int j = 0; j < adj[cur].size(); j++) {
                    int next = adj[cur][j];

                    if (v[next] == 1) { continue; }

                    p[next] = cur;  // p 설정

                    q.push(next);
                }

            }



        }

    }

    // 3. p[i] == 0 인 i 의 개수
    int ans = -1;
    for (int i = 1; i <= N; i++) {
        if (p[i] == 0) { ans++; }
    }



    // 3. 출력
    cout << ans << "\n";

    return 0;
}