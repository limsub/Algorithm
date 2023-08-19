#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>


// 1929 소수 구하기

// loop을 최대한 적게 돌기 위해 얼마나 돌아야 하는지
// 1 ~ N/2 or 1 ~ sqrt(N)
// 1 ~ sqrt( double(N) ) 쓰니까 컴파일 에러


int main() {

    int M, N;
    scanf("%d %d", &M, &N);

    vector<int> arr(N+1);
    for (int i = 0; i <= N; i++) {
        arr[i] = i;
    }

    arr[1] = -1;



    for (int i = 2; i <= N/2; i++) {
        int k = i;

        if (arr[k] == -1) {
            continue;
        }

        for (int j = 2; j <= N/k; j++) {
            arr[j * k] = -1;
        }

    }


    for (int i = M; i <= N; i++) {

        if (arr[i] != -1) {
            printf("%d\n", arr[i]);
        }

    }

    return 0;
}
