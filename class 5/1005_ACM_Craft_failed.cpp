#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;
#include <queue>


// 1005
// ACM Craft

int T, N, K, X, Y, W;

int arr[1001];
vector<int> dirArr[1001];
vector<int> reDirArr[1001];

int dp[1001]; 


void initArr() {
    for (int i = 0; i < N; i++) {
        arr[i] = 0;
        dp[i] = 0;

        dirArr[i].clear();
        reDirArr[i].clear();
    }
}


int find() {

    queue<int> q;

    // 1 ~ N 까지 건물

    // 1. 시작 지점이 어딘지 찾는다. -> 여러 개일 수도 있기 때문에 모두 q에 넣어준다
    for (int i = 1; i <= N; i++) {
        if (reDirArr[i].empty()) {
            // startPoint = i;
            // cout << "starPoint : " << i << "\n";
            q.push(i);
        }
    }

    // 2. dp 계산
    // - 순서 : bfs 탐색 순서
    
    // q.push(startPoint);
    while(!q.empty()) {

        // 시작 지점
        int curPoint = q.front();
        q.pop();
        // cout << "\n" << "탐색 지점 : " << curPoint << "\n";

        // * 이미 탐색한 위치이면, pass
        // if (dp[curPoint] != 0) { continue; }

        // 시작 지점에 대해 dp 값 시작
        // - reDirArr의 요소들의 값 비교
        int maxT = 0;
        for (int q = 0; q < reDirArr[curPoint].size(); q++) {
            int previousPoint = reDirArr[curPoint][q];
            // cout << "previousPoint : " << previousPoint << "\n";

            if (dp[previousPoint] > maxT) { maxT = dp[previousPoint]; }
        }
        dp[curPoint] = maxT + arr[curPoint];

        // cout << "dp[curPoint] : " << dp[curPoint] << "\n";


        // 연결 지점 탐색
        // cout << curPoint << "의 연결 지점" << "\n";
        for (int p = 0; p < dirArr[curPoint].size(); p++) {

            int nextPoint = dirArr[curPoint][p];

            // cout << " ** " << nextPoint << "\n";

            q.push(nextPoint);
        }
    }


    // cout << "******" << "\n";
    for (int i = 1; i <= N; i++) {
        // cout << dp[i] << "  ";
    }

    return dp[W];
}

int main() {

    vector<int> ansArr;

    // test case
    // int T;
    cin >> T;
    while (T--) {

        initArr();

        // int N, K;
        cin >> N >> K;

        // 소요 시간
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }

        // 방향
        // int X, Y;
        for (int i = 0; i < K; i++) {
            cin >> X >> Y;

            dirArr[X].push_back(Y);
            reDirArr[Y].push_back(X);
        }

        // 타겟
        // int W;
        cin >> W;

        int ans = find();
        // cout << "ans : " << ans << "\n";
        ansArr.push_back(ans);
        

    }


    for (int i = 0; i < ansArr.size(); i++) {
        cout <<  ansArr[i] << "\n";
    }

    return 0;
}
