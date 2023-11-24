#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <cmath>
#include <set>
using namespace std;
#include <string.h>
// #include <bits/stdc++.h>

// 1916 최소비용 구하기
// 단순 다익스트라?

// 15% 시간초과?
// 조건 추가 (Cost < Dist[node], node == endNode) -> 17% 시간초과

#define INF 0x7F7F7F7F;

int N, M;
vector< vector< pair<int, int> > > arr;
int startNode, endNode;
int Dist[1001] = {0, };

void dijkstra() {

    // 작은 것부터 빼기 위한 우선순위 큐
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;

    pq.push(make_pair(0, startNode));
    Dist[startNode] = 0;

    while (!pq.empty()) {
        // 가장 거리가 짧은 노드 방문
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        // Dist에 저장된 값을 기준으로 해야 해 (이걸 넣고난 이후에 다른 노드로 인해 Dist가 더 줄어들었을 수도 있다)
        if (Dist[curNode] < curCost) { continue; }

        if (curNode == endNode) { continue; }

        // 인접 노드 방문
        for (int i = 0; i < arr[curNode].size(); i++) {
            int nextNode = arr[curNode][i].first;
            int nextCost = arr[curNode][i].second;

            // 비교해서 현재가 더 좋은 경로이면 교체
            if (Dist[nextNode] > nextCost + Dist[curNode]) {
                Dist[nextNode] = nextCost + Dist[curNode];
                pq.push(make_pair(Dist[nextNode], nextNode));
            }
        }
    }
    cout << Dist[endNode] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력
    cin >> N >> M;
    arr.resize(N+1);
    for (int i = 0; i < M; i++) {
        int x, y, z;
        
        cin >> x >> y >> z;
        arr[x].push_back(make_pair(y, z));
    }
    cin >> startNode >> endNode;
    // printf("입력 완료\n");

    // 초기화
    for (int i = 1; i <= N; i++) {
        Dist[i] = INF;
    }

    dijkstra();
    
    return 0;
}