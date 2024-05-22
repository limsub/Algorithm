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

// 2075 N번째 큰 수

// 다 우선순위큐에 때려박고 4번 pop -> top 출력 => 메모리 초과
// N개씩만 push, pop을 반복한다.

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int N; cin >> N;

    priority_queue<int, vector<int>, greater<int> >  pq;

    // 처음 N개 추가
    for (int j = 0; j < N; j++) {
        int x; cin >> x;
        pq.push(x);
    }

    // 이후에는 N개 추가 -> 삭제 반복
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x; cin >> x;
            pq.push(x);
        }

        for (int j = 0; j < N; j++) {
            pq.pop();
        }
    }


    cout << pq.top() << "\n";


    return 0;
}