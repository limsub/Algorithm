#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>

#include <set>


// 1504 특정한 최단 경로
// 다익스트라.

// 75% 틀. 시간 초과 날거라고 생각했는데, 그것도 아니고 은근 많이 간다
// Int 최댓값 설정 잘 하고 최댓값에 대한 예외처리 해주기

int N, E;
int v1, v2;

vector< vector< pair<int, int> > > arr;

int INF = 0x7FFFFFF;

int Dijkstra(int start, int end) {

    priority_queue< pair<int, int> > pQ;
    pQ.push(make_pair(0, start));

    vector<int> d(N+1, INF);
    d[start] = 0;

    while(!pQ.empty()) {
        int cost = - pQ.top().first;
        int cur = pQ.top().second;
        
        pQ.pop();

        for (int i = 0; i < arr[cur].size(); i++) {
            int next = arr[cur][i].first;
            int nCost = arr[cur][i].second;

            if (d[next] > cost + nCost) {
                d[next] = cost + nCost;

                pQ.push(make_pair(-d[next], next));
            }
        }
    }

    
    return (d[end] >= INF) ? -1 : d[end];
}

int main() {

    cin >> N >> E;

    arr.resize(N+1);
    

    for (int i = 0; i < E; i++) {
        int x, y, cost;
        cin >> x >> y >> cost;

        arr[x].push_back(make_pair(y, cost));
        arr[y].push_back(make_pair(x, cost));
    }

    cin >> v1 >> v2;

    

    int ans1 = Dijkstra(1, v1) + Dijkstra(v1, v2) + Dijkstra(v2, N);
    if (Dijkstra(1, v1) == -1 || Dijkstra(v1, v2) == -1 || Dijkstra(v2, N) == -1 ) {
        ans1 = -1;
    }

    int ans2 = Dijkstra(1, v2) + Dijkstra(v2, v1) + Dijkstra(v1, N);
    if (Dijkstra(1, v2) == -1 || Dijkstra(v2, v1) == -1 || Dijkstra(v1, N) == -1 ) {
        ans2 = -1;
    }


    int realAns;

    if (ans1 != -1 && ans2 != -1 ) {
        realAns = (ans1 > ans2) ? ans2 : ans1;
    }
    if (ans1 == -1) { realAns = ans2; }
    if (ans2 == -1) { realAns = ans1; }
    
    cout << realAns << endl;

    return 0;
}