#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>

// 4963

// 섬 개수 구기

int arr[50][50];
int v[50][50];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

// 탐색한 곳 v값 1로 변경
void bfs(int y, int x, int n, int m) {
    queue< pair<int, int> > q;
    q.push(make_pair(y, x));
    v[y][x] = 1;

    while (!q.empty() ) {
        pair<int, int> next = q.front();
        q.pop();


        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {

                int ny = next.first + dy[i];
                int nx = next.second + dx[j];

                if (ny >= n || ny < 0 || nx >= m || nx < 0) { continue; }
                if (v[ny][nx] == 1) { continue; }
                if (arr[ny][nx] == 0) { continue;}

                q.push(make_pair(ny, nx));
                v[ny][nx] = 1;

            }
        }
    }
}

int countIsland(int n, int m) {

    int cnt = 0;

    queue<int> queue;

    // bfs(0, 0, n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 0 && arr[i][j] == 1) {
                bfs(i, j, n, m);
                cnt++;
            }
        }
    }

    return cnt;
}

void initArr() {
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            arr[i][j] = 0;
            v[i][j] = 0;
        }
    }
}


int main() {

    vector<int> ans;
    
    while (1) {
        int m, n;
        cin >> m >> n;

        if (m == 0 && n == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }

        int t = countIsland(n, m);
        ans.push_back(t);

        // arr, v 모두 0으로 초기화
        initArr();
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }


   return 0;
}