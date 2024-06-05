#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long

// 24116 본선 회장 (Finals)

// Minimum Spanning Tree

// K개의 도시 지정. -> MST에서 최댓값부터 간선 2개 빼면 됨.


int V, E, K;
tuple<int, int, int> edge[100010];  // 간선 저장 (sort 예정)
vector<int> p(100010, -1);  // 직접적인 부모 저장

// 1. 최종 부모 찾기
int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

// 2. 부모 합치기 (이미 같으면 false)
bool is_diff_p(int x, int y) {
    x = find(x); y = find(y);

    // - 1). 이미 같은 부모
    if (x == y) return false;

    // - 2). 다른 부모
    if (p[x] == p[y]) p[x]--;   // p[x]를 낮춰서 얘가 부모가 될 수 있게끔 한다

    if (p[x] < p[y]) p[y] = x;
    else p[x] = y;

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    // 1. 입력
    cin >> V >> E >> K;
    for (int i = 0; i < E; i++) {
        int x, y, cost; cin >> x >> y >> cost;
        edge[i] = {cost, x, y};
    }


    // 2. 정렬
    sort(edge, edge + E);


    // 3. Kruskal Algorithm
    int cnt = 0;
    int ans = 0;
    vector<int> mst_cost;   // MST에 들어가는 cost 저장 (가장 큰 K-1개 뺄 예정)

    for (int i = 0; i < E; i++) {
        int x, y, cost;
        tie(cost, x, y) = edge[i];

        // - x와 y의 최종 부모가 같으면 continue
        // - 다르면 합치고, ans에 cost 더해줌
        if (!is_diff_p(x, y)) continue;

        ans += cost;
        cnt ++;
        mst_cost.push_back(cost);

        if (cnt == V-1) break;
    }

    
    // 4. 가장 큰 K-1개의 cost를 빼준다.
    sort(mst_cost.begin(), mst_cost.end(), greater());
    for (int i = 0; i < K-1; i++) {
        ans -= mst_cost[i];
    }

    // 5. ans 출력
    cout << ans;
}
