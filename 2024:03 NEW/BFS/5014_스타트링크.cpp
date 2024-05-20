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
#include <map>
// #include <pair>
// #include <bits/stdc++.h>

// 5014 스타트링크

// 그래프가 아닌 형태의 BFS

// 총 F층. 스타트링크 - G층. 현재 S층.
// 위로 U층 이동. 아래로 D층 이동.

// 81% 틀. - 반례 못찾겠다.
// 하.... 0층은 없다... (next <= 0 continue)


int F, S, G, U, D;

int v[1000010]; // i층에 가기 위해 몇 번 버튼을 눌러야 하는지 저장 (아마 + 1)

void bfs() {
    queue<int> q;

    int d[] = {U, -D}; // 탐색 가능한 층 : 2개. (cur + U, cur - D);

    // 현재 위치 큐 삽입
    q.push(S);
    v[S] = 1;

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        // cout << cur << "\n";

        for (int dir = 0; dir < 2; dir++) {
            int next = cur + d[dir];

            if (next > F || next <= 0) continue;
            if (v[next]) continue;

            q.push(next);
            v[next] = v[cur] + 1;

            if (next == G) return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    cin >> F >> S >> G >> U >> D;

    bfs();

    if (v[G]) {
        cout << v[G] - 1;
    }
    else {
        cout << "use the stairs";
    }

    return 0;
}