#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;
#include <queue>


// DFS
void dfs(int start_node, vector< vector<int> >graph, bool *visited) {
    visited[start_node] = true;
    cout << start_node << " ";

    for (int i = 0; i < graph[start_node].size(); i++) {
        int next_node = graph[start_node][i];
        if (!visited[next_node]) {
            dfs(next_node, graph, visited);
        }
    }
}

// BFS
void bfs(int start_node, vector<vector <int> >graph, bool* visited) {
    queue<int> q;
    q.push(start_node);
    visited[start_node] = true;


    while(!q.empty() ) {
        int next_node = q.front();
        q.pop();

        cout << next_node << " ";

        for (int i = 0; i < graph[next_node].size(); i++) {
            int next2_node = graph[next_node][i];
            if (! visited[next2_node]) {
                q.push(next2_node);
                visited[next2_node] = true;
            }
        }
    }
}


int main() {

    int N = 8;
    bool visited[N+1];
    for (int i = 0; i < N+1; i++) {
        visited[i] = false;
    }

    vector< vector<int> > graph(N+1);

    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);

    graph[2].push_back(1);
    graph[2].push_back(7);

    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);

    graph[4].push_back(3);
    graph[4].push_back(5);

    graph[5].push_back(3);
    graph[5].push_back(4);

    graph[6].push_back(7);

    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);

    graph[8].push_back(1);
    graph[8].push_back(7);

    bfs(1, graph, visited);
}