#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long

// 1717 집합의 표현

// 단순 union find

vector<int> p(1000010, -1);

int find_p(int x) {
    if (p[x] < 0) return x;
    return p[x] = find_p(p[x]);
}

void union_p(int x, int y) {
    x = find_p(x); y = find_p(y);
    
    if (x == y) return;

    if (p[x] < p[y]) p[y] = x;
    else p[x] = y;
}

bool is_same_p(int x, int y) {
    x = find_p(x); y = find_p(y);

    return x == y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int N, M; cin >> N >> M;
    for (int i = 0; i < M; i++) {

        int x, y, z; cin >> x >> y >> z;

        if (x == 0) {
            union_p(y, z);
        }


        else {
            if (is_same_p(y, z)) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }

        }
    }


    return 0;
}

