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


// 1238 파티
// 다익스트라

int N, M, X;
vector< vector< pair<int, int> > > arr;

int INF = 0x7F7F7F7F;


int Dijkstra(int start, int end) {

    priority_queue< pair<int, int> > pQ;
    vector<int> dist(N+1, INF);

    pQ.push(make_pair(0, start));
    dist[start] = 0;

    while (!pQ.empty()) {

        int cost = -pQ.top().first;
        int cur = pQ.top().second;
        pQ.pop();

        for (int i = 0; i < arr[cur].size(); i++) {
            int nextCost = cost + arr[cur][i].first;
            int nextCur = arr[cur][i].second;

            if (dist[nextCur] > nextCost) {
                dist[nextCur] = nextCost;
                pQ.push(make_pair(-dist[nextCur], nextCur));
            }   
        }
    }

    return dist[end];
}

int main() {

    cin >> N >> M >> X;
    arr.resize(N+1);

    for (int i = 0; i < M; i++) {
        int x, y, cost;
        cin >> x >> y >> cost;

        arr[x].push_back(make_pair(cost, y));
    }

    // 최단 거리를 저장할 배열
    vector<int> ansArr(N+1);

    // X로 가는거
    for (int i = 1; i <= N; i++) {
        ansArr[i] = Dijkstra(i, X) + Dijkstra(X, i);
    }

    // 최댓값 찾기
    int max = -1;
    for (int i = 1; i <= N; i++) {
        if (ansArr[i] > max) {
            max = ansArr[i];
        }
    }

    cout << max << endl;

    return 0;
}