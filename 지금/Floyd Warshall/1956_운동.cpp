#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long
#define INF 0x3F3F3F3F // INF + INF 연산할 일이 생길 수 있기 때문에 7로 안했다.


// 1956 운동

// 플로이드 워셜

// 최소 사이클의 도로 길이의 합.
// i -> j -> i 의 값이 가장 작은 거 찾으면 됨
// d[i][j] + d[j][i] 값의 최솟값

int d[402][402];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 입력 및 초기화
    int v, e; cin >> v >> e;
    for (int i = 0; i <= v; i++) fill(d[i], d[i] + v + 1, INF);
    for (int i = 0; i <= v; i++) d[i][i] = 0;
    for (int i = 0; i < e; i++) {
        int x, y, cost; cin >> x >> y >> cost;
        d[x][y] = cost; // 여러 번 주어지지 않는다.
    }

    // 2. 플로이드 워셜
    for (int i = 1; i <= v; i++) {  // i를 거쳐간다고 생각
        // x -> y;
        for (int x = 1; x <= v; x++) {
            for (int y = 1; y <= v; y++) {
                d[x][y] = min(d[x][y], d[x][i] + d[i][y]);
            }
        }
    }

    // 3. 최솟값 찾기
    int ans = INF;
    for (int i = 1; i < v; i++) {
        for (int j = i+1; j <= v; j++) {
            ans = min(ans, d[i][j] + d[j][i]);
        }
    }

    if (ans >= INF) {
        cout << "-1";
    }
    else {
        cout << ans;
    }
    


    return 0;
}

