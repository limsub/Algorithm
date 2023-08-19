#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>


// 1747

// 77%에서 틀림 -> 소수 loop 돌 때 "<= sqrt(N)" 등호 붙여줘야함

bool isPel(int x) {
    string s = to_string(x);

    int l = s.length();

    // l이 1인 경우 -> true
    if (l == 1) {
        return true;
    }

    bool flag = true;

    if (l % 2 == 0) {
        for (int i = 0; i <= (l-1)/2; i++) {
            if (s[i] != s[l-1-i]) {
                flag = false;
            }
        }
    }
    else {
        for (int i = 0; i <= (l-1)/2 - 1; i++) {
            if (s[i] != s[l-1-i]) {
                flag = false;
            }
        }
    }

    // cout << s[0] << s[2] << endl;

    // cout << s.length() << endl;

    return flag;
}

bool isPrime(int x) {

    if (x == 1 || x == 4) {
        return false;
    }
    else if (x == 2 || x == 3) {
        return true;
    }
    else {
        for (int i = 2; i <= sqrt(x); i++) {
            if ( x % i == 0) {
                return false;
        }
    }
    }
    
    return true;
}


int main() {

    int N;
    cin >> N;


    int start = N;

    while(1) {

        if (isPel(start) && isPrime(start)) {
            break;
        }

        start++;
    }

    cout << start << endl;


    return 0;
}