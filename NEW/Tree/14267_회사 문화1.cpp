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


// 14267 회사 문화 1
// 1% 런타임 에러 OutOfBounds <- parent -1 들어오는거 인덱스 예외처리 해주기

int N, M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    vector< pair<int, int> > p(N+1);    // (직속 상사, 칭찬 수치)
    vector< vector<int> > child(N+1, vector<int>() );     // 자식 노드 저장 (방향 때문에 필요)
    
    

    for (int i = 1; i <= N; i++) {
        int parent;
        cin >> parent;

        p[i] = make_pair(parent, 0);    // 일단 초기값 0

        if (parent != -1) {
            child[parent].push_back(i);
        }
    }

    for (int i = 0; i < M; i++) {
        int person, weight;
        cin >> person >> weight;

        p[person].second += weight;
    }

    // 1번이 사장이므로, 사장부터 시작해서 부모의 weight을 자식의 weight에 더해줌
    // 직속 부하이기 때문에, 각 노드는 간선이 2개밖에 없다. 이 중 부모가 아닌 노드 방향으로 탐색을 이어가면 됨
    // (수정) -> 애초에 child 배열을 이용
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int j = 0; j < child[cur].size(); j++) {
            int next = child[cur][j];

            p[next].second += p[cur].second;

            q.push(next);
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << p[i].second << " ";
    }


    return 0;
}