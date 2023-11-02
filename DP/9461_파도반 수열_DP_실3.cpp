#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>

// 9461 파도반 수열 - DP

// 틀린 이유 - int 대신 long long 사용 (디피할 때 자주 나오는 듯 하다))

int main() {

    // 먼저 계산해서 넣어둠
    long long arr[101];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;
    arr[4] = 2;
    arr[5] = 2;

    for (int i = 6; i < 101; i++) {
        arr[i] = arr[i-1] + arr[i-5];
    }



    int T;
    cin >> T;

    vector<long long> ansArr;
    for (int i = 0; i < T; i++) {

        int N;
        cin >> N;

        ansArr.push_back(arr[N]);

        
    }

    for (int i = 0; i < ansArr.size(); i++) {
        cout << ansArr[i] << endl;
    }


    return 0;
}