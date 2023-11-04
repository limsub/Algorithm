#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>

// 7576 토마토 - BFS
// 기존에 3차원 풀어본 경험 있어서 금방 컷

vector< vector<int> > arr;
vector< vector<int> > v;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void printArr() {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size() ;j++) {
            cout << arr[i][j] << " ";
        }
        printf("\n");
    }
}

void printV() {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size() ;j++) {
            cout << v[i][j] << " ";
        }
        printf("\n");
    }
}


int main() {

    int M, N;
    cin >> M >> N;

    arr.resize(N);
    v.resize(N);

    queue< pair<int, int> > q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x;
            cin >> x;
            arr[i].push_back(x);
            v[i].push_back(0);

            if (x == 1) {
                q.push(make_pair(i, j));
                v[i][j] = 1;
            }
        }
    }



    // bfs 시작
    int cnt = 0;
    while (!q.empty()) {
        // 뭉텡이로 for문 돌기
        int size = q.size();

        for (int i = 0; i < size; i++) {
            pair<int, int> next = q.front();
            q.pop();

            

            for (int dir = 0; dir < 4; dir++) {
                int nextI = next.first + dy[dir];
                int nextJ = next.second + dx[dir];

                if (nextI >= N || nextI < 0 || nextJ >= M || nextJ < 0) { continue; }
                if (v[nextI][nextJ] != 0) { continue; }
                if (arr[nextI][nextJ] == -1 ) { continue; }

                q.push(make_pair(nextI, nextJ));
                v[nextI][nextJ] = 1;
                arr[nextI][nextJ] = 100;
            }            
        }

        // 뭉텡이가 끝날 때마다 cnt ++
        cnt++;
    }

    // 만약 arr에 0이 남아있다면 -1 출력 (다 탐색 못함)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << cnt-1 << endl;

    return 0;
}