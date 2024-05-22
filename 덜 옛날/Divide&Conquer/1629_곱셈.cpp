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

long long A, B, C;

long long power(int b) {

    if (b == 0) { return 1; }
    if (b == 1) { return A % C; }

    long long k = power(b/2);
    if (b % 2 == 0) { return k * k % C; }
    else { return k * k % C * A % C; }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> A >> B >> C;

    cout << power(B) << "\n";
}