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


// 20955 민서의 응급 수술
// 5% 틀.

int N, M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    vector< vector<int> > adj(N+1);

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }


    int graph_cnt = 0;  // 분리된 그래프들의 개수 (합치는 연산 이용할 예정)
    int cycle_cnt = 0;  // 각 그래프에 있는 사이클의 개수 (끊는 연산 이용할 예정)

    // bfs 돌면서 그래프의 개수와 각 그래프에 있는 사이클 개수(edges > N-1) 를 파악한다
    vector<int> v(N+1);
    for (int i = 1; i <= N; i++) {

        if (v[i] == 0) {
            graph_cnt++;    // 그래프 개수 추가

            queue<int> q;
            q.push(i);
            v[i] = 1;

            set<int> vertice;   // 그래프에 포함된 vertices
            vertice.insert(i);

            // bfs 시작
            while(!q.empty()) {
                int cur = q.front();
                q.pop();
                

                for (int j = 0; j < adj[cur].size(); j++) {
                    int next = adj[cur][j];

                    if (v[next] == 1) { continue; }

                    vertice.insert(next);
                    v[next] = 1;
                    q.push(next);
                }
            }

            int edge_cnt = 0;   // 그래프에 포함된 edge 개수
            for (auto v: vertice) {
                edge_cnt += adj[v].size();  // 각 vertice의 간선 개수
            }
            edge_cnt /= 2;

            cycle_cnt += edge_cnt - (vertice.size() - 1);   // N, N-1이어야 사이클이 없다.
        }
    }

    cout << cycle_cnt + graph_cnt - 1 << "\n";



    return 0;
}