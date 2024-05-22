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
    cin.tie(NULL);
    // cout.tie(NULL);

    int N;
    cin >> N;
    // scanf("%d", &N);

    priority_queue<int> pQ;
    vector<int> result;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        // scanf("%d", &x);

        if (x == 0) {
            if (pQ.empty()) {
                result.push_back(0);
                // cout << 0 << endl;
            } else {
                result.push_back(pQ.top());
                // cout << pQ.top() << endl;
                pQ.pop();
            }
        } else {
            pQ.push(x);
        }

    }


    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << "\n";
    }
    return 0;
}