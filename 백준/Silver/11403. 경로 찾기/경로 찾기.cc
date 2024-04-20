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
#include <map>
// #include <pair>
// #include <bits/stdc++.h>

int adj[102][102];
int v[102];

int ans[102][102];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int N; cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> adj[i][j];
        }
    }

    // i = 0 부터 i = N-1까지 따로...?

    for (int i = 0; i < N; i++) {
        int start = i;

        fill(v, v + N, 0);

        queue<int> q;
        q.push(start);
        // v[start] = 1;
        // ans[start][start] = 1;

        while (!q.empty()) {
            int cur = q.front(); q.pop();

            // cout << "cur : " << cur << "\n";

            for (int j = 0; j < N; j++) {
                // cur에서 직접 탐색이 가능한 곳을 확인한다.
                if (adj[cur][j] != 1) continue;

                int next = j;

                // cout << "next : " << next << "\n";

                if (v[next]) continue;

                q.push(next);
                v[next] = 1;    // v가 꼭 필요한가 싶다.

                ans[i][next] = 1;   // 여기서 걸린다는 건, i에서 탐색이 가능하다는 뜻.
            }
        }
    }

    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }






    return 0;
}