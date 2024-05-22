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

// 20922 겹치는 건 싫어

// 42% 틀.
// -> d = max(d, en - st); if (en == N) break; 두 코드 순서 주의하기.
// en이 범위를 넘어가더라도, d를 계산하는 데 사용할 수 있다.


int v[100010];  // 각 숫자가 몇 번 사용되었는지
int arr[200010];    // 입력받은 수열 저장

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    // 1. 입력
    int N, K; cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];


    // 2. 투 포인터
    int d = 0;
    int en = 1;
    v[arr[0]] = 1;
    for (int st = 0; st < N; st++) {
        while (v[arr[en]] < K && en < N) {
            // 방문했으면 v++
            v[arr[en]]++;

            en++;   // en 다음으로 넘긴다.
        }

        // 최대 거리 저장 (en 위치가 배열 벗어나도 상관 없기 때문에, 아래 조건보다 위에 써준다)
        d = max(d, en - st);

        if (en == N) break;

        // st를 넘기기 전 v--
        v[arr[st]]--;
    }

    cout << d;

    return 0;
}