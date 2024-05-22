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


// 1915 


// 1. 로직 구상
// 실패
// d[i][j] 꼭짓점 (i, j)로 시작/끝나는 정사각형의 최대 길이?


// 2. 정답 확인
// d[i][j] = min{ d[i-1][j], d[i][j-1], d[i-1][j-1] } + 1


int n, m;
int arr[1010][1010], d[1010][1010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        for (int j = 1; j <= m; j++) {
            arr[i][j] = s[j-1] - '0';
        }
    }

    int max_ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == 1) {
                d[i][j] = min(d[i-1][j] + 1, d[i-1][j-1] + 1) ;
                d[i][j] = min(d[i][j-1] + 1, d[i][j]);

                max_ans = max(max_ans, d[i][j]);
            }
        }
    }

    cout << max_ans * max_ans;

    return 0;
}