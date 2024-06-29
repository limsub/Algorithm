#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long
#define INF 0x3F3F3F3F // INF + INF 연산할 일이 생길 수 있기 때문에 7로 안했다.


// 14938 서강그라운드
// 플로이드 워셜

// 얻을 수 있는 아이템의 최대 개수
// 계산 : 노드 모두 돌면서, 각 노드 별 다른 노드에 대한 최단거리 고려
// 최단거리가 수색 범위 안에 있으면, 모두 플러스해서 sum 만들기
// 모든 노드에 대해 sum 저장 후, 최대 sum 출력
// 여기서 해당 노드란, 예은이가 낙하한 지점을 의미한다.


int d[402][402];
int items[402];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 입력 및 초기화
    int n, m, r; cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) cin >> items[i];   // 인덱스 주의
    
    for (int i = 0; i <= n; i++) fill(d[i], d[i] + n + 1, INF);
    for (int i = 0; i <= n; i++) d[i][i] = 0;

    for (int i = 0; i < r; i++) {
        int x, y, cost; cin >> x >> y >> cost;
        d[x][y] = cost;
        d[y][x] = cost;
    }


    // 2. 플로이드 워셜
    for (int i = 1; i <= n; i++) { // i : 거쳐가는 노드

        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                // x -> y로 가는 최단거리
                d[x][y] = min(d[x][y], d[x][i] + d[i][y]);
            }
        }

    }


    // 3. 최대 아이템 개수 계산
    vector<int> sums;
    for (int i = 1; i <= n; i++) {  // i 노드에 예은이가 낙하한다면

        int sum = 0;
        for (int j = 1; j <= n; j++) {  // 어차피 d[i][j] = 0 이라서 넘어가도 됨
            
            if (d[i][j] <= m) { // 도달할 수 있다면
                sum += items[j];
            }
            
        }

        sums.push_back(sum);
    }

    sort(sums.begin(), sums.end(), greater<int>());

    cout << sums.front();


    // cout << "\n";
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << d[i][j] << "  ";
    //     }
    //     cout << "\n";
    // }


    return 0;
}

