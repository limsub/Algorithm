#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;
#include <stdio.h>

#include <queue>
#include <cmath>

#include <set>

// 1753 최단 경로
// 최단 경로는 일단 다익스트라 넣어보자

// 2% 시간 초과 -> 다익스트라에서 뭘 수정해야 할까
// 방문 처리??

// cin, cout 을 scanf, printf로 바꾸니까 해결됐다....


int INF = 2147000000;

int V, E;
int start;

int dist[20001];

vector< vector< pair<int, int> > > arr;

void dijkstra() {
    // priority_queue< pair<int, int> > pQ;
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pQ;
    // int v[20001] = {0, };
    
    pQ.push(make_pair(0, start));
    dist[start] = 0;


    while (!pQ.empty()) {
        // 가장 cost 낮은 노드부터 탐색
        int curCost = pQ.top().first;
        int curNode = pQ.top().second;
        pQ.pop();

        // printf("%d와 인접 노드 확인===\n", curNode);

        // // 방문 처리 (?)
        // if (v[curNode] == 1) { continue; }
        // v[curNode] = 1;

        // 최단 거리가 아닌 경우 스킵
        // if (dist[curNode] < curCost) { continue; }

        

        // 인접 노드 확인
        for (int j = 0; j < arr[curNode].size(); j++) {
            int nextNode = arr[curNode][j].second;
            int newCost = curCost + arr[curNode][j].first;

            // printf("====node : %d  cost : %d\n", nextNode, newCost);
            
            // 저장된 거리가 더 클 때 업데이트
            if (dist[nextNode] > newCost) {
                // printf("===업데이트\n");
                dist[nextNode] = newCost;
                pQ.push(make_pair(newCost, nextNode));
            }
        }
    }
}

int main() {

    // cin >> V >> E >> start;
    scanf("%d %d\n", &V, &E);
    scanf("%d\n", &start);
    arr.resize(V+1);
    
    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
    }


    for (int i = 0; i < E; i++) {
        int x, y, cost;
        // cin >> x >> y >> cost;
        scanf("%d %d %d\n", &x, &y, &cost);

        arr[x].push_back(make_pair(cost, y));
    }

    dijkstra();

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) {
            // cout << "INF" << endl;
            printf("INF\n");
        }
        else {
            // cout << dist[i] << endl;
            printf("%d\n", dist[i]);
        }
        
    }

}








// // 1238 파티
// // 다익스트라

// int N, M, X;
// vector< vector< pair<int, int> > > arr;

// int INF = 0x7F7F7F7F;


// int Dijkstra(int start, int end) {

//     priority_queue< pair<int, int> > pQ;
//     vector<int> dist(N+1, INF);

//     pQ.push(make_pair(0, start));
//     dist[start] = 0;

//     while (!pQ.empty()) {

//         int cost = -pQ.top().first;
//         int cur = pQ.top().second;
//         pQ.pop();

//         for (int i = 0; i < arr[cur].size(); i++) {
//             int nextCost = cost + arr[cur][i].first;
//             int nextCur = arr[cur][i].second;

//             if (dist[nextCur] > nextCost) {
//                 dist[nextCur] = nextCost;
//                 pQ.push(make_pair(-dist[nextCur], nextCur));
//             }   
//         }
//     }

//     return dist[end];
// }

// int main() {

//     cin >> N >> M >> X;
//     arr.resize(N+1);

//     for (int i = 0; i < M; i++) {
//         int x, y, cost;
//         cin >> x >> y >> cost;

//         arr[x].push_back(make_pair(cost, y));
//     }

//     // 최단 거리를 저장할 배열
//     vector<int> ansArr(N+1);

//     // X로 가는거
//     for (int i = 1; i <= N; i++) {
//         ansArr[i] = Dijkstra(i, X) + Dijkstra(X, i);
//     }

//     // 최댓값 찾기
//     int max = -1;
//     for (int i = 1; i <= N; i++) {
//         if (ansArr[i] > max) {
//             max = ansArr[i];
//         }
//     }

//     cout << max << endl;

//     return 0;
// }