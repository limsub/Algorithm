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
// 6% fail



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    vector<string> ans_str(T);


    for (int testIdx = 0; testIdx < T; testIdx++) {
        int N, M;
        cin >> N >> M;

        vector<int> adj[20010];
        int v[20010];

        // 그래프 입력
        for (int i = 0; i < M; i++) {
            int x, y; cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        // bfs 
        // - v[i]가 0이면 아직 탐색 x => 현재 v와 다른 값으로 저장
        // - v[i]가 같은 값이면 분리 불가능 => NO 출력
        for (int i = 1; i <= N; i++) {

            if (v[i] != 0) { continue; }

            queue<int> q;
            q.push(i);
            v[i] = 1;


            // queue<int> q;
            // q.push(1);
            // v[1] = 1;

            while (!q.empty()) {
                int cur = q.front(); q.pop();

                for (int j = 0; j < adj[cur].size(); j++) {
                    int next = adj[cur][j];

                    // cout << "cur : " << cur << " next : " << next << " v[cur] : " << v[cur] << " v[next] : " << v[next] << "\n";

                    // 만약 v가 cur와 동일하다면, 이분 그래프가 될 수 없다.
                    if (v[cur] == v[next]) { 
                        // cout << "99999" << "\n";
                        ans_str[testIdx] = "NO";
                        break;
                    }

                    if (v[next] != 0) { continue; }

                    v[next] = (v[cur] == 1) ? 2 : 1;
                    q.push(next);
                }
            }
        }


        if (ans_str[testIdx] != "NO") { 
            // cout << " - textIdx : " << testIdx << " - ans_str[testIdx] : " << ans_str[testIdx] << "\n";
            ans_str[testIdx] = "YES"; 
        }
    

    }

    for (int testIdx = 0; testIdx < T; testIdx++) {
        // cout << "testIdx : " << testIdx << "\n";
        cout << ans_str[testIdx] << "\n";
    }


    return 0;
}