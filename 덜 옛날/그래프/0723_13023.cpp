#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>



// 13023

// 사이클이 있는지 확인하는 문제
// 사이클 확인 -> DFS 돌았는데 자기 자신한테 돌아온다

// 실수 - 노드 4개짜리 사이클이 있는지 확인하는 문제이다

// 실수 - 사이클 문제가 전혀 아니네...
// 그냥 깊이 5짜리가 있는지 확인하는 문제였다..


// 계속 틀린 이유
// v의 초기화를 main함수에서 DFS 들어가기 전에 계속 해주면 틀리고,
// DFS 함수 내에서 특정 노드와 연결된 탐색이 완료된 후에 v값을 0으로 바꿔주어야 한다...
// 근데 이거 이유를 아직 잘 모르겠다..;;


vector< vector<int> > graph;
vector<int> v;
int N, M;
int ans;

void DFS(int startNode, int cnt) {

    if (cnt == 5) {
        ans = 1;
        return;
    }

    v[startNode] = 1;

    for (int i = 0; i < graph[startNode].size(); i++) {
        int nextNode = graph[startNode][i];

        if (v[nextNode] == 0) {
            //cout << startNode << " - " << nextNode << endl;
            DFS(nextNode, cnt+1);
        }
    }


    v[startNode] = 0;
}

int main() {

    ans = 0;
    
    cin >> N >> M;

    graph.resize(N+1);

    v = vector<int>(N+1, 0);
    


    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }


    
    for (int i = 0; i < N; i++) {
        //v = vector<int>(N+1, 0);
        
        DFS(i, 1);

        if (ans == 1) {
            break;
        }
    }

    printf("%d\n", ans);

    return 0;
}
