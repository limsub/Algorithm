#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>

// 1325
// 효율적인 해킹

// 1차 제출 -> 2% 메모리 초과
// (출력하는 vector 제거) 2차 제출 -> 2% 메모리 초과
// (사이클 고려하지 않으면 v값이 계속해서 커질 수 있다!!)

// 사이클 고려하면... 또 생각할 게 많아지네

// 모두 고려했는데도.. 1% 틀

int N, M;
vector< vector<int> > arr;
vector<int> v;

vector<bool> v2;


int maxAns = -1;
vector<int> ansArr;

// 매번 bfs마다 maximum 값과, 그 배열을 따로 잡는다!


void printArr() {
    for (int i = 1; i <= N; i++) {
        printf("===== %d와 연결 =====  ", i);
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << " " << endl;
    }
}

void printV() {
    for (int i = 1; i <= N; i++) {
        cout << i << " : " << v[i] << endl;
    }
}

void resetV() {
    for (int i = 0; i < N+1; i++) {
        v2[i] = false;
        v[i] = 0;
    }
}

void bfs(int startNode) {
    // 시작 노드의 v값을 0으로 잡고 들어감
    // 만약 이미 0보다 큰 값이 있다면, 지금 하는 bfs는 의미가 없으므로 함수 return

    v2[startNode] = true;

    queue<int> q;
    q.push(startNode);

    while (!q.empty()) {
        // 탐색할 노드 (v값은 큐에 넣기 전에 바꿔주기))
        int nextNode = q.front();
        q.pop();

        int nextVisted = v[nextNode] + 1;    // 인접한 애들에게 넣어줄 v값

        // 인접 노드 중 탐색하지 않은 애들 큐에 넣어주기
        for (int j = 0; j < arr[nextNode].size(); j++) {

            int next2Node = arr[nextNode][j];

            // if (v[next2Node] >= nextVisted) { continue; }
            if (v2[next2Node]) { continue; }

            // 큐에 삽입
            q.push(next2Node);
            v[next2Node] = nextVisted;
            v2[next2Node] = true;
            
        }
    }


    // 여기서 maxAns를 체크하고, 더 큰게 나왔으면 arr 리셋하고 새로운 값들로 추가해
    int maxAnsTmp = -1;
    for (int i = 1; i <= N; i++) {
        if (v[i] > maxAnsTmp) {
            maxAnsTmp = v[i];
        }
    }
    printf("startNode : %d\n", startNode);
    printf("maxAnsTmp : %d, maxAns : %d\n", maxAnsTmp, maxAns);
    printV();


    // 같은게 나왔어 -> 추가해줘
    if (maxAnsTmp == maxAns) {
        // printf("hi start : %d\n", startNode);
        // 없는 애들만 추가해
        for (int i = 1; i <= N; i++) {
            if ( (v[i] == maxAns ) && (find(ansArr.begin(), ansArr.end(), i) == ansArr.end() ) ) {
                ansArr.push_back(i);
            }
        }
    }


    // 더 큰게 나왔어
    if (maxAnsTmp > maxAns) {
        ansArr.clear();
        maxAns = maxAnsTmp;

        for (int i = 1; i <= N; i++) {
            if (v[i] == maxAns) {
                ansArr.push_back(i);
            }
        }

        // printf("startNode : %d\n", startNode);
        // printf("===== %d ===== \n", maxAns);
        // printV();

    }
    return;
}





int main() {

    cin >> N >> M;

    arr.resize(N+1);
    v.resize(N+1);
    v2.resize(N+1);

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;

        arr[x].push_back(y);
    }




    for (int i = 1; i <= N; i++) {
        resetV();
        bfs(i);
    }

    sort(ansArr.begin(), ansArr.end());
    for (int i = 0; i < ansArr.size(); i++) {
        printf("%d ", ansArr[i]);
    }

   
    

    return 0;
}