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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    
    int N;
    cin >> N;

    int d[1000001] = {0, };
    d[0] = 0;
    d[1] = 1;


    // 1. N이 양수, 0, 음수 중 무엇인지 체크
    if (N > 0) {

        for (int i = 2; i <= N; i++) {
            d[i] = (d[i-1] + d[i-2]) % 1000000000;
        }

        cout << "1" << "\n";
        cout << d[N] << "\n";
    }
    else if (N < 0) {
        N = -N;


        for (int i = 2; i <= N; i++) {
            d[i] = (d[i-1] + d[i-2]) % 1000000000;
        }

        
        
        if (N % 2 == 0) {
            // 음수 출력
            cout << "-1" << "\n";
            cout << d[N] << "\n";
        }
        else {
            // 양수 출력
            cout << "1" << "\n";
            cout << d[N] << "\n";

        }
    }
    else {  // N == 0
        cout << "0" << "\n";
        cout << "0" << "\n";
        return 0;
    }
    
    return 0;
}