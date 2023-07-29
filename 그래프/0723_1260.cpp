#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>



// 1260
// 까다로운 점 - 인접한 노드가 여러 개일 때는 작은 노드부터 탐색
// -> 각 vector를 sorting해주면 된다

vector< vector<int> > graph;
vector<int> v;



void DFS(int startNode) {

    printf("%d ", startNode);
    v[startNode] = 1;

    for (int i = 0; i < graph[startNode].size(); i++) {
        int nextNode = graph[startNode][i];

        if (v[nextNode] == 0) {
            DFS(nextNode);
        }
    }
}

void BFS(int startNode) {

    queue<int> q;

    q.push(startNode);
    v[startNode] = 1;

    while(!q.empty()) {
        int nextNode = q.front();
        q.pop();

        printf("%d ", nextNode);

        for (int i = 0; i < graph[nextNode].size(); i++) {
            int nextNode2 = graph[nextNode][i];

            if (v[nextNode2] == 0) {
                q.push(nextNode2);
                v[nextNode2] = 1;
            }
        }


    }
}

int main() {

    int N, M, V;
    cin >> N >> M >> V;

    graph.resize(N+1);
    v = vector<int> (N+1, 0);

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    // sorting
    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    DFS(V);
    printf("\n");
    v = vector<int> (N+1, 0);
    BFS(V);



    return 0;
}
