#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long

// 1646 도시 분할 계획

// Minimum Spanning Tree

// 두 개의 분리된 마을로 분할
// 각 마을은 MST를 만족.

// 1. 일반적인 방법으로 MST 찾기
// 2. MST에 포함된 간선 중 가장 cost가 큰 것 빼주기.

int V, E;
tuple<int, int, int> edge[1000010];
vector<int> p(100010, -1);

// 1. find - 최종 부모 노드 찾기
int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

// 2. is_diff_group
// - 이미 같은 최종 부모를 가지고 있으면 false
// - 그렇지 않으면, 부모를 합치고 true
bool is_diff_group(int x, int y) {
    x = find(x); y = find(y);

    if (x == y) return false;

    if (p[x] == p[y]) p[x]--;

    if (p[x] < p[y]) p[y] = x;
    else p[x] = y;

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
    int max_cost = -1;

    for (int i = 0; i < E; i++) {
        int x, y, cost;
        tie(cost, x, y) = edge[i];

        // 이미 같은 그룹이라면 패스
        if (!is_diff_group(x, y)) continue;

        // 다른 그룹이라면 포함 (is_diff_group에서 union 완료)
        ans += cost;
        cnt++;
        max_cost = max(max_cost, cost);

        // MST의 간선 = 노드 - 1
        if (cnt == V-1) break;
    }

    cout << ans - max_cost;


    return 0;
}