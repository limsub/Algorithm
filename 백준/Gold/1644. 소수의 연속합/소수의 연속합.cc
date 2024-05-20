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

// 1644 소수의 연속합
// 투포인터

// 90% 넘어서 런타임 에러 (OutOfBounds)
// - 이거 노린 케이스 : "N은 1부터 시작한다."
// => pn이 아예 없게 되는데, 그럼 pn[0]에 접근하면 에러 발생

int a[4000010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int N; cin >> N;

    if (N == 1) { cout << "0"; return 0;}
    

    // 1. 소수 찾아서 배열에 때려박기 - o(n)? o(nlogn)? o(n2)?
    // - 에라토스테네스의 체 시간복잡도 몇인지 찾아보기.
    vector<int> pn;
    for (int i = 2; i <= N; i++) {
        for (int j = 2; j * i <= N; j++) {
            a[i * j] = 1;
        }
    }

    for (int i = 2; i <= N; i++) {
        if (a[i] == 0) {
            pn.push_back(i);
        }        
    }

    int pn_size = pn.size();

    // for (int k = 0; k < pn_size; k++) {
    //     cout << pn[k] << " ";
    // }


    // 2. 소수 배열에서 투 포인터 진행 - o(n)
    int ansCnt = 0;
    // - 합이 N보다 커지면 stop
    // - 합이 N이 되면 cnt++;

    int en = 0;
    int sum = pn[0];    // pn[st] ~ pn[en] 합 저장
    for (int st = 0; st < pn_size; st++) {

        while (sum < N && en < pn_size) {
            en++;
            if (en != pn_size) sum += pn[en];
        }

        // en이 끝까지 갔으면 break
        if (en == pn_size) break;

        // N을 만족했으면 ansCnt++
        if (sum == N) {
            // cout << st << " , " << en << "\n";
            ansCnt++;
        }

        // 다음 넘어갈 때 pn[st] 빼주기
        sum -= pn[st];
    }
    
    cout << ansCnt;


    return 0;
}