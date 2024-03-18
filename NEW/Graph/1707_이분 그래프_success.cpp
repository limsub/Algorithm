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


// 1707 이분 그래프
// 바킹독 풀이

int T, N, M;
int v[20010];
vector<int> adj[20010];

bool solve() {

    // v 배열 초기화 - 초기값 모두 -1
    fill(v, v + N + 1, -1);

    // 모든 정점에 대한 bfs (분리된 그래프 대비)
    for (int i = 1; i <= N; i++) {
        if (v[i] != -1)  { continue; }

        queue<int> q;
        q.push(i);
        v[i] = 0;

        while(!q.empty()) {
            int cur = q.front(); q.pop();

            for (int j = 0; j < adj[cur].size(); j++) {
                int next = adj[cur][j];

                // 뭐가 있을 때
                if (v[next] != -1) { 
                    // 만약 같은거라면, false
                    if (v[next] == v[cur]) { return false; }
                    else { continue; }
                }

                // v[next] 가 -1인 경우 (아직 탐색하지 않은 정점인 경우)
                v[next] = (v[cur] == 0) ? 1 : 0;
                q.push(next);


                /* === 내가 시도한 코드 === */
                // if (v[cur] == v[next]) { 
                //     ans_str[testIdx] = "NO";
                //     break;
                // }

                // if (v[next] != 0) { continue; }

                // v[next] = (v[cur] == 1) ? 2 : 1;
                // q.push(next);
            }
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int T;
    cin >> T;

    while (T--) {
        cin >> N >> M;

        // adj 배열 초기화 (N만큼만 필요하기 때문에 그 이후는 신경쓰지 않는다)
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
        }

        // 그래프 입력
        int x, y;
        while(M--) {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        if (solve()) { cout << "YES\n"; }
        else { cout << "NO\n";}
    }

    return 0;
}