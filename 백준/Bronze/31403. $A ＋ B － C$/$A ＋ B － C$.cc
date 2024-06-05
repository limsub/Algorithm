#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int a, b, c; cin >> a >> b >> c;

    cout << a + b - c << "\n";


    string s = to_string(a) + to_string(b);
    int k = stoi(s);

    cout << k - c;

}

