#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long

// 13549 숨바꼭질 3

// BFS

// 큐에 저장 : {위치, cost (시간)}

// 1% 틀. 런타임에러 (OutOfBounds)
// 7% 틀. - 0초 후 순간이동이 있기 때문에, 큐에서 먼저 꺼냈다고 해서 반드시 빠른 시간이라고 할 수가 없다.
// -> v도 함부로 막으면 안되겠다 그럼

// 큐에서 꺼낼 때, 그냥 들어있는 순서대로 꺼내는 것이 아니라, 
// cost가 작은 것을 먼저 꺼내는 게 필요하다!!! 
// => priority queue

// priority queue 썼는데도 7% 틀.


// 7% 이유 : 2 * x로 가는 위치를, x +- 1보다 앞에서 조건문 처리해주니까 풀렸다...??
// 이유는 모르겠음

int v[100001]; // 해당 위치의 방문 여부

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    int N, K; cin >> N >> K;

    // queue< pair<int, int> > q;
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;

    // 1. 시작 위치 넣어준다.
    q.push({0, N}); 
    v[N] = 1;


    // 2. BFS
    while (!q.empty()) {
        // int curX = q.front().first;
        // int curC = q.front().second;
        int curC = q.top().first;
        int curX = q.top().second;
        q.pop();

        if (curX == K) {
            cout << curC << "\n"; 
            return 0;
        }


        // 이동 가능한 곳은 3곳
        // 1. x + 1 (cost += 1)
        // 2. x - 1 (cost += 1)


        // continue 쓰지 말고, 각각 if문

        int nextC1 = curC + 1;
        int nextX1 = curX + 1;

        int nextC2 = curC + 1;
        int nextX2 = curX - 1;

        int nextC3 = curC;
        int nextX3 = curX * 2;

        if (nextX3 >= 0 && nextX3 < 100001 && !v[nextX3]) {
            q.push({nextC3, nextX3});
            v[nextX3] = 1;
        }

        if (nextX1 >= 0 && nextX1 < 100001 && !v[nextX1]) {
            q.push({nextC1, nextX1});
            v[nextX1] = 1;
        }

        if (nextX2 >= 0 && nextX2 < 100001 && !v[nextX2]) {
            q.push({nextC2, nextX2});
            v[nextX2] = 1;
        }

        





        // for (int i = 0; i < 2; i++) {
        //     // int nextX = curX + nextPos[i];
        //     // int nextC = curC + 1;
        //     int nextC = curC + 1;
        //     int nextX = curX + nextPos[i];

        //     // v[next]에 값이 있더라도, nextC2값이 더 적으면 접근 가능
        //     if (v[nextX]) continue;
        //     if (nextX < 0 || nextX >= 100001) continue;

        //     q.push({nextC, nextX});
        //     v[nextX] = 1;
        //     // v[nextX] = nextC;


        //     // if (nextX == K) {
        //     //     // ansArr.push_back(nextC);
        //     //     cout << nextC; return 0;
        //     // }
        // }


        // // 3. 2 * x (cost += 0)
        // int nextC2 = curC;
        // int nextX2 = curX * 2;
        
        
        // // v[next]에 값이 있더라도, nextC2값이 더 적으면 접근 가능
        // if (v[nextX2]) continue;
        // // if (v[nextX2]) continue;
        // if (nextX2 < 0 || nextX2 >= 100001) continue;

        // q.push({nextC2, nextX2});
        // v[nextX2] = 1;
        // // v[nextX2] = nextC2;

        // // if (nextX2 == K) {
        // //     ansArr.push_back(nextC2);
        // //     // cout << nextC2; return 0;
        // // }

    }

    // cout << *min_element(ansArr.begin(), ansArr.end());





    return 0;
}

