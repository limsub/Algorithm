#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long
#define INF 0x3F3F3F3F // INF + INF 연산할 일이 생길 수 있기 때문에 7로 안했다.


vector<int> arr[510];
int v[510];

int n, m; 

void bfs(int s) {
    queue<int> q;
    q.push(s);
    v[s] = 1;

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int i = 0; i < arr[cur].size(); i++) {
            int next = arr[cur][i];

            if (v[next]) continue;

            q.push(next);
            v[next] = v[cur] + 1;
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }


    bfs(1);

    int ans = 0;
    for (int i = 1; i < n + 1; i++) {
        if (v[i] <= 3 && v[i] != 0) ans++;
    }

    cout << ans - 1;




    return 0;
}

