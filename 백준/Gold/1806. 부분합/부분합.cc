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

// 1806 부분합
// 투포인터

// 합이 S 이상인 것 중 길이가 가장 짧은 것.
// (인덱스 차이를 저장해야 함.)

// 1. 정렬하고
// 2. st 고정시키고 en 증가.


// 1% 틀.

int n, s;
int arr[100010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 


    // 1. 입력
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> arr[i];


    // 2. 정렬
    // sort(arr, arr + n);


    // 3. 투 포인터
    int en = 1;
    int sum = arr[0];    
    // sum에는 arr[st] + ... + arr[en-1] 까지의 값이 들어간다.(?)

    int d = 100010 /*n + 10*/; // 인덱스 차이를 저장
    for (int st = 0; st < n; st++) {
        // 누적합이 s 이상이 될 때까지 en을 증가시킨다.
        while (sum < s && en <= n-1) {
            sum += arr[en];
            en++;
            // 현재 en 위치의 값을 더하고, en은 플러스
            // => 현재 sum에는 st ~ en-1까지가 더해져 있다.
        }

        // // 만약 en이 인덱스 범위 밖으로 벗어났다면, 해당 st에 대해 합을 넘기는 en은 존재하지 않는다.
        // if (en == n) break;

        // 만약 en이 이미 인덱스 범위 밖으로 벗어났는데, 또 플러스를 해야 한다 -> 그럼 더이상 만들어 줄 수가 없어
        if (en == n && sum < s) {
            break;
        }


        d = min(d, en - st);


        // 다음 loop으로 갈 때, st위치의 수는 빠진다.
        sum -= arr[st];
    }

    if (d == 100010) { 
        cout << "0";
    } else {
        cout << d;
    }
    
    



    return 0;
}