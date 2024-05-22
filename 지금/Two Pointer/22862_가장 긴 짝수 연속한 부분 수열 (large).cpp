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

// 22862 가장 긴 짝수 연속한 부분 수열 (large)

// 투 포인터
// st, en 이용해서 중간 연속 수열 찾는다.
//  - 연속한 짝수 수열, 단 홀수 K개까지는 봐줌


// 82% 틀 -> 1 1 인풋 주면 결과 -1 나옴
// -> K가 N보다 큰 경우, 그냥 다 음수 나와버림
// 사실상 K가 N보다 크다면, 그냥 배열 내의 짝수 개수 리턴해야 한다.


// 91% 틀
// -> K가 N보다 클 때의 예외사항이 아니라, "K가 배열 내의 홀수 개수보다 크거나 같을 때" 로 예외처리 해야 한다.
// 내가 구현한 코드 자체가 K+1까지 다 써먹을 때까지 하고 있기 때문에.

int arr[1000010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    // 1. 입력
    int N, K; cin >> N >> K;

    int evenCnt = 0;
    int oddCnt = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i]; 

        if (arr[i] % 2 == 0) evenCnt++;
        else oddCnt++;
    }


    // - 예외 : K가 N보다 크거나 같은 경우 -
    // => 수정. K가 N 안에 있는 홀수 개수보다 크거나 같은 경우
    if (K >= oddCnt) { 

        // arr 내의 짝수 개수 리턴 후 끝내기
        int evenCnt = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i] % 2 == 0) evenCnt++;
        }

        cout << evenCnt;
        
        return 0; 
    }

    // 2. 투 포인터
    int en = 0;
    int d = 0;
    int odd_cnt = (arr[0] % 2 == 0) ? 0 : 1;
    for (int st = 0; st < N; st++) {
        
        // "K개까지 지울 수 있다"
        // -> 마지막 K까지 어쨌든 써먹어야 한다
        // -> K+1이 되기 직전에 stop해야 해.
        // K+1이 되는 위치가 en. 즉, st ~ en-1까지의 길이를 계산해야 함.

        // 예외사항 : K가 N보다 크다면? K개를 써먹을 수가 없어.
        // 이러면 d가 무조건 0으로만 잡히기 때문에, 정답은 -K만 나오게 된다.
        // -> en == N으로 break될 때, 만약 K >= N이라면, d = N이 되게 하는게 아니라, 그 안에 짝수 개수 리턴
        // 그렇게 하지 말고, 아예 처음 인풋 받을 때 K가 N보다 크면 짝수개수 계산해서 리턴하고 끝내

        // while문 : 홀수 개수가 K개를 넘어가면 아웃
        while(odd_cnt <= K && en < N) {
            en++;

            if (en != N) {
                // arr[en]이 짝수인지 홀수인지 확인
                if (arr[en] % 2 == 0) {
                    // 짝
                    
                }
                else {
                    // 홀
                    odd_cnt++;
                }
            }
        }

        // en이 배열 넘어가면 break
        if (en == N) break;

        // 연속한 배열 중 가장 긴 길이 저장
        // 현재 en은 홀수 위치에 있다. 즉, en - st + 1이라고 하면 안된다.
        // cout << st << " -- " << en << "\n";
        d = max(d, en - st);    


        // arr[st]가 홀수였으면 다음 넘어가기 전에 odd_cnt --;
        if (arr[st] % 2 != 0) {
            odd_cnt--;
        }
    }



    cout << d - K;




    return 0;
}