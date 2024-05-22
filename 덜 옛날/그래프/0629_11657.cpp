#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>

#define INF 1410065408

// Bellman_Ford
void Bellman_Ford(vector<vector<pair<int, int> > > v, int start_node, int total_num) {
    vector<long long> Dist(total_num + 1, INF);
    Dist[start_node] = 0;

    // 방향이 있는 그래프라고 가정하면, edge의 개수는 저장한 pair의 개수와 동일
    int edge_cnt = 0;
    for (int i = 1; i <= total_num; i++) {
        edge_cnt += v[i].size();
    }
    //cout << edge_cnt << endl;


    // N-1번 탐색
    for (int i = 1; i <= total_num-1; i++) {
        // edge 탐색 (v개수 + v[i].size())
        for (int j = 1; j <= total_num; j++) {
            for (int k = 0; k < v[j].size(); k++) {
                // printf("%d %d\n", j, k);
                // edge의 정보
                int from = j;
                int to = v[j][k].first;
                int cost = v[j][k].second;

                // 시작점이 한번이라도 계산된 노드가 아니면 pass
                if (Dist[from] == INF)  continue;

                // 시작점까지의 cost + 시작점-도착점 cost vs. 기존 도착점까지의 cost
                if (Dist[to] > Dist[from] + cost) {
                    Dist[to] = Dist[from] + cost;
                }
            }
        }
    }

    // N-1번 탐색 이후 또 변하면, 음의 사이클이 존재하는 그래프
    for (int j = 0; j < total_num; j++) {
        for (int k = 0; k < v[j].size(); k++) {
            int from = j;
            int to = v[j][k].first;
            int cost = v[j][k].second;

            if (Dist[from] == INF)  continue;

            if (Dist[to] > Dist[from] + cost) {
                printf("-1");
                //printf("음의 사이클이 존재하는 그래프입니다\n");
                return;
            }
        }
    }

    //printf("음의 사이클이 존재하지 않는, 정상적인 그래프입니다\n");
    for (int i = 2; i <= total_num; i++) {
        if (Dist[i] != INF) {
            cout << Dist[i] << endl;
        }
        else {
            cout << -1 << endl;
        }
        
    }

}

int main() {

    int N, M;
    scanf("%d %d", &N, &M);
    vector< vector< pair<int, int> > > v(N + 1);
    for (int i = 0; i < M; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        v[x].push_back(make_pair(y, z));
    }

    Bellman_Ford(v, 1, N);
    


    return 0;
}