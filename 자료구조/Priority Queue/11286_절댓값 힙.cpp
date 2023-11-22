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
// #include <bits/stdc++.h>


// 11286 절댓값 힙


int main() {

    int N;
    cin >> N;

    priority_queue<pair<long long, long long>, vector< pair<long long, long long> >, greater< pair<long long, long long> > > pQ;

    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;

        if (x == 0) {
            if (pQ.empty()) {
                cout << 0 << endl;
            }
            else {
                long long top = pQ.top().second;
                pQ.pop();
                cout << top << endl;
            }
            
        }
        else {
            long long y = (x < 0) ? -x : x;
            pQ.push(make_pair(y, x));
        }

        


    }

    return 0;
}