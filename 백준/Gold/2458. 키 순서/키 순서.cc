#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long
#define INF 0x3F3F3F3F // INF + INF 연산할 일이 생길 수 있기 때문에 7로 안했다.


// 2458 키 순서

// 플로이드 워셜
// 모든 cost는 1로 통일. 즉, 1이거나 INF이거나
// k번째 노드를 고려한다고 하면, 
// for (int i = 1; i <= n; i++) 에 대해, d[k][i]가 있거나, d[i][k]가 있으면 pass
// 근데 단 하나의 i에 대해서 둘다 INF인 경우가 있으면, 그쪽이랑 연결된 게 없기 때문에 얜 탈락


int d[502][502];
int n, m;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 입력
    cin >> n >> m;

    // d 초기화
    for (int i = 0; i <= n; i++) fill(d[i], d[i] + n + 1, INF);
    for (int i = 0; i <= n; i++) d[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        d[x][y] = 1;
    }

    // 2. 플로이드 워셜
    for (int i = 1; i <= n; i++) {  // i번째 노드를 거쳐간다고 생각

        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                // x -> y vs. x -> i -> y 비교
                d[x][y] = min(d[x][y], d[x][i] + d[i][y]);
            }
        }

    }

    // 3. 출력
    int cnt = 0;
    for (int k = 1; k <= n; k++) {
        // k번째 노드 입장에서
        int flag = 0;

        for (int i = 1; i <= n; i++) {
            if (d[k][i] >= INF && d[i][k] >= INF) {
                flag = 1;
                break;
            }
        }

        if (!flag) cnt++;
    }

    cout << cnt;


    return 0;
}

