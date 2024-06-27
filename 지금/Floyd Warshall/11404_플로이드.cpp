#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long
#define INF 0x3F3F3F3F // INF + INF 연산할 일이 생길 수 있기 때문에 7로 안했다.


// 11404 플로이드
int n, m;
int d[102][102];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 입력 
    cin >> n >> m;

    // d 초기화 (INF)
    for (int i = 0; i <= n; i++) fill(d[i], d[i] + n + 1, INF);
    for (int i = 0; i <= n; i++) d[i][i] = 0;   // 시작, 도착 같은건 0

    // 입력 (노선이 여러개가 있을 수 있기 때문에, 계속해서 d를 업데이트)
    for (int i = 0; i < m; i++) {
        int x, y, cost; cin >> x >> y >> cost;

        // x에서 y로 가는 cost
        d[x][y] = min(d[x][y], cost);
    }


    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         if (d[i][j] == INF) cout << "-11 ";
    //         else cout << d[i][j] << " ";
    //     }
    //     cout << "\n";
    // }


    // 플로이드 워셜
    // n개의 정점에 대해, 얘를 거쳐간다고 생각
    // i번째 정점에 대해 고려한다고 하면, 
    // x -> y로 바로 가는거 vs. x -> i -> y 로 가는 걸 비교함
    // (x, y에 i가 없는 경우만 고려한다)

    for (int i = 1; i <= n; i++) {

        for (int x = 1; x <= n /*&& x != i*/; x++) {
            for (int y = 1; y <= n /*&& y != i*/; y++) {
                d[x][y] = min(d[x][y], d[x][i] + d[i][y]);
            }
        }

    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] == INF) cout << "0 ";
            else cout << d[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

