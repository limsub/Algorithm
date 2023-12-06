#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <cmath>
#include <set>
using namespace std;
#include <string.h>
// #include <bits/stdc++.h>

// 2240 자두나무
int t[1001];
int d1[1001];
int w1[1001];
int d2[1001];
int w2[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    // 입력
    int T, W;
    cin >> T >> W;
    for (int i = 1; i <= T; i++) {
        cin >> t[i];
        d1[i] = -1;
        d2[i] = -1;
    }

    t[0] = 1;

    d1[0] = 0;
    d2[0] = 0;

    for (int i = 1; i <= T; i++) {
        
        
        int maxD1 = -1;
        int maxD2 = -1;
        
        
        for (int j = 0; j < i; j++) {

            // 이동해서 먹어야 하는 경우 -> d1에 저장
            if (t[j] != t[i]) {
                
                // d1에 있는 값으로 비교
                if (w1[j] < W && d1[j] != -1) {
                    int newD = d1[j] + 1;

                    if (newD > d1[i]) { d1[i] = newD; w1[i] = w1[j] + 1; }
                }


                // d2에 있는 값으로 비교
                if (w2[j] < W && d2[j] != -1) {
                    int newD = d2[j] + 1;

                    if (newD > d1[i]) { d1[i] = newD; w1[i] = w2[j] + 1; }
                }
            }


            // 이동하지 않고 먹는 경우 -> d2에 저장
            else {

                // d1에 있는 값으로 비교
                if (d1[j] != -1) {
                    int newD = d1[j] + 1;

                    if (newD > d2[i]) { d2[i] = newD; w2[i] = w1[j]; }
                }

                // d2에 있는 값으로 비교
                if (d2[j] != -1) { 
                    int newD = d2[j] + 1;

                    if (newD > d2[i]) { d2[i] = newD; w2[i] = w2[j]; }
                }


            }


        }
    }

    // sort(d1, d1 + T+1);
    // sort(d2, d2 + T + 1);

    // cout << max(d1[T], d2[T]) << "\n";

    for (int i = 0; i < T; i++) {
        printf("t : %d  d1[%d] : %d   w1[%d] : %d   ", t[i],  i, d1[i], i, w1[i]);
        printf("d2[%d] : %d   w2[%d] : %d  \n", i, d2[i], i, w2[i]);
    }

    return 0;
}