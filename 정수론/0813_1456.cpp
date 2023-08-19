#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>


// 1456 거의 소수
// 소수의 N제곱?

// 소수를 먼저 찾고, 걔네들의 N제곱이 범위 안에 몇 개 있는지 찾자
// 어차피 소수이기 때문에 서로 겹칠 일이 없다

// 와 이항정리..!

// 와... double로 또 바꿔줘야 함

// 사실상 답지 보고 한거랑 다름없음... 
// 1. 범위 보고 int인지 long인지
// 2. 입력받은 B로 할지 10000001로 할지
// 3. 나누기할 때 double 바꿔줄지
// 4. sqrt 적절하게 쓰기. 잘못 썼다가 런타임에러 (OutOfBounds)
// 5. 이항정리를 어떻게 생각하냐...


int main() {

    long A, B;
    scanf("%ld %ld", &A, &B);

    vector<long> arr(10000001);

    for (long i = 0; i < 10000001; i++) {
        arr[i] = i;
    }
    arr[0] = -1;
    arr[1] = -1;

    for (long i = 2; i < sqrt(10000001); i++) {

        if (arr[i] == -1) {
            continue;
        }

        for (long j = i + i; j < 10000001; j += i) {
            arr[j] = -1;
        }
        
    }

    long cnt = 0;

    for (long i = 2; i < 10000001; i++) {

        if (arr[i] != -1) {
            long k = i;

            while (double(i) <= double(B) / double(k)) {


                if ( double(i) >= double(A)/double(k)) {
                    cnt += 1;
                }

                k *= i; 
                
            }
        }
        
    }

    printf("%ld", cnt);



    return 0;
}
