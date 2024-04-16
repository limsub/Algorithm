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
// #include <pair>
// #include <bits/stdc++.h>



// 11279 최대 힙
// 우선순위 큐


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int N; cin >> N;

    priority_queue<int> pq;

    while (N--) {
        int x; cin >> x;

        if (x == 0) {
            if (pq.empty()) {
                cout << 0 << "\n";
            }
            else {
                cout << pq.top() << "\n";
                pq.pop();   
            }
        }
        else {
            pq.push(x);
        }
    }
    
    return 0;
}