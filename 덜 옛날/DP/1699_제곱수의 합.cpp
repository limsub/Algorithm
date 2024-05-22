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

// 1699 제곱수의 합


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    int N;
    cin >> N;

    int d[100001] = {0, };
    d[1] = 1;

    vector<int> sqrtNum;
    sqrtNum.push_back(1);

    for (int i = 2; i <= N; i++) {


        // 만약 제곱수라면 d에 1 넣고, sqrtNum에 push해주고 continue
        int root = sqrt(i);
        if (root * root == i) {
            d[i] = 1;
            sqrtNum.push_back(i);
            continue;
        }
        

        // 제곱수가 아니면, d 값을 계산한다.
        int minCnt = 0x7F7F7F7F;
        // i보다 작은 제곱수와의 조합을 모두 고려한다
        for (int j = 0; j < sqrtNum.size(); j++) {
            int newAns = 1 + d[i - sqrtNum[j]];
            if (newAns < minCnt) { minCnt = newAns; }
        }

        d[i] = minCnt;
    }

    cout << d[N] << "\n";

    return 0;
}