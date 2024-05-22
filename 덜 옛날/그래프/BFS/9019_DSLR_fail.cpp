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
// #include <bits/stdc++.h>

// 9019 DSLR

// 1% 런타임 에러 -> funcS 분기처리 잘못 함. v[-1] 접근
// 1% 시간초과..?
// 3% 시간초과... string에서 vector로도 바꿔봤는데 실패....

// 실패.

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

vector< vector<char> > v(100000);

void bfs(int start, int end) {

    queue<int> q;
    
    int n1 = funcD(start);
    q.push(n1);
    // v[n1] += "D";
    v[n1].push_back('D');

    int n2 = funcS(start);
    q.push(n2);
    // v[n2] += "S";
    v[n2].push_back('S');

    int n3 = funcL(start);
    q.push(n3);
    // v[n3] += "L";
    v[n3].push_back('L');

    int n4 = funcR(start);
    q.push(n4);
    // v[n4] += "R";
    v[n4].push_back('R');

    while (!q.empty()) {
        
        int cur = q.front();
        q.pop();

        if (cur == end) {
            // cout << v[cur] << endl;
            // printf("%s\n", v[cur].c_str());

            for (int k = 0; k < v[cur].size(); k++) {
                cout << v[cur][k];
            }
            cout << endl;

            return;
        }

        // 예외처리 추가
        // 1. LR, RL은 아무것도 안하는거니까 빼기
        // 2. LLL, RRR은 이미 L, R로 탐색했기 때문에 빼기
        // 3. LL과 RR은 동일하기 때문에 RR은 버리기.

        int length = v[cur].size();

        int n1 = funcD(cur);
        // if (v[n1] == "") {
        if (v[n1].empty()) {
            q.push(n1);     
            // v[n1] = v[cur] +  "D";

            for (int k = 0; k < v[cur].size(); k++) {
                v[n1].push_back(v[cur][k]);
            }
            v[n1].push_back('D');
        }

        int n2 = funcS(cur);
        // if (v[n2] == "") {
        if (v[n2].empty()) {
            q.push(n2);
            // v[n2] = v[cur] + "S";
            for (int k = 0; k < v[cur].size(); k++) {
                v[n2].push_back(v[cur][k]);
            }
            v[n2].push_back('S');
        }

        int n3 = funcL(cur);
        // if (v[n3] == "") {
        if (v[n3].empty()) {
            
            if (length > 1 && v[cur][length-1] == 'R') {}
            // else if (length > 2 && v[cur].substr(length-2, 2) == "LL") { }
            else if (length > 2 && v[cur][length-2] == 'L' && v[cur][length-1] == 'L') { }
            else {
                q.push(n3);
                for (int k = 0; k < v[cur].size(); k++) {
                    v[n3].push_back(v[cur][k]);
                }
                v[n3].push_back('L');
                
                // v[n3] = v[cur] + "L";
            }
        }
        int n4 = funcR(cur);
        
        // if (v[n4] == "") {
        if (v[n4].empty()) {
            if (length > 1 && (v[cur][length-1] == 'L' || v[cur][length-1] == 'R') ) {}
            // else if (length > 2 && v[cur].substr(length-2, 2) == "RR") { }
            else if (length > 2 && v[cur][length-1] == 'R' && v[cur][length-2] == 'R') { }
            else {
                q.push(n4);
                for (int k = 0; k < v[cur].size(); k++) {
                    v[n4].push_back(v[cur][k]);
                }
                v[n4].push_back('R');
                // v[n4] = v[cur] + "R";
            }

            
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // bfs(1, 16);

    // for (int i = 0; i < 9999; i++) {
    //     int x = funcD(i);
    //     int y = funcS(i);
    //     int n = funcL(i);
    //     int m = funcR(i);

    //     if (x >= 10000 || x < 0) {
    //         cout << x << endl;
    //         cout << "x" << "  " << i << endl;
    //     }
    //     if (y >= 10000 || y < 0) {
    //         cout << y << endl;
    //         cout << "y" << "  " << i << endl;
    //     }
    //     if (n >= 10000 || n < 0) {
    //         cout << n << endl;
    //         cout << "n" << "  " << i << endl;
    //     }
    //     if (m >= 10000 || m < 0) {
    //         cout << m << endl;
    //         cout << "m" << "  " << i << endl;
    //     }
    // }

    int T;
    // cin >> T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int A, B;
        // cin >> A >> B;
        scanf("%d %d", &A, &B);
        bfs(A, B);

        v.clear();
        v.resize(100000);
    }



    return 0;
}