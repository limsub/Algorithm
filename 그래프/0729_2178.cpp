#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>



// 2178

vector< vector<int> > graph;
int v[101][101] = {0};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int N, M;

// 포인트 : 0과 1이 담겨있는 graph에다가 바로 그 깊이를 저장시켜버림
// 한 칸 넘어갈 때마다 이전 위치의 값 + 1을 저장시키기
// 따로 깊이에 대한 변수를 사용할 필요가 없다


void BFS() {

    queue< pair<int, int> > q;

    // (0, 0)에서 시작 -> (N-1, M-1) 도착

    q.push(make_pair(0, 0));
    v[0][0] = 1;

    // pair로 저장된 nextNode -> (x, y)
    // 배열에 적용할 때는 -> [y][x]

    while(!q.empty()) {

        pair<int, int> nextNode;
        nextNode = q.front();
        q.pop();

        //printf("%d ", nextNode);
        //printf("새로운 nextNode : %d, %d\n", nextNode.second, nextNode.first);

        // 인접한 노드 탐색
        for (int i = 0; i < 4; i++) {
            int x_pos = dx[i];
            
            int y_pos = dy[i];

                // 간단하게 줄여주기
                int next_y = nextNode.second + y_pos;
                int next_x = nextNode.first + x_pos;

                if (next_y >= 0 && next_y < N && next_x >= 0 && next_x < M) {
                    if (graph[next_y][next_x] != 0
                        && v[next_y][next_x] == 0) {

                        //printf("좌표 (y, x) : %d, %d\n", next_y, next_x);
                        
                        v[next_y][next_x] = 1;
                        q.push(make_pair(next_x, next_y));
                        graph[next_y][next_x] = graph[nextNode.second][nextNode.first] + 1;

                    }
                }

            

            
        }

    }
}

int main() {

    
    cin >> N >> M;
    
    graph.resize(N+1);
    for (int i = 0; i < N+1; i++) {
        graph[i].resize(M+1);
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char x;
            cin >> x;

            string s;
            s += x;

            graph[i][j] = atoi(s.c_str());
        }
    }

    // printf("\n");

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++)  {
    //         cout << graph[i][j];
    //     }
    //     printf("\n");
    // }

    //ans = 0;

    BFS();

    // printf("\n");

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++)  {
    //         cout << graph[i][j] << "  ";
    //     }
    //     printf("\n");
    // }

    printf("%d", graph[N-1][M-1]);

    return 0;
}
