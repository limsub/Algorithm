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

// 2461 대표 선수
// 각 열에 대해 st를 하나씩 두고, 여러 열 중 최솟값을 가지는 열의 st를 하나씩 증가시킴.


int arr[1010][1010];    // 입력 배열
int st[1010];           // st 요소 (각 열 i에 대응)


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    // 1. 입력
    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    // 2. 정렬
    for (int i = 0; i < N; i++) {
        sort(arr[i], arr[i] + M);
    }


    // 3. 투 포인터
    // 처음은 모든 st가 0
    int ans_d = 0x7F7F7F7F;
    while(1) {
        // 1. 각 열에 대해 st 위치의 값 중 가장 작은 값을 가지는 i를 찾는다.
        // 이 때, 계산을 위해 가장 큰 값도 같이 찾는다.
        int min_pos = 0;
        int min_value = 0x7F7F7F7F;
        int max_value = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i][st[i]] < min_value) {
                min_value = arr[i][st[i]];
                min_pos = i;
            }

            if (arr[i][st[i]] > max_value) {
                max_value = arr[i][st[i]];
            }
        }

        // 2. 이 때의 가장 큰 차이를 계산하고, 최솟값을 가지는 i열의 st를 증가시킨다
        int d = max_value - min_value;
        st[min_pos]++;

        // 3. 이 때의 가장 큰 차이를, 전체 중 가장 최솟값과 비교한다
        ans_d = min(d, ans_d);



        // // cout << "*******\n";
        // // cout << "min: " << min_value << "   max: " << max_value << "\n";
        // // for (int i = 0; i < N; i++) {
        // //     cout << st[i] << "  ";
        // // }
        // // cout << "\n";


        // cout << "*******\n";
        
        // 3. 만약, st[min_pos]가 N 배열 범위를 넘어갔다면, 더 이상 계산하는 것이 의미가 없다.
        if (st[min_pos] >= N) break;
    }
    
    cout << ans_d;

    return 0;
}