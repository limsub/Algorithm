#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>

// 11724
// DFS처럼 재귀함수 사용하는 것들은 웬만하면 전역변수 사용하자


vector< vector<int> > graph;
int cnt;
int v[10001];

void DFS(int start_node) {

    if (v[start_node] == 1) {
        return;
    }

    v[start_node] = 1;

    for (int i = 0; i < graph[start_node].size(); i++) {
        int next_node = graph[start_node][i];
        
        if (v[next_node] == 0) {
            DFS(next_node);
        }
    }

    
}

int main() {

    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        v[i] = 0;
    }
    graph.resize(N+1);
    cnt = 0;

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        //printf("1 , 2\n");

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i < N+1; i++) {
        if (v[i] == 0) {
            //printf("dfs 실행 %d\n", i);
            DFS(i);
            cnt++;
        }
    }

    printf("%d\n", cnt);
    return 0;
}
