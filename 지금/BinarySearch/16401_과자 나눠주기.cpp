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


// 16401 과자 나눠주기
// 이분탐색

// DivisionByZero Error 발생
// mid가 0인 경우는 뭐냐 도대체
// => st가 1부터 시작해야해.

int N, M;
int arr[1000010];


int bs(int large) {
    int st = 1; 
    int en = large;

    int ans;

    while (st <= en) {

        int mid = (st + en)/2;
        
        int q = 0;
        for (int i = 0; i < M; i++) {
            q += arr[i]/mid;
        }


        if (st == en) {
            if (q < N) ans = en - 1;
            else ans = en;

            break;
        }

        else {
            if (q >= N) st = mid + 1;
            else en = mid;
        }
    }

    return ans;

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 


    // 1. 입력
    cin >> N >> M;
    for (int i = 0; i < M; i++) cin >> arr[i];

    int l = *max_element(arr, arr + M);

    // 모든 조카에게 같은 길이의 막대과자를 나눠줄 수 없다...?

    // 2. binary search
    int ans = bs(l);
    if (ans == -1) cout << "0";
    else cout << ans;
    


    return 0;
}