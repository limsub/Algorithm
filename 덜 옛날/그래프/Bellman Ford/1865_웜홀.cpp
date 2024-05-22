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

// 1865 웜홀
// 2% 틀

int INF = 0x7F7F7F7F;
int T;

vector< pair< pair<int, int>, int > > arr;
// int Dist[1000];

int N, M;

bool bellmanFord(int N, int M, int W) {
    // int Dist[1000];
    // for (int i = 0; i < N+1; i++) {
    //     Dist[i] = INF;
    // }

    vector<int> Dist(N+1, INF);
    
    Dist[1] = 0;

    for (int i = 0; i < N-1; i++) {

        for (int j = 0; j < arr.size(); j++) {
            int x = arr[j].first.first;
            int y = arr[j].first.second;
            int z = arr[j].second;

            // if (Dist[x] == INF) { continue; }

            if (Dist[y] > Dist[x] + z) { 
                Dist[y] = Dist[x] + z;
            }
        }
    }

    for (int j = 0; j < arr.size(); j++) {
        int x = arr[j].first.first;
        int y = arr[j].first.second;
        int z = arr[j].second;

        // if (Dist[x] == INF) { continue; }

        if (Dist[y] > Dist[x] + z) { 
            return false;
        }
    }
    return true;
}

/*
void bellmanFord(int start) {

    Dist[1] = 0;

    // N - 1번 탐색
    for (int i = 0; i < N-1; i++) {

        // 간선의 개수(M)를 다 도는게 한 번 
        for (int j = 0; j < arr.size(); j++) {
            int x = arr[j].first.first;
            int y = arr[j].first.second;
            int z = arr[j].second;

            if (Dist[x] == INF) { continue; }
            
            if (Dist[y] > Dist[x] + z) { 
                Dist[y] = Dist[x] + z;
            }

        } 
    }

    // 마지막 한 번 더 탐색 (음의 사이클이 있는지 확인)
    for (int j = 0; j < arr.size(); j++) {
        int x = arr[j].first.first;
        int y = arr[j].first.second;
        int z = arr[j].second;

        if (Dist[x] == INF) { continue; }
        if (Dist[y] > Dist[x] + z) {
            cout << "음의 사이클이 존재합니다" << "\n";
            return;
        } 
    }

    cout << "음의 사이클이 없는, 정상적인 그래프입니다" << "\n";

}
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--) {
        int N, M, W;
        cin >> N >> M >> W;

        for (int i = 0; i < M; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            
            arr.push_back(make_pair( make_pair(x, y), z));
            arr.push_back(make_pair( make_pair(y, x), z));
        }
        for (int i = 0; i < W; i++) {
            int p, q, r;
            cin >> p >> q >> r;

            arr.push_back(make_pair( make_pair(p, q), -r));
        }

        // 모든 간선을 출발점으로 치고, 벨만 포드 실행. 단 하나라도 음의 사이클이 존재하면 break
        if (bellmanFord(N, M, W)) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
        }

        arr.clear();
    }

    
    
    return 0;
}