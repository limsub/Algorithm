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


// 18870 좌표 압축

    // 초기 세팅 필요
    // 1. 정렬 2. 중복된 원소 제거

int arr[1000010];
int arr2[1000010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    // 1. 입력
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;

        arr[i] = x;
        arr2[i] = x;
    }

    // 2. 정렬
    sort(arr, arr + N);

    // 2.5 중복 제거
    int *new_end = unique(arr, arr + N);
    int new_length = new_end - arr;


    // 3. 좌표 압축?
    // x1' : x1보다 작은 좌표들의 개수 
    //  = x1이 등장하는 가장 작은 인덱스
    

    for (int i = 0; i < N; i++) {
        int num = arr2[i];
        int idx = lower_bound(arr, arr + new_length, num) - arr;

        cout << idx << " ";

        // ansArr.push_back(idx);
    }
     

    return 0;
}