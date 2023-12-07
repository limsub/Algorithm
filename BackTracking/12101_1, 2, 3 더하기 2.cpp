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

// 15988 1, 2, 3 더하기 2

int n, k;

int cnt = 0;

vector<int> ans;

void backTracking(int sum) {
    if (sum == n) {
        cnt ++;
        if (cnt == k) {
            // print
            cout << ans[0];
            for (int t = 1; t < ans.size(); t++) {
                cout << "+" << ans[t];
            }
        }
        return;
    }


    for (int i = 1; i <= 3; i++) {
        if (sum + i <= n) { 
            int x = i;
            ans.push_back(x);
            backTracking(sum + x);
            ans.pop_back();
        }
    }

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


    cin >> n >> k;

    backTracking(0);

    if (cnt < k) {
        cout << -1 << "\n";
    }

    return 0;
}