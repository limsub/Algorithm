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



// 11000 강의실 배정
// 우선순위 큐

// 1. 정렬 기준 - "회의 시작 시간"
// 2. 우선순위 큐 - "회의 종료 시간"

bool compare(pair<int, int> x, pair<int, int> y) {

    if (x.first == y.first) {
        return x.second <= y.second;
    }

    return x.first < y.first;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int N; cin >> N;

    vector< pair<int, int> > arr;
    priority_queue< int, vector<int>, greater<int> > pq;    // 가장 작은 값이 우선순위가 된다.

    for (int i = 0; i < N; i++) {
        int s, t; cin >> s >> t;
        arr.push_back(make_pair(s, t));
    }

    // '회의 시작 시간' 기준으로 정렬
    sort(arr.begin(), arr.end());

    // 1. 맨 처음 시작하는 회의(의 종료 시간) 삽입
    pq.push(arr[0].second);

    for (int i = 1; i < N; i++) {
        // 종료 시간 삽입.
        pq.push(arr[i].second);

        // top의 종료 시간이 새롭게 넣는 회의의 시작 시간보다 작거나 같으면, 같은 회의실에서 진행 가능
        if (pq.top() <= arr[i].first) {
            pq.pop();
        }
    }

    cout << pq.size();


    
    return 0;
}