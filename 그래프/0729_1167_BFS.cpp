#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>



// 1167
vector< vector< pair<int, int> > > graph;
vector<int> v;
int V;
int maxD;
int maxN;


void BFS(int startNode) {
    //int pnt = 0;

    int pnt[V+1];
    pnt[startNode] = 0;

    queue<int> q;
    q.push(startNode);

    v[startNode] = 1;

    while(!q.empty()) {
        int nextNode = q.front();
        q.pop();

        for (int i = 0; i < graph[nextNode].size(); i++) {
            
            int next2Node = graph[nextNode][i].first;
            int next2NodeCost = graph[nextNode][i].second;

            if (v[next2Node] == 0) {
                q.push(next2Node);
                v[next2Node] = 1;
                pnt[next2Node] = pnt[nextNode] + next2NodeCost;
                //printf("nextNode, next2Node, pnt[next2Node] : %d %d %d\n", nextNode, next2Node, pnt[next2Node]);
            }
        }
    }

    
    for (int i = 1; i <= V; i++) {
        if (pnt[i] > maxD) {
            maxD = pnt[i];
            maxN = i;
        }
    }
}


int main() {

    
    cin >> V;
    maxN = 1;

    // resize
    v.resize(V+1, 0);
    graph.resize(V+1);
    maxD = 0;

    for (int i = 1; i <= V; i++) {
        int x;
        cin >> x;

        while (1) {    
            int node, cost;
            cin >> node;
            if (node == -1) {
                break;
            }
            cin >> cost;

            graph[x].push_back(make_pair(node, cost));
            
        }
    }

    BFS(1);
    fill(v.begin(), v.end(), 0);
    BFS(maxN);


    

    

    // for (int i = 1; i <= V; i++) {
    //     BFS(i);

    //     fill(v.begin(), v.end(), 0);
    // }



    printf("%d", maxD);
    

    return 0;
}
