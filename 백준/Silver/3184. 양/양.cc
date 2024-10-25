#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3F3F3F3F // INF + INF 연산할 일이 생길 수 있기 때문에 7로 안했다.


// 3184
// bfs -> 누가 이겼는지 리턴

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int arr[300][300];
int v[300][300];

int n, m;
int ans1, ans2;

// 늑대가 이기면 false, 양이 이기면 true
// 아무도 안이기면 0, 양이 이기면 1, 늑대가 이기면 2
void bfs(int sy, int sx) {  

    int cnt1 = 0;   // 양
    int cnt2 = 0;   // 늑대

    queue<pair<int, int>> q;
    q.push({sy, sx});
    v[sy][sx] = 1;

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        if (arr[cy][cx] == 2) cnt1++;
        if (arr[cy][cx] == 3) cnt2++;

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;
            if (v[ny][nx]) continue;
            if (arr[ny][nx] == 1) continue;

            q.push({ny, nx});
            v[ny][nx] = 1;
        }
    }

    // cout << "cnt : " << cnt1 << " - " << cnt2 << "\n";

    if (cnt1 == 0 && cnt2 == 0) {
        
    }
    else if (cnt1 > cnt2) {
        ans1 += cnt1;
    }
    else {
        ans2 += cnt2;
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

  
    // 1. 입력
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char x; cin >> x;
            switch (x) {
                case '.':
                arr[i][j] = 0;  // 빈 공간
                break;

                case '#':
                arr[i][j] = 1;  // 벽
                break;

                case 'o':
                arr[i][j] = 2;  // 양
                break;

                case 'v':
                arr[i][j] = 3;  // 늑대
                break;
            }
        }
    }

    // 2. bfs
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (v[i][j]) continue;
            if (arr[i][j] == 1) continue;

            bfs(i, j);            
        }
    }
     
    // 3. 출력
    cout << ans1 << " " << ans2;

    return 0;
}