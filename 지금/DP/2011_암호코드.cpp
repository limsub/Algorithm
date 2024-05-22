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


//  2011

// 1. 로직 구상
// [0] : 1개짜리일 때 개수. [1] : 2자리 수 중 뒷자리일 때 경우
// N   : 2  5  1  1  4
// [0] : 1  1  2  2  4
// [1] : 0  1  0  2  2

// d[i][0] = d[i-1][0] + d[i-1][1]
// d[i][1] = d[i-1][0]

// 답 : d[N][0] + d[N][1]


// 2. 정답 확인 
// 1과 로직 동일. 단 배열을 하나로만 사용

// 1대로 하면 틀림


int n;
int arr[5010];
int d[5010][2];
int mod = 1000000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    string s; cin >> s;
    int s_len = s.length();

    for (int i = 1; i <= s_len; i++) arr[i] = s[i-1] - '0';

    if (arr[1] == 0) { cout << "0"; return 0; }

    d[1][0] = 1;
    d[1][1] = 0;

    for (int i = 2; i <= s_len; i++) {
        if (arr[i] > 0) {
            d[i][0] = (d[i-1][0] + d[i-1][1]) % mod;
        }

        int x = arr[i-1] * 10 + arr[i];

        if (x >= 10 && x <= 26) {
            d[i][1] = d[i-1][0] % mod;
        }

        // if (arr[i] == 0 && x < 10 || x > 26) { cout << "0"; return 0;}
        if (d[i][0] == 0 && d[i][1] == 0) { cout << "0"; return 0;}
    }

    cout << (d[s_len][0] + d[s_len][1]) % mod;


    return 0;
}