#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long
#define INF 0x3F3F3F3F // INF + INF 연산할 일이 생길 수 있기 때문에 7로 안했다.


// 1613 역사

// 플로이드 워셜
// 모든 cost는 1로 통일. 즉, 1이거나 INF이거나
// d[x][y]와 d[y][x]를 비교. 둘 중 하나가 1이면 경로 있음. 둘다 INF이면 경로 없음


int d[402][402];
int n, k;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 입력
    cin >> n >> k;
    d[0][0] = 1;

    // d 초기화
    for (int i = 0; i <= n; i++) fill(d[i], d[i] + n + 1, INF);
    for (int i = 0; i <= n; i++) d[i][i] = 0;

    for (int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;
        d[x][y] = 1; // x -> y 경로가 존재
    }




    // 플로이드 워셜
    for (int i = 1; i <= n; i++) {  // i를 거쳐간다고 생각

        for (int x = 1; x <= n; x++) {
            for  (int y = 1; y <= n; y++) {
                // x -> y vs. x -> i -> y 의 cost를 비교한다.
                d[x][y] = min(d[x][y], d[x][i] + d[i][y]);
            }
        }

    }




    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int x, y; cin >> x >> y;

        // 둘다 INF다.
        if (d[x][y] >= INF && d[y][x] >= INF) {
            cout << "0\n";
        }
        // x -> y만 존재한다.
        else if (d[x][y] < INF && d[y][x] >= INF) {
            cout << "-1\n";
        }
        else {
            cout << "1\n";
        }
    }

    return 0;
}

