#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>


// 1016
// % 나오기도 전에 틀림
// long long으로 바꾸니까 1%에서 시간초과 -> 2중 loop이 문제일 것 같음 -> 이것도 에라토스테네스의 체..?
// 에라토스테네스로 하니까 런타임 에러(bad alloc)..?
// 다 longlong으로 바꿔줬는데도 1%에서 런타임 에러(bad alloc)..
// 구글링해보니까 bad alloc은 힙 메모리가 터졌다는 뜻.. -> 배열 크기가 문젠가..? 아아 min과 max의 차이가 백만으로 정해져 있었다
// 배열 크기 조정까지 했지만 시간초과 (% 나오지도 않음)


int main() {

    long long minNum, maxNum;
    cin >> minNum >> maxNum;

    vector<long long> arr(maxNum - minNum + 1, 0);
    // 0번째 인덱스       = minNum
    // 1               = minNum + 1
    // maxNum - minNum = maxNum
    

    // minNum = 17, maxNum = 25
    // -> arr[0], arr[8]



    // 1.
    // vector<long long> s;
    for (long long i = 2; i <= sqrt(maxNum); i++) {
      //  s.push_back(i*i);


        long long k = i * i;

        // 1. 일단 minNum보다 크거나 같은 가장 작은 배수까지 올리자
        int p = k;
        while (p < minNum) {
            p += k;
        }

        // 2. p부터 maxNum 전까지 배열의 값들을 -1로 바꿔줌.
        //      배열 인덱스 주의. p - minNum으로 접근
        for (int j = p; j <= maxNum; j += k) {
            arr[j - minNum] = -1;
        }
    }

    // 2.

    long long cnt = maxNum - minNum + 1;


    for (long long x = minNum; x <= maxNum; x++) {

        if (arr[x - minNum] == -1) {
            cnt--;
        }

        // for (long long j = 0; j < s.size(); j++) {
        //     if (x % s[j] == 0) { 
        //         cnt--;
        //         break;
        //     }
        // }
    }

    cout << cnt << endl;


    return 0;
}