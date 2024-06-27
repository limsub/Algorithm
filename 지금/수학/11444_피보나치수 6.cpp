#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long

// 11444 피보나치 수 6

map<ll, ll> m;
ll d = 1000000007;

ll fb(ll n) {

    

    if (m[n]) return m[n];



    
    if (n % 2 == 0) {
        // 짝
        
        return m[n] = ( fb(n/2) * ( fb(n/2 + 1) + fb(n/2 - 1) ) ) % d;
    }

    else {
        // 홀
        return m[n] =  ( ( (fb((n+1)/2)) * (fb((n+1)/2)) ) % d + ( ( fb((n-1)/2) ) * ( fb((n-1)/2) ) ) % d ) % d;
    }
    
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    m[0] = 0;
    m[1] = 1;
    m[2] = 1;

    ll n; cin >> n;

    cout << fb(n);


    return 0;
}

