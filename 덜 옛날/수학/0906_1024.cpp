#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>

// 1024 수열의 합

// 등차수열 공식 사용 -> 굿노트

int main() {

    int N, L;
    cin >> N >> L;

    int a1 = -1; // 첫 항
    int K = L;  // 길이 100 >= K >= L

    while (K <= 100) {

        // K가 짝수
        if (K % 2 == 0) {
            int k = K / 2;

            if (  (N % k == 0 && (k != 1)) || ( N % k == 0 && k == 1 && N%2 != 0)  ) {
                //cout << K << endl;
                int a = N / k;

                if (a % 2 != 0) {
                    a1 = (N/K) - ((K-1)/2);
                    break;
                }
            }


        }

        // K가 홀수
        if (K % 2 != 0) {
            if (N % K == 0) {
                a1 = (N/K) - ((K-1)/2);
                break;
            }
        }

        
        K++;
    }

    if (a1 < 0) {
        cout << -1 << endl;
    }
    else {
        for (int i = a1; i < a1 + K; i++) {
            cout << i << " ";
        }
    }

    // cout << a1 << endl;
    // cout << K << endl;

    return 0;
}