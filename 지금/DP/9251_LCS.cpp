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


// 9251 LCS


// 1. 로직 구상



// 2. 정답 확인


int d[1010][1010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    string a, b; cin >> a >> b;
    
    int a_len = a.length();
    int b_len = b.length();

    for (int i = 1; i <= a_len; i++) {
        for (int j = 1; j <= b_len; j++) {

            if (a[i-1] == b[j-1]) {
                d[i][j] = d[i-1][j-1] + 1;
            }

            else {
                d[i][j] = max(d[i-1][j], d[i][j-1]);
            }
        }
    }

    cout << d[a_len][b_len];





    return 0;
}