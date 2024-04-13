#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;
#include <queue>
#include <cstdio>
#include <set>
// #include <pair>

// 7576 토마토
// - 좌표 BFS
// - 기존에 뭉텡이 BFS라고 풀었지만 결국 v에 값 저장하면 되는 것.
// - 초기 v값 0 잡고, 다 돌린 후에 0인 애 있으면 탐색을 못하는 칸이 있다고 판단.


int N, M;

int arr[1010][1010];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int v[1010][1010];

void bfs(vector< pair<int, int> > starts) {
    queue< pair<int, int> > q;

    for (int i = 0; i < starts.size(); i++)  {
        // q.push( {starts[i].first, starts[i].second} );
        q.push(make_pair(starts[i].first, starts[i].second));

        v[starts[i].first][starts[i].second] = 1;
    }


    while (!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nY = curY + dy[dir];
            int nX = curX + dx[dir];

            if (nY >= N || nY < 0 || nX >= M || nX < 0) continue;
            if (v[nY][nX] != 0) continue;
            if (arr[nY][nX] != 0) continue;


            // q.push({nY, nX});
            q.push(make_pair(nY, nX));
            v[nY][nX] = v[curY][curX] + 1;
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    // 1. 입력
    cin >> M >> N;

    vector< pair<int, int> > starts;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 1) { 
                // starts.push_back({i, j});
                starts.push_back(make_pair(i, j));
            }

            if (arr[i][j] == -1) { 
                v[i][j] = -1;
            }
        }
    }

    // 2. bfs 시작
    bfs(starts);


    // 3. 값 탐색
    int max_Cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (v[i][j] == 0) {
                cout << -1 << "\n";
                return 0;
            }

            max_Cnt = max(max_Cnt, v[i][j]);
        }
    }

    cout << max_Cnt - 1 << "\n";



    
    return 0;
}