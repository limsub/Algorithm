#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>

// 18352
// 특정 거리의 도시 찾기

// 1차 제출 -> 2% 틀
// 2차 제출 (배열 소팅 후 출력) -> 81% 틀
// 4차 제출 (아예 갈아엎음. v 기본값 -1로 수정) -> 맞

int main() {

    int N, M, K, X;
    cin >> N >> M >> K >> X;

    vector< vector<int> > arr(N+1); // 1부터 값 넣을 예정

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;

        // 단방향 노드 연결
        arr[x].push_back(y);
    }


    // bfs 시작
    // int cnt = 0;
    queue<int> q;
    vector<int> v(N+1);
    for (int i = 0; i < v.size(); i++) {
        v[i] = -1;
    }


    // 출발지가 정해져 있다: X
    // X부터 최단 거리 : cnt (X는 0) -> v에 저장
    q.push(X);
    v[X]++;

    vector<int> ansArr;

    while (!q.empty()) {
        // 토마토 문제와 비슷하게 접근해보자
        // 현재 큐에 있는 애 (뭉텅이) 다 뺄 때마다 cnt += 1

        int size = q.size();

        // // 만약 cnt가 K와 같다면, 지금 큐에 들어있는애들 모두 출력하고 리턴
        // if (cnt == K) {
        //     if (q.empty()) {
        //         printf("-1\n");
        //         return 0;
        //     }

        //     for (int i = 0; i < size; i++) {
        //         ansArr.push_back(q.front());
        //         // printf("%d\n", q.front());
        //         q.pop();
        //     }

        //     sort(ansArr.begin(), ansArr.end());

        //     for (int i = 0; i < size; i++) {
        //         printf("%d\n", ansArr[i]);
        //     }
        //     return 0;
        // }


        for (int i = 0; i < size; i++) {
            int next = q.front();
            q.pop();


            for (int j = 0; j < arr[next].size(); j++) {
                int nextTest = arr[next][j];
                int nextCnt = v[next] + 1;

                if (v[nextTest] != -1 && v[nextTest] <= nextCnt) { continue; }
                q.push(nextTest);
                v[nextTest] = nextCnt;
            }
        }
        
        // 한 뭉텡이 다 뺐으면 cnt 증가
        // cnt++;

        // // 혹시 다음에 큐가 비었다면, 없다는 뜻으로 -1 리턴
        // if (q.empty()) {
        //     printf("-1\n");
        //     return 0;
        // }
    }

    // for (int i = 0; i <= N; i++) {
    //     printf("%d %d\n", i, v[i]);
    // }

    // 여기서 출력하자
    // v가 K인 애들 출력해주기
    for (int i = 0; i <= N; i++) {
        if (v[i] == K) {
            ansArr.push_back(i);
        }
    }

    // 만약 비었으면 -1 출력
    if (ansArr.empty()) {
        printf("-1");
        return 0;
    }

    sort(ansArr.begin(), ansArr.end());
    for (int i = 0; i < ansArr.size(); i++) {
        printf("%d\n", ansArr[i]);
    }


    return 0;
}