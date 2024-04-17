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


// 13975 파일 합치기 3

// 1% 틀.

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int T; cin >> T;

    while (T--) {

        priority_queue<long long , vector<long long >, greater<long long > > pq;
        int K; cin >> K;

        for (int i = 0; i < K; i++) {
            int x; cin >> x;

            pq.push(x);
        }


        // 가장 작은 것 2개를 뽑아서 더한다. 더한 값은 그대로 pq에 넣어준다.
        long long  sum = 0;
        while (pq.size() > 1) {
            long long n1 = pq.top(); pq.pop();
            long long n2 = pq.top(); pq.pop();

            long long n_sum = n1 + n2;

            // cout << n1 << " *** " << n2 << "\n";

            sum += n_sum;
            pq.push(n_sum);
        }

        cout << sum << "\n";

    }



    return 0;
}