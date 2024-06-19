#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long

// 16236 아기 상어

// 1. 먹을수록 상어 크기 증가 -> 전역변수로 관리
// 2. 가장 가까운 물고기 먹으러 간다.
//  - 매번 BFS로 가장 가까운 물고기의 위치 확인할 필요 있다.
//  - 구현해봐야 알겠지만, 현재 상어의 위치를 전역변수로 관리


// 거리가 같으면, 가장 "왼쪽에 있거나 가장 위에 있는" -> 이 조건 구현하기가 까다롭다
// dy[], dx[] 로 어느 정도 해결은 가능한데, (바보같이 배열이라 생각 안했다)

// 결국은, 저 조건을 해결하지 못했다....

int arr[22][22];
int v[22][22];
int startY, startX;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 입력
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 9) {
                startY = i; startX = j;
                arr[i][j] = 0;  // 이 위치에 물고기가 있다고 착각하고, 여길 못지나가
            }
        }
    }


    // 2. bfs
    int curS = 2;   // 상어의 크기
    int ansD = 0;   // 정답 거리
    int cnt = 0;    // 현재 먹은 물고기 수 (상어의 크기와 같아지면, 상어 크기 + 1, cnt = 0)

    queue< pair<int, int> > q;
    q.push({startY, startX});
    v[startY][startX] = 1;

    // "현재 위치에서 가장 가까운 위치에 있는 물고기까지 걸리는 거리 계산"

    while (!q.empty()) {
        int curY = q.front().first; 
        int curX = q.front().second;
        q.pop();

        cout << curY << " - " << curX << "\n";

        // 만약 curY, curX에 먹을 수 있는 물고기가 있다면, 먹어

        // 같은 거리에 먹을 수 있는 게 여러개가 있다면, "가장 위" 아니면 "가장 왼쪽" 이게 어렵다.
        if (arr[curY][curX] < curS && arr[curY][curX] != 0 && arr[curY][curX] != 9) {

            arr[curY][curX] = 0;
            cnt++;

            if (cnt == curS) {
                curS ++;
                cnt = 0;

                // cout << "사이즈 증가 : " << curS << "\n";
            }

            // 정답 거리 
            ansD += (v[curY][curX] - 1);

            cout << "거리 추가 완료 : " << ansD << "\n";

            cout << "**********\n";
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    cout << v[i][j] << "  ";
                }
                cout << "\n";
            }

            cout << "**********\n";

            cout << "**********\n";
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    cout << arr[i][j] << "  ";
                }
                cout << "\n";
            }

            cout << "**********\n";

            // v 초기화
            memset(v, 0, sizeof(v));

            // q 초기화
            while(!q.empty()) { q.pop(); }
            q.push({curY, curX});
            v[curY][curX] = 1;


            continue; // 아래 탐색 하지 말고, 다시 bfs처음으로 돌아가
        }

        for (int dir = 0; dir < 4; dir++) {
            int nY = curY + dy[dir];
            int nX = curX + dx[dir];

            if (nY >= N || nY < 0 || nX >= N || nX < 0) continue;
            if (v[nY][nX]) continue;

            // 큰 크기 : 못지나가고, 못먹음
            // 같은 크기 : 지나가고, 못먹음
            // 작은 크기 : 먹음
            if (arr[nY][nX] > curS) continue;


            q.push({nY, nX});
            v[nY][nX] = v[curY][curX] + 1;
        }
    }

    cout << ansD;
    

    return 0;
}

