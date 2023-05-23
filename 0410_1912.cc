// #1912
// maximum 부분합 구하기 -> 알고리즘 시간에 n^3, n^2, n자리 시간으로 배웠음
// 그 중 O(n)짜리로 구현.
// 모든 값이 음수인 경우는 따로 케이스를 나눠서 해결

#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <list>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {

    int N;
    vector<int> arr(100001);
    cin >> N;

    int minusCheck = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i] > 0) {
            minusCheck = 1;
        }
    }

    if (minusCheck == 0) {
        int maxNum = arr[0];
        for (int i = 0; i < N; i++) {
            maxNum = max(maxNum, arr[i]);
        }
        printf("%d", maxNum);
    }



    else {
        int thisSum = 0, maxSum = 0;

        for (int i = 0; i < N; i++) {
            thisSum += arr[i];

            if (thisSum < 0) {
                thisSum = 0;
            }

            maxSum = max(maxSum, thisSum);
        }
        printf("%d", maxSum);
    }
    
    return 0;
}