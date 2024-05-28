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
#include <map>
// #include <pair>
// #include <bits/stdc++.h>


// 1822 차집합
// 이분탐색

// nlogn 예상

// 13% 틀. 0 출력 예외처리 안함
// 30% 틀. b에다가 N으로 잘못 씀

int a[500010];
int b[500010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < M; i++) cin >> b[i];

    sort(a, a + N); sort(b, b + M);

    vector<int> ans;
    for (int i = 0; i < N; i++) {
        int x = a[i];

        if (!binary_search(b, b + M, x)) {
            ans.push_back(x);
        }
    }

    if (ans.empty()) {
        cout << "0";
    }
    else {
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
    }
    
    

    return 0;
}