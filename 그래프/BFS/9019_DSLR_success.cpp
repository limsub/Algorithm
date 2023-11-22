#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <cmath>
#include <set>
using namespace std;
#include <string.h>

// #include <bits/stdc++.h>

// 9019 DSLR

// 1% 런타임 에러 -> funcS 분기처리 잘못 함. v[-1] 접근
// 1% 시간초과..?

int funcD(int n) {
    n *= 2;
    if (n > 9999) {
        n = n % 10000;
    }
    return n;
}
int funcS(int n) {
    n -= 1;
    if (n == -1 ) {
        n = 9999;
    }
    return n;
}
int funcL(int n) {
    // d1
    int d4 = n % 10;
    // d2
    int d3 = (n % 100)/10;
    // d3
    int d2 = (n % 1000)/100;
    // d4
    int d1 = (n % 10000)/1000;

    return (d2 * 1000 + d3 * 100 + d4 * 10 + d1);
}
int funcR(int n) {
    // d1
    int d4 = n % 10;
    // d2
    int d3 = (n % 100)/10;
    // d3
    int d2 = (n % 1000)/100;
    // d4
    int d1 = (n % 10000)/1000;

    return (d4 * 1000 + d1 * 100 + d2 * 10 + d3);
}


// string v[100000] = {"", };

// vector< vector<char> > v(100000);
int v[10001] = {0, };

void bfs(int start, int end) {
    
    queue< pair<int, string> > q;
    q.push(make_pair(start, ""));

    while (!q.empty()) {

        int curNum = q.front().first;
        string curStr = q.front().second;
        q.pop();

        if (curNum == end) {
            cout << curStr << endl;
            return;
        }

        // 1. D
        int D = funcD(curNum);
        if (v[D] == 0) {
            v[D]= 1;
            q.push(make_pair(D, curStr + "D"));
        }

        // 2. S
        int S = funcS(curNum);
        if (v[S] == 0) {
            v[S] = 1;
            q.push(make_pair(S, curStr + "S"));
        }

        // 3. L
        int L = funcL(curNum);
        if (v[L] == 0) {
            v[L] = 1;
            q.push(make_pair(L, curStr + "L"));
        }

        // 4. D
        int R = funcR(curNum);
        if (v[R] == 0) {
            v[R] = 1;
            q.push(make_pair(R, curStr + "R"));
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    

    int T;
    // cin >> T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int A, B;
        // cin >> A >> B;
        scanf("%d %d", &A, &B);
        bfs(A, B);

        memset(v, 0, sizeof(v));
    }

    return 0;
}