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

int INF = 0x7F7F7F7F;


// vector< vector< pair<int, int> > > arr;
vector< pair< pair<int, int>, int > > arr;
int Dist[1000];

int N, M;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    N = 4;
    M = 6;

    // 다익스트라와 다른 방식으로 저장해야겠다. 간선을 기준으로 저장해야 함
    // arr.resize(N + 1);
    // arr[1].push_back(make_pair(2, 3));
    // arr[1].push_back(make_pair(3, 2));
    // arr[1].push_back(make_pair(1, 4));
    // arr[2].push_back(make_pair(3, 3));
    // arr[3].push_back(make_pair(4, -4));
    // arr[4].push_back(make_pair(2, -4));

    arr.resize(N+1);
    arr.push_back(make_pair(make_pair(1, 2), 3));
    arr.push_back(make_pair(make_pair(1, 3), 3));
    arr.push_back(make_pair(make_pair(1, 1), 4));
    arr.push_back(make_pair(make_pair(2, 3), 3));
    arr.push_back(make_pair(make_pair(3, 4), -4));
    arr.push_back(make_pair(make_pair(4, 2), -4));

    for (int i = 1; i <= N; i++) {
        Dist[i] = INF;
    }

    bellmanFord(1);
   
    return 0;
}