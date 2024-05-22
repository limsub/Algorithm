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

// 2011 암호 코드
// 14% 틀
// 나머지 계산 + 0에 대한 예외처리. 어우 쉽지 않았다.

long long  d[5002];

int check(char first, char second) {

    int firstInt = first - '0';
    int secondInt = second - '0';

    int checkNum = firstInt * 10 + secondInt;

    if (firstInt == 0) { return 1; }
    else if (checkNum > 26) { return 2; }
    else { return 3; }


    // if (checkNum >= 10 && checkNum <= 26) { return true; }
    // else { return false; }
}

bool checkZero(char c) {
    int cNum = c - '0';
    if (cNum == 0) { return true; }
    else { return false; }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    // 초기화 및 입력
    string s;
    cin >> s;
        
    // string과 d[]의 인덱스가 반대로 가기 때문에 사이즈 저장
    int size = s.size();

    // d[i]를 계산할 때
    // s[size - i]와 s[size - i + 1] 필요

    // 3가지로 나눠야 해 (return int)
    // 1. 앞 자리 수가 0일 때 -> d[i] = 0 (0 이외에 한 자리 수는 모두 하나로써 가치가 있다)
    // 2. 앞 자리 수 + 뒷 자리 수 가 26 초과인 경우 -> d[i] = d[i-1];
    // 3. else (10 이상 26 이하) -> d[i] = d[i-1] + d[i-2];
    

    // i == 1; - 예외 : 0일 때....
    if (checkZero(s[size - 1])) { d[1] = 0; }
    else { d[1] = 1; }

    // i == 2;
    int testK = check(s[size-2], s[size-2+1]);
    if (testK == 1) { d[2] = 0; }
    else if (testK == 2) { d[2] = d[1]; }
    else { d[2] = d[1] + 1; }

    // i >= 3;
    for (int i = 3; i <= size; i++) {
        int testP = check(s[size - i], s[size - i + 1]);

        if (testP == 1) { d[i] = 0; }
        else if (testP == 2) { d[i] = d[i-1] % 1000000; }
        else { 
            d[i] = d[i-1] % 1000000 + d[i-2] % 1000000;
            d[i] = d[i] % 1000000;
        }
    }

    cout << d[size];

    return 0;
}