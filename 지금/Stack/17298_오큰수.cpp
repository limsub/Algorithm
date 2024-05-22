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



// 17298 오큰수
// 스택


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    // 1. 입력
    int N; cin >> N;
    vector<int> arr;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }

    // 이중 for문 -> 반드시 시간초과

    vector<int> ans(N, -1);
    stack<int> tmp;

    for (int idx = 0; idx < N; idx++) {

        // 1. 스택에 뭐(인덱스)가 있고, 
        // 2. 그 인덱스에 해당하는 arr 값이, 현재 idx보다 작은 경우
        while(!tmp.empty() && arr[tmp.top()] < arr[idx]) {
            ans[tmp.top()] = arr[idx];
            tmp.pop();
        }
        

        // idx를 스택에 추가
        tmp.push(idx);
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }

    
    return 0;
}