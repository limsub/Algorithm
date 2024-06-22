#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long

// 20040 사이클 게임

// union find

// 사이클이 발생한다 : x와 y를 union하려 했는데, 이미 p가 같다.

// 1% 틀 - 사이클이 발생하는 첫 순간을 잡아야 한다. 계속 게임을 진행히시키면 그 이후에 사이클이 또 생길수가 있다.

vector<int> p(500101, -1);

int find_p(int x) {
    if (p[x] < 0) return x;
    return p[x] = find_p(p[x]);
}

bool union_p(int x, int y) {
    x = find_p(x); y = find_p(y);

    // x의 최종 부모와 y의 최종 부모가 이미 같을 때,
    // 이 둘을 이으면 사이클이 생기게 된다.
    if (x == y) return false;


    if (p[x] < p[y]) {
        // p[x] += p[y];
        p[y] = x;
    }
    else {
        // p[y] += p[x];
        p[x] = y;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int N, M; cin >> N >> M;
    int ans = 0;
    bool flag = true;
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;


        if (!union_p(x, y) && flag) {
            ans = i + 1;
            flag = false;
        }

        // if가 걸렸으면 더이상 게임을 진행하지 않아야 한다.
        // 근데 입력을 같이 받고 있는 for문이라... 음....
    }
    
    cout << ans;

    return 0;
}

