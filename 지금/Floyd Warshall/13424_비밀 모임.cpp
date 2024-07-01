#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long
#define INF 0x3F3F3F3F // INF + INF 연산할 일이 생길 수 있기 때문에 7로 안했다.


// 13424 비밀 모임
// 플로이드 워셜

// 친구의 수 K개.
// for i 돌면서 친구 방들에 대해 최솟값 가지는 i 찾기

int d[102][102];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;

    while (T--) {
        
        // 1. 입력 및 초기화
        int N, M; cin >> N >> M;
        for (int i = 0; i <= N; i++) fill(d[i], d[i] + N + 1, INF);
        for (int i = 0; i <= N; i++) d[i][i] = 0;
        for (int i = 0; i < M; i++) {
            int x, y, cost; cin >> x >> y >> cost;
            d[x][y] = cost;
            d[y][x] = cost;
        }
        int K; cin >> K;
        vector<int> fr;
        for (int i = 0; i < K; i++) { 
            int x; cin >> x; 
            fr.push_back(x); 
        }

        // 2. 플로이드 워셜
        for (int i = 1; i <= N; i++) { // i번째 방을 거친다.

            for (int x = 1; x <= N; x++) {
                for (int y = 1; y <= N; y++) {
                    // x -> y;
                    d[x][y] = min(d[x][y], d[x][i] + d[i][y]);
                }
            }
        }

        // for (int i = 1; i <= N; i++) {
        //     for (int j = 1; j <= N; j++) {
        //         cout << d[i][j] << "   ";
        //     }
        //     cout << "\n";
        // }

        // 3. 최소값 갖는 i 찾기
        int ans = 0x7F7F7F7F;
        int ans_idx = -1;
        for (int i = 1; i <= N; i++) {
            int sum = 0;
            for (int t = 0; t < fr.size(); t++) {
                // 각 친구들에게 가야하는 거리 계산
                int frd = fr[t];
                sum += d[i][frd];   // 만약 가는 길이 없다면, INF를 더해버리기 때문에 알아서 최솟값으로 들어가지 않게 된다.
            }

            // ans = min(ans, sum);
            if (sum < ans) { 
                ans = sum;
                ans_idx = i;
            }
        }

        cout << ans_idx << "\n";
    }


    return 0;
}

