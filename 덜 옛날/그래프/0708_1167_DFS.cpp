#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;
#include <queue>

vector< vector< pair<int, int> > > v(1000001);
bool visited[1000001];
int maxD;
int maxN;

void dfs(int node, int dist) {
    // 이미 방문한 노드이면 바로 리턴
    if (visited[node]) {
        return;
    }

    // dist가 최댓값보다 커지면 최댓값 수정
    if (dist > maxD) {
        maxD = dist;
        maxN = node;
    }

    // dfs 시작
    visited[node] = true;
    for (int i = 0; i < v[node].size(); i++) {
        int nextNode = v[node][i].first;    // 다음 노드 번호
        int nextDist = v[node][i].second;   // 해당 노드까지 거리

        dfs(nextNode, dist + nextDist);
    }

}


int main() {

    // 노드 개수
    int N;
    scanf("%d", &N);
    
    // DFS용 visited 배열
    for (int i = 0; i < N+1; i++) {
        visited[i] = false;
    }

    // 트리 정보 저장
    for (int i = 1; i <= N; i++) {
        // i 입력 -> x
        int x;
        scanf("%d", &x);

        // 두개씩 쌍으로 입력 -> 노드번호가 -1이면 종료
        while (1) {
            int node, cost;
            scanf("%d", &node);
            if (node == -1) {
                break;
            }
            scanf("%d", &cost);

            v[x].push_back(make_pair(node, cost));
            v[node].push_back(make_pair(x, cost));
        }
    }


    maxD = 0;
    
    // 임의의 정점에서 dfs 실행
    dfs(1, 0);

    for (int i = 0; i < N+1; i++) {
        visited[i] = false;
    }

    // 계산된 가장 멀리 있는 노드(maxN)에서 다시 dfs 실행
    dfs(maxN, 0);
    

    printf("%d\n", maxD);

    return 0;
}