#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long
#define INF 0x3F3F3F3F // INF + INF 연산할 일이 생길 수 있기 때문에 7로 안했다.

// 9252 LCS 2

// LCS의 길이와, 문자열까지 출력해야 함.

int dir[1010][1010]; // 방향을 나타낸다. 0 : 대각선, 1 : 위쪽, 2 : 왼쪽
int len[1010][1010];  // 길이를 나타낸다.

string a, b; 


void print_lcs(int a_idx, int b_idx) {

    if (a_idx == 0 || b_idx == 0) {
        return;
    }

    if (dir[a_idx][b_idx] == 0) {
        // cout << "a_idx : " << a_idx << " * " << "b_idx : " << b_idx << "\n";
        print_lcs(a_idx-1, b_idx-1);
        cout << a[a_idx-1];
    }
    else if (dir[a_idx][b_idx] == 1) {
        print_lcs(a_idx-1, b_idx);
    }
    else {
        print_lcs(a_idx, b_idx-1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 입력
    cin >> a >> b;
    int a_len = a.size();
    int b_len = b.size();

    for (int i = 0; i <= max(a_len, b_len); i++) {
        // 첫 줄의 길이는 0
        len[i][0] = 0;
        len[0][i] = 0;
    }


    // 2. DP
    for (int i = 0; i < a_len; i++) {
        for (int j = 0; j < b_len; j++) {
            // (j+1, i+1) 위치의 값을 업데이트할 예정
            // i와 j를 이용해서 ㅇㅇ

            if (a[i] == b[j]) { // 같으면 대각선 가리키게 하고, 길이 + 1
                dir[i+1][j+1] = 0;
                len[i+1][j+1] = len[i][j] + 1;
            }

            // 다르면, 더 큰 쪽을 바라보게 한다. 길이는 더 큰 쪽과 동일
            else if (len[i][j+1] > len[i+1][j]) {
                dir[i+1][j+1] = 1;  // 위쪽
                len[i+1][j+1] = len[i][j+1];
            }
            else {
                dir[i+1][j+1] = 2;  // 왼쪽
                len[i+1][j+1] = len[i+1][j];
            }
        }
    }


    // for (int i = 0; i <= a_len; i++) {
    //     for (int j = 0; j <= b_len; j++) {
    //         cout << dir[i][j] << "  ";
    //     }
    //     cout << "\n";
    // }

    // cout << "\n-----\n";

    // for (int i = 0; i <= a_len; i++) {
    //     for (int j = 0; j <= b_len; j++) {
    //         cout << len[i][j] << "  ";
    //     }
    //     cout << "\n";
    // }



    // 3. 출력
    // 길이
    cout << len[a_len][b_len] << "\n";

    // 문자열
    int a_idx = a_len; int b_idx = b_len;
    print_lcs(a_idx, b_idx);
    // while (1) {
    //     int a_idx = a_len; int b_idx = b_len;

    //     if (a_idx == 1 || b_idx == 1) break;
    //     // if (len[a_idx][b_idx] == 0) break;

    //     if (dir[a_idx][b_idx] == 0) {
    //         a_idx--; b_idx--;
    //         cout << a[a_idx];
    //     }
    //     else if (dir[a_idx][b_idx] == 1) {
    //         b_idx--;
    //     }
    //     else {
    //         a_idx--;
    //     }
    // }


    



    return 0;
}

