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


// 4179 불!
// - 큐 두개 필요
// - 사람 큐, 불 큐

// 1. 불 큐에 대해 bfs 시작 - v에는 몇 초에 해당 위치에 들어가는지 저장
// 2. 사람 큐에 대해 bfs 시작 - 조건 추가. 불 큐의 v와 비교해서 탐색 가능한지 판단

int N, M;

int dy[] = {-1, 1, 0, 0 };
int dx[] = {0, 0, -1, 1 };

int arr[1010][1010];

int vF[1010][1010];
int vP[1010][1010];


void bfsF(vector< pair<int, int> > starts) {
    queue< pair<int, int> > q;

    for (int i = 0; i < starts.size(); i++) { 
        q.push(starts[i]);
        vF[starts[i].first][starts[i].second] = 1;
    }

    while (!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();


        for (int dir = 0; dir < 4; dir++) {
            int nY = curY + dy[dir];
            int nX = curX + dx[dir];


            if (nY >= N || nY < 0 || nX >= M || nX < 0) continue;
            if (vF[nY][nX]) continue;
            if (arr[nY][nX] == 0) { continue;}


            q.push(make_pair(nY, nX));
            vF[nY][nX] = vF[curY][curX] + 1;
        }
    }
}

int bfsP(int startY, int startX) {
    queue< pair<int, int> > q;
    q.push(make_pair(startY, startX));
    vP[startY][startX] = 1;

    int ans = -1;

    while (!q.empty()) {
        int cY = q.front().first;
        int cX = q.front().second;
        q.pop();


        for (int dir = 0; dir < 4; dir++) {
            int nY = cY + dy[dir];
            int nX = cX + dx[dir];

            if (nY > N-1 || nY < 0 || nX > M-1 || nX < 0) {
                ans = vP[cY][cX];
                return ans;
            } 
            if (vP[nY][nX] || arr[nY][nX] == 0) continue;
            if (vF[nY][nX] != 0 && vP[cY][cX] + 1 >= vF[nY][nX]) continue;
            

            
            q.push(make_pair(nY, nX));
            vP[nY][nX] = vP[cY][cX] + 1;
        }
    }

    return ans;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    // 1. 입력
    cin >> N >> M;

    vector< pair<int, int> > f_starts;  // 불 초기 위치
    int p_startY, p_startX; // 사람 초기 위치

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char x; cin >> x;

            switch (x) {
                case '#':
                    arr[i][j] = 0;
                    break;
                case 'J':
                    arr[i][j] = 1;
                    p_startY = i;
                    p_startX = j;
                    break;
                case 'F':
                    arr[i][j] = 2;
                    f_starts.push_back(make_pair(i, j));
                    break;
                case '.':
                    arr[i][j] = 3;
                    break;
            }
        }
    }


    // 2. 불 bfs
    bfsF(f_starts);

    // 3. 사람 bfs
    int ans = bfsP(p_startY, p_startX);

    // 4. 출력
    if (ans == -1) {
        cout << "IMPOSSIBLE";
    }
    else {
        cout << ans << "\n";
    }
    



    
    return 0;
}