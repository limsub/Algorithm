#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>

#define INF 999999

// Dijkstra
void Dijkstra_search(vector< vector <pair<int, int> > > v, int start_node, int total_num) {
    priority_queue<pair <int, int> >PQ;
    PQ.push(make_pair(0, start_node));
    vector<int> Dist(total_num+1,  INF);
    

    Dist[start_node] = 0;

    while (!PQ.empty()) {
        // priority queue에는 (cost, node) 순서
        // vector에는 (node, cost) 순서
        int cost = -PQ.top().first;
        int cur = PQ.top().second;
        PQ.pop();

        // queue에서 뽑은 노드의 인접한 노드 방문
        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int ncost = v[cur][i].second;

            // 기존보다 더 적은 cost가 나오면 바꿔주기
            if (Dist[next] > cost + ncost) {
                Dist[next] = cost + ncost;
                // - 붙여서 넣어줘야 가장 낮은 cost가 가장 비싼 cost가 되면서 먼저 큐에서 나온다
                PQ.push(make_pair(-Dist[next], next));
            }
        }
    }

    for (int i = 1; i <= total_num; i++) {
        cout << "Dist" << i << " : " << Dist[i] << endl;
    }
}

int main() {

    // pair(next node 이름, cost)
    vector< vector<pair<int, int> > > v(7);
    v[1].push_back(make_pair(2, 4));
    v[1].push_back(make_pair(3, 2));
    v[2].push_back(make_pair(1, 4));
    v[2].push_back(make_pair(4, 4));
    v[3].push_back(make_pair(1, 2));
    v[3].push_back(make_pair(5, 4));
    v[4].push_back(make_pair(2, 4));
    v[4].push_back(make_pair(6, 1));
    v[5].push_back(make_pair(2, 5));
    v[5].push_back(make_pair(3, 4));
    v[5].push_back(make_pair(6, 2));
    v[6].push_back(make_pair(4, 1));
    v[6].push_back(make_pair(5, 2));

    Dijkstra_search(v, 1, 6);




    return 0;
}