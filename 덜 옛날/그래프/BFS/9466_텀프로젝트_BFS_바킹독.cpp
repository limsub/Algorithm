#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>


// 9466 텀 프로젝트

// 1% 시간 초과


vector<int> arr;    // 인덱스가 희망한 사람. 값이 지정한 사람
// vector<int> v;      // 방문한 사람
// int c[100001] = {0, };   // 사이클이 있다고 판단된 애들은 값이 1

// 주의 : 인덱스는 0부터가 아니라 1부터 계산한다 (사람 번호)


int T;

// vector<int> ansArr;

/* ===== 바킹독 풀이 ===== */
int state[100005] = {2, };
// 사이클에 들어 있는지, 이미 실패했는지, 아직 방문하지 않았는지, 방문했는지로 구분한다
// 0, 1, 2, 3
void run(int x) {
    // printf("hi");

    int cur = x;

    while (true) {
        // cur를 일단 방문했다
        state[cur] = 3;

        // 다음 cur로 넘어간다
        cur = arr[cur];

        // printf("=== 다음 cur= %d ===== \n", cur);

        // case 1. state == 0이거나 1이면 cur와 여태까지 애들은 사이클에 포함되지 않는다
        if (state[cur] == 0 || state[cur] == 1) {
            // 처음으로 돌아가서 여태까지 방문한 애들 모두 실패 상태로 바꿔준다
            cur = x;
            while (state[cur] == 3) {
                state[cur] = 1;
                cur = arr[cur];
            }
            return;
        }

        // case 2. 초기 x 말고 다른 y를 재방문하면, x ~ y는 실패, y ~ y는 사이클에 포함된 애들이다
        if (state[cur] == 3 && cur != x) {
            // printf("=====%d%d\n", cur, x);
            // y ~ y 사이클로 넣어줌
            while (state[cur] != 0) {
                state[cur] = 0;
                cur = arr[cur];
            }
            // x ~ y 실패
            cur = x;
            while (state[cur] != 0) {
                state[cur] = 1;
                cur = arr[cur];
            }
            return;
        }

        // case 3. 초기 x를 재방문하면, x ~ x는 모두 사이클
        if (state[cur] == 3 && cur == x) {
            while (state[cur] != 0) {
                state[cur] = 0;
                cur = arr[cur];
            }
            return; 
        }
    }

}

/*
void dfs(int start, int next) {

    // printf("start and next : %d %d \n", start, next);

    // 재귀함수 돌면서 다시 start가 나오면 배열에 넣어둔 애들 모두 사이클 있다
    if (start == next) {
        for (int i = 0; i < ansArr.size(); i++) {
            c[ansArr[i]] = 1;
        }
        return;
    }
    
    v[next] = 1;

    int next2 = arr[next];

    if (v[next2] == 0 || next2 == start) {
        ansArr.push_back(next2);
        dfs(start, next2);
        ansArr.pop_back();
    }

    
    return;
}
*/
int main() {

    cin >> T;

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;

        // 배열 초기화
        arr.clear();
        // v.clear();
        arr.resize(N+1);
        // v.resize(N+1);
        // for (int t = 1; t <= N; t++) { c[t] = 0; v[t] = 0; }

        // 배열 입력
        for (int j = 1; j <= N; j++) {
            cin >> arr[j];
            state[j] = 2;
        }

        

        /* === 바킹독 === */
        for (int j = 1; j <= N; j++) {
            if (state[j] == 2) {
                run(j);
            }
        }

        int cnt = 0;
        for (int j = 1; j <= N; j++) {
            if (state[j] == 1) {
                cnt++;
            }
        }
        cout << cnt << endl;


        


        // // 1부터 N에 대해 dfs 시작. c가 0인 애들만 dfs 시작. v는 계속 초기화
        // for (int j = 1; j <= N; j++) {
        //     // 이미 사이클이 있다고 판단됨
        //     if (c[j] == 1) { continue;}

        //     // 자기 자신을 가리키고 있는 경우, 굳이 dfs 돌리지 않는다
        //     if (arr[j] == j) { c[j] = 1; continue; }

        //     // j에 대해서는 방문했다 치고, arr[j] 부터 시작
        //     v[j] = 1;
        //     ansArr.push_back(j);
        //     dfs(j, arr[j]);

        //     // ansArr, v 초기화
        //     ansArr.clear();
        //     v.clear();
        //     v.resize(N);
        // }

        // // printf("=====배열 출력=====\n");
        // // for (int j = 1; j <= N; j++) {
        // //     cout <<  "arr" << j << " : " << arr[j] << endl;
        // //     cout <<  "c" << j << " : " << c[j] << endl;
        // // }


        // // c가 0인 애들이 총 몇명인지 계산. 
        // // printf("===== c가 0인 원소들=====\n");
        // // for (int j = 1; j <= N; j++) {
        // //     if (c[j] == 0) { cout << j << endl;}
        // // }

        // // c가 0인 애들 수 출력
        // int cnt = 0;
        // for (int j = 1; j <= N; j++) {
        //     if (c[j] == 0) { cnt++; }
        // }
        // cout << cnt << endl;



    }



    return 0;
}
