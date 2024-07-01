#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long
#define INF 0x3F3F3F3F // INF + INF 연산할 일이 생길 수 있기 때문에 7로 안했다.

// 1719 택배

// "최단 경로" 를 출력하는게 아니라, "최단 경로로 가기 위한 첫 번째 위치"를 출력해야 함
// 걍 3차원 배열로 저장하자 그럼
// [0] : 최단 경로, [1] : 최단 경로로 가기 위한 첫 번째 위치

int d[202][202][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 입력 및 초기화
    int N, M; cin >> N >> M;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            d[i][j][0] = INF; d[i][j][1] = -1;
        }
    }
    for (int i = 0; i <= N; i++) {
        d[i][i][0] = 0; d[i][i][1] = -1;
    }
    for (int i = 0; i < M; i++) {
        int x, y, cost; cin >> x >> y >> cost;

        d[x][y][0] = cost;
        d[x][y][1] = y;

        d[y][x][0] = cost;
        d[y][x][1] = x;
    }


    // 2. 플로이드 워셜
    for (int i = 1; i <= N; i++) {  // i 노드를 거쳐간다고 생각
        for (int x = 1; x <= N; x++) {
            for (int y = 1; y <= N; y++) {
                // x -> y
                // 얘가 더 최단거리이면 업데이트해주기
                if (d[x][i][0] + d[i][y][0] < d[x][y][0]) {
                    d[x][y][0] = d[x][i][0] + d[i][y][0];
                    // d[x][y][1] = i;
                    // 이러면 안돼...
                    d[x][y][1] = d[x][i][1];
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (d[i][j][1] == -1) {
                cout << "- ";
            }
            else {
                cout << d[i][j][1] << " ";
            }
            
        }
        cout << "\n";
    }


    return 0;
}

