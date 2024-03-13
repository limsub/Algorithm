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
int N;
vector< pair<int, int> > adj[10010];    // (노드, 가중치)
int notLeaf[10010]; // leaf가 아니면 1로 값 변경


int v[10010];
int max_weight;
void dfs(int start, int cur, int weight) {

    // cout << "-- start : " << start << "\n";

    // leaf 도달했으면 max_weight 비교하고 return
    if (cur != start && notLeaf[cur] == 0) {
        if (weight > max_weight) { 
            // cout << "start : " << start << " cur : " << cur << "\n";
            max_weight = weight; 
        }
        return;
    }

    v[cur] = 1;

    for (int j = 0; j < adj[cur].size(); j++) {
        int next_node = adj[cur][j].first;
        int next_weight = adj[cur][j].second;

        if (v[next_node] == 1) { continue; }

        dfs(start, next_node, weight + next_weight);
    }


}

void initV() {
    for (int i = 1; i <= N; i++) { v[i] = 0; }
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

        notLeaf[x] = 1;
    }

    // leaf node들 저장 (dfs 시작)
    vector<int> leaf_nodes;
    for (int i = 1; i <= N; i++) {
        if (notLeaf[i] == 0) { leaf_nodes.push_back(i); }
    }


    // dfs 시작
    for (int i = 0; i < leaf_nodes.size(); i++) {
        int start_node = leaf_nodes[i];

        // cout << "star_node : " << start_node << "\n";

        dfs(start_node, start_node, 0);

        initV();
    }

    cout << max_weight << "\n";


    return 0;
}