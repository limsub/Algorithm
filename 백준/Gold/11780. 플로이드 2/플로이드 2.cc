#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long
#define INF 0x3F3F3F3F // INF + INF 연산할 일이 생길 수 있기 때문에 7로 안했다.

// 11780 플로이드 2

// 최단 경로 출력 + 거쳐가는 모든 노드를 함께 출력해야 한다.
// 벡터에다 저장을 해야겠지...?

// d[x][y]에 최단 경로 저장
// vector<int> ds[x][y]에 x에서 y로 갈 때 거치는 모든 노드 저장.
// 출력할 때는 모든 노드의 개수 + 노드들 출력

// d[x][y] = min(d[x][y], d[x][i] + d[i][y]);

// if (d[x][i] + d[i][y] < d[x][y]) 일 때!!
// 1. d[x][y] = d[x][i] + d[i][y];
// 2. - 1. ds[x][y] 모두 지우기. 
//    - 2. ds[x][y].push_back(ds[x][i])
//    - 3. ds[x][y].push_back(ds[i][y])


// 이런 미친 99% 틀은 뭐야



int n, m;
int d[102][102];
vector<int> ds[102][102];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 입력 및 초기화
    cin >> n >> m;
    for (int i = 0; i <= n; i++) fill(d[i], d[i] + n + 1, INF);
    for (int i = 0; i <= n; i++) d[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int x, y, cost;
        cin >> x >> y >> cost;

        // 1. 비용 저장
        d[x][y] = min(d[x][y], cost);
        // 2. x에서 y로 갈 때 거치는 노드 - 일단 도착 노드도 포함시킨다.
        ds[x][y].clear();
        ds[x][y].push_back(y);
    }


    // 2. 플로이드 워셜 + 방문 노드도 함께 저장
    for (int i = 1; i <= n; i++) {  // i번째 노드를 거쳐간다고 생각

        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                // x -> y로 가는 cost 계산

                if (d[x][i] + d[i][y] < d[x][y]) {
                    // 업데이트가 필요하다면!

                    // 1. 
                    d[x][y] = d[x][i] + d[i][y];

                    // 2 - 1.
                    ds[x][y].clear();

                    // 2 - 2.
                    // 뒤에 추가할 때,
                    // x -> a -> b -> c -> d -> i
                    // i -> e -> f -> g -> y 라면

                    // (a, b, c, d, i)
                    // (e, f, g, y) 가 저장이 되어있다.

                    // 
                    for (int k = 0; k < ds[x][i].size(); k++) {
                        ds[x][y].push_back(ds[x][i][k]);
                    }

                    // 2 - 3.
                    for (int k = 0; k < ds[i][y].size(); k++) {
                        ds[x][y].push_back(ds[i][y][k]);
                    }
                }
            }
        }

    }

    // 3. 출력
    // - 1. cost 출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] >= INF) { cout << "0 "; }
            else { cout << d[i][j] << " "; }
        }
        cout << "\n";
    }

    // - 2. 거쳐가는 노드 출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // i -> j로 갈 때, 

            if (i == j || d[i][j] >= INF) {
                cout << "0";
            }
            else {
                // - 1). 거쳐가는 노드의 개수
                cout << ds[i][j].size() + 1 << " ";

                // - 2). 거쳐가는 노드들 
                cout << i << " ";
                for (int k = 0; k < ds[i][j].size(); k++) {
                    cout << ds[i][j][k] << " ";
                }
            }    
            cout << "\n";
        }
    }


    return 0;
}

