#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long
#define INF 0x3F3F3F3F // INF + INF 연산할 일이 생길 수 있기 때문에 7로 안했다.


// 10159 저울
// 플로이드 워셜

// 각 물건에 대해, 비교가 불가능한 것들 개수 출력 
// = INF인 거 개수 출력
// i 무게 > j 무게 이면, d[i][j] = 1;

int N, M;
int d[102][102];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 입력 및 초기화
    cin >> N >> M;
    for (int i = 0; i <= N; i++) fill(d[i], d[i] + N + 1, INF);
    for (int i = 0; i <= N; i++) d[i][i] = 0;

    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        d[x][y] = 1;
    }

    // 2. 플로이드 워셜
    for (int i = 1; i <= N; i++) {  // i번 노드를 거쳐갔다.

        for (int x = 1; x <= N; x++) {
            for (int y = 1; y <= N; y++) {
                d[x][y] = min(d[x][y], d[x][i] + d[i][y]);
            }
        }
    }


    // 3. 출력
    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        for (int j = 1; j <= N; j++) {
            if (d[i][j] >= INF && d[j][i] >= INF) cnt++;
        }
        ans.push_back(cnt);
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }


    return 0;
}

