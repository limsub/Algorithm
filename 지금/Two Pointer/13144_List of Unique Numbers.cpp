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


// 13144 List of Unique Numbers
// 투 포인터

// 현재 배열에 포함된 수를 판단하는 배열 생성 - bool isArr[100010]
// 배열에 포함된 수가 나올 때까지 en 늘려가기


// 10% 틀. -> ansCnt는 10만 x 10만이라 int로 안됨. long long 필요


bool isArr[100010];
int arr[100010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    // 1. 입력
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }


    // 2. 투 포인터
    int en = 1;
    isArr[arr[0]] = true;
    long long ansCnt = 0;
    for (int st = 0; st < N; st++) {
        while (!isArr[arr[en]] && en < N) {

            isArr[arr[en]] = true;  // 방문 -> 배열에 포함됨.
            
            en++;
        }

        if (en == N) {
            // 현재 st부터 N-1까지 N과의 차를 더해야 함.
            // (N - st) + (N - (st+1)) + ... + (N - (N-1))

            for (int k = st; k <= N-1; k++) {
                ansCnt += (N - k);
            }

            break;
        }

        // 중복된 수가 없는 최대 길이를 통해 경우의 수를 계산한다.
        ansCnt += (en - st);

        // st 넘어가기 전에 isArr 풀어주기
        isArr[arr[st]] = false;
    }

    cout << ansCnt;

    return 0;
}