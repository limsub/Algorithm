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

// 2230
// 투 포인터

// 3% 틀

// 이따구로 풀면 안되는 이유는, st 하나를 고정시켜두고 en을 찾는 느낌으로 가야 하는데
// 얘는 그냥 st랑 en을 둘다 움직이고 있다.

// 근데 여전히 3%에서 틀린 이유는 잘 모르겠다....

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    // 1. 입력
    int N, M; cin >> N >> M;
    int a[N+1];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    // 2. 정렬
    sort(a, a + N);

    // 3. 투 포인터 알고리즘
    int st = 0; int en = 0; int m = 0x7FFFFFFF;

    //  - 1. 차이가 M보다 작다 -> en을 늘려서 M 이상인 첫 번째 지점을 찾는다.
    //  - 2. 차이가 M 이상이다 -> st를 늘려서 M보다 작아지는 지점을 찾는다.

    while (1) {
        // - 1.
        while (a[en] - a[st] < M && en <= N-1) {
            en++;
        }

        // 만약 en이 N-1을 초과한, 즉 배열의 범위 이상으로 갔으면 break
        // 이 경우, 지금 최솟값을 찾고자 하는 st에 대해 최솟값은 존재하지 않는다.
        if (en == N) { break; }



        // - 2.
        while (a[en] - a[st] >= M && st <= N-1) {
            // 사실상 st가 N-1인 경우는 en도 이미 N-1일 것이고, 
            // 그렇게 되면 a[en] == a[st]인 경우이다.
            // 그렇다면 M이 0인 케이스에 해당될 수 있나..?
            
            // 만약 M 이상이 되었다면, min 갱신
            m = min(a[en] - a[st], m);

            st++;
        }

        // 만약 st가 끝까지 도착했다면, break
        // 웬만하면 st가 N-2, en이 N-1에서 마무리 되고, en이 N 되면서 break 되겠지만, 
        // 혹시나 M == 0인 케이스 때문에 st가 N까지 증가할 가능성이 존재한다.
        if (st >= N) { break; }
    }

    cout << m;


    return 0;
}