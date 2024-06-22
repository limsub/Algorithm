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

// 2295 세 수의 합

// https://codingnotes.tistory.com/173 참고


// x + y + z = w 가 되는 걸 찾기 위함.
// x + y를 싹 저장시켜두고, 
// w - z를 탐색하며 저장된 배열에 있는지 확인하는 로직....

// 천잰가

int arr[1010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    // 1. 입력
    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];



    // 3. x + y 저장
    vector<int> sum_v;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sum_v.push_back(arr[i] + arr[j]);
        }
    }


    // 2. 정렬
    sort(arr, arr + N);
    sort(sum_v.begin(), sum_v.end());



    // 4. w - z 탐색
    for (int i = N-1; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            int n = arr[i] - arr[j];

            if (binary_search(sum_v.begin(), sum_v.end(), n)) {
                cout << arr[i]; 
                return 0;
            }


        }
    }


    return 0;
}