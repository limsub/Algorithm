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


// 20366 같이 눈사람 만들래?

// 투 포인터

// 바킹독 풀이.

// i1 j1 j2 i2
// a[i1] + a[i2]와 a[j1] + a[j2]가 근접한 (j1, j2) 쌍을 찾는다.

// i1만 정해진 loop을 돌고, i2, j1, j2는 그 때마다 새롭게 설정된다.

// 결과적으로, i1과 i2를 픽스해둔 상태에서,
// j1과 j2를 각각에 맞는 초기 위치에서 시작하고
// 만약 a[i1] + a[i2]가 더 크게 되면, j1을 증가시킴으로써 a[j1] + a[j2] 값을 키우고
// a[i1] + a[i1]가 더 작게 되면, j2를 감소시킴으로써 a[j1] + a[j2] 값을 줄인다.


// 천재 아냐.....?



int arr[610];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
    // 1. 입력
    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];


    // 2. 정렬
    sort(arr, arr + N);


    // 3. 투 포인터
    int min_ans = 0x7F7F7F7F;
    for (int i1 = 0; i1 < N; i1++) {
        for (int i2 = i1 + 3; i2 < N; i2++) {   // i2는 i1+3 ~ N

            int j1 = i1 + 1;
            int j2 = i2 - 1;

            while (j1 < j2) {
                min_ans = min(min_ans, abs(arr[i1] + arr[i2] - arr[j1] - arr[j2]));

                if (arr[i1] + arr[i2] >= arr[j1] + arr[j2]) {
                    // j 묶음 애들이 더 커져야 한다.
                    j1++;
                }
                else {
                    // j 묶음 애들이 더 작아져야 한다
                    j2--;
                }
            }
        }
    }

    cout << min_ans;
    

    return 0;
}