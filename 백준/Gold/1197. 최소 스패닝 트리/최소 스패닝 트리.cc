#include <bits/stdc++.h>
using namespace std;





// 1197 최소 스패닝 트리

// 크루스칼 알고리즘 공부 후, 활용해서 풀기

int V, E;
tuple<int, int, int> edge[100010];   // 간선을 기준으로 가야 하기 때문에 tuple을 사용하는 게 더 좋아보인다.
vector<int> p(10005, -1);

// 1. find - 최종 부모 노드 찾기
int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

// 2. is_diff_group
//  - 이미 서로 같은 최종 부모인지 확인
//  - 서로 다른 부모라면, 그 두 그룹을 합친다.
bool is_diff_group(int u, int v) {
    u = find(u); v = find(v);

    // 최종 부모가 같다면
    if (u == v) return false;

    // 다르다면 합친다. 만약 p가 서로 같다면, p[u]를 줄여서, u가 부모가 될 수 있게 한다
    if (p[u] == p[v]) p[u]--;
    
    if (p[u] < p[v]) p[v] = u;
    else p[u] = v;

    return true;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    // 1. 입력
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int x, y, cost; cin >> x >> y >> cost;

        edge[i] = {cost, x, y};
    }

    // 2. 정렬
    sort(edge, edge + E);

    // 3. Kruskal Algorithm
    int cnt = 0;
    int ans = 0;

    for (int i = 0; i < E; i++) {
        int x, y, cost;
        tie(cost, x, y) = edge[i];

        // 만약 같은 그룹에 있다면 -> 연결하지 않는다.
        if (!is_diff_group(x, y)) continue;

        // 다른 그룹이라면
        ans += cost;
        cnt++;

        // 최소 신장 트리의 간선 = 노드 - 1
        if (cnt == V-1) break;  
    }

    cout << ans;

    return 0;
}