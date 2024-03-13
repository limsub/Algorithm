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


// 1967 트리의 지름

// 1. 두 정점 중 하나 찾기
//  - 어느 점에서 출발하더라도, 가장 멀리 있는 점은 두 정점 중 하나
// 2. 해당 정점에서 가장 멀리 떨어저 있는 점 = 나머지 한 정점



int N;
vector< pair<int, int> > adj[10010];  
int v[10010];

int max_weight;
int max_Node;

void dfs(int cur, int weight) {

    if (max_weight < weight) { 
        max_weight = weight;
        max_Node = cur;
    }

    for (int j = 0; j < adj[cur].size(); j++) {
        int next_node = adj[cur][j].first;
        int next_weight = adj[cur][j].second;

        if (v[next_node] == 1) { continue; }

        v[next_node] = 1;
        dfs(next_node, weight + next_weight);
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    

    for (int i = 0; i < N-1; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        adj[x].push_back(make_pair(y, z));
        adj[y].push_back(make_pair(x, z));
    }

    // 임의의 정점(1)에서 가장 멀리 떨어진 정점 확인 (dfs)
    v[1] = 1;
    dfs(1, 0);

    // v 초기화
    fill(v, v + 10010, 0);

    // 해당 정점에서 다시 dfs 시작 -> 거리 확인
    v[max_Node] = 1;
    dfs(max_Node, 0);

    cout << max_weight << "\n";

    return 0;
}