#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>

// 1697 숨바꼭질
// 런타임 에러 -> next가 0이거나 100000 이상인 경우 분기처리 안함
// next >= 100000 이 아니라 next > 100000 이라고 해야 함

int N, M;

int v[100001] = {0, };

void bfs() {
    queue<int> q;

    q.push(N);

    int cnt = 0;

    while(!q.empty()) {
        // 뭉텡이 단위로 뽑기
        int size = q.size();

        for (int i = 0; i < size; i++) {
            int start = q.front();
            q.pop();

            if (start == M) {
                cout << cnt << endl;
                return;
            }

            // 이미 방문했었으면 굳이 넣어줄 필요 없다
            int next1 = start - 1;
            int next2 = start + 1;
            int next3 = start * 2;

            int arr[] = {next1, next2, next3};

            for (int j = 0; j < 3; j++) {
                int next = arr[j];

                if (next < 0 || next > 100000) { continue; }
                if (v[next] != 0) { continue; }

                q.push(next);
                v[next] = 1;
            }
        }

        cnt++;
    }
}

int main() {

    cin >> N >> M;

    v[N] = 1;

    bfs();

    return 0;
}