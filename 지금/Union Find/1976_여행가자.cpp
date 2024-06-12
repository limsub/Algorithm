#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long

// 1976 여행 가자
// union find

// 아마 문제를 그냥 처음 봤으면, 냅다 BFS로 풀려고 했을듯

// 1. 입력 받아서, union find로 연결된 애들 묶는다.
// 2. 마지막에 입력으로 들어온 애들의 find_p()를 계산해서 다 같은지 확인한다.


vector<int> p(300, -1);

int find_p(int x) {
    if (p[x] < 0) return x;
    return p[x] = find_p(p[x]);
}

void union_p(int x, int y) {
    x = find_p(x); y = find_p(y);

    if (x == y) return;

    if (p[x] < p[y]) {
        p[x] += p[y];   // 자식 개수 더해주는 연습. 그냥~
        p[y] = x;
    }
    else {
        p[y] += p[x];
        p[x] = y;
    }

    return;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int N, M; cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int e; cin >> e;
            if (e == 1) {   // 연결되었다면, 
                union_p(i, j);
            }
        }
    }

    // 여행 시작 도시
    int city1; cin >> city1;
    int final_p = find_p(city1);
    bool flag = true;
    for (int i = 1; i < M; i++) {
        int city; cin >> city;
        if (final_p != find_p(city)) flag = false;
    }


    if (flag) cout << "YES";
    else cout << "NO";
    

    return 0;
}

