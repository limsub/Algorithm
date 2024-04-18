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


// 1655 가운데를 말해요

// q1 (min heap) q2 (max heap) min 활용
// q1과 q2의 size 차이가 최대 1까지만 나도록 유지

// 2% 틀. -> 오타남. 바로 sucess

// pq1.size(), pq2.size() 각자 출력할 때는 정상으로 나오는데, 
// pq1.size() - pq2.size() 출력하면 맛이 간다. 이유 분석해보기

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int N; cin >> N;

    priority_queue<int, vector<int>, greater<int> > pq1;
    priority_queue<int, vector<int>, less<int> > pq2;
    int mid;

    int x1; cin >> x1;
    pq2.push(x1);
    mid = x1;

    cout << mid << "\n";

    for (int i = 1; i < N; i++) {
        // cout << "입력 : " << "\n";
        int x; cin >> x;

        // 기존 mid 값과 비교해서 어떤 큐에 넣을지 결정
        if (x > mid) { pq1.push(x); }
        else { pq2.push(x); }

        int pq1_size = pq1.size();
        int pq2_size = pq2.size();

        // cout << "size : " << pq1.size() << "  " << pq2.size() << "\n";

        // pq1과 pq2의 size 차이가 2 이상 나면 조절해주기.
        if (pq1_size - pq2_size > 1) {
            pq2.push(pq1.top());
            pq1.pop();
        }

        if (pq2_size - pq1_size > 1) {
            pq1.push(pq2.top());
            pq2.pop();
        }

        // mid 업데이트
        if (pq1.size() > pq2.size()) {
            mid = pq1.top();
        } 
        else {
            // 둘이 같을 땐 더 작은거 하기 때문
            mid = pq2.top();
        }

        cout << mid << "\n";
    }



    return 0;
}