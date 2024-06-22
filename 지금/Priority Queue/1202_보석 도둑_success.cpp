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


// 1202 보석 도둑
// 우선순위큐, 그리디, 정렬

// pq의 용도를 너무 1차원적으로만 생각하고 살았다
// pq를 여러 번 활용할 수 있다는 점을 알고 가자.

// C를 오름차순으로 정렬.
// <M, V>도 오름차순으로 정렬. (M 기준 오름차순.)

// pq 선언 : (V 큰거. V 같으면 M 작은거)

// C가 작은 것부터 loop 시작
// <M, V> 배열 돌면서 C에 들어갈 수 있는 것들 pq에 삽입.
// 다 삽입했으면, pq의 top()을 해당 C에 넣는다. 즉 pop()으로 빼주기

// 어차피 작은 것들이기 때문에 남은 애들은 다음 C에서 그대로 재활용 ㄱㄱ


struct Compare {
    bool operator() (const pair<int, int> &p1, const pair<int, int> &p2) {
        if (p1.second == p2.second) return p1.first > p2.first;

        return p1.second < p2.second;
    }
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    vector< pair<int, int> > v;
    vector<int> c;
    priority_queue< pair<int,int>, vector< pair<int, int> >, Compare> pq;


    // 1. 입력
    int N, K; cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    for (int i = 0; i < K; i++) {
        int x; cin >> x;
        c.push_back(x);
    }


    // 2. sort
    sort(v.begin(), v.end());
    sort(c.begin(), c.end());
    

    // 3. loop 시작
    int j = 0;
    long long sum = 0;
    for (int i = 0; i < c.size(); i++) {    // C가 작은 것부터 loop 시작
        int c_size = c[i];

        // c_size에 넣을 수 있는 것들 모두 pq에 삽입
        while (j < v.size() && v[j].first <= c_size) {
            pq.push(make_pair(v[j].first, v[j].second));
            j++;
        }

        // pq에서 가장 V가 큰 걸 Ci에 사용
        if (!pq.empty()) {
            int max_v = pq.top().second; pq.pop();
            sum += max_v;
        }
        
    }

    cout << sum;


    return 0;
}