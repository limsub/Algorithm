#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>



// 11047
// 그리디


int main() {
    int N, K;

    cin >> N >> K;
    vector<int> arr(N);

    int index = 0;
    for (int i = 0; i < N ;i++) {
        cin >> arr[i];
    }

    // 아예 탐색하면서 바로 계산해버린다
    // 하나의 인덱스에서 몇 번씩 계산하는게 아니고
    // 몫과 나머지를 이용해서 바로 다음 인덱스로 넘어감
    int cnt = 0;
    for (int i = N-1; i >= 0; i--) {
        if ( arr[i] <= K) {
            // 몫은 cnt에 더해줌
            cnt += K / arr[i];

            // 나머지는 K로 저장
            K = K % arr[i];
        }
    }



    // for (int i = 0; i < N; i++) {
    //     if (arr[i] > K) {
    //         index = i - 1;
    //         break;
    //     }
    // }

    //printf("초기 index : %d\n", index);


    // int cnt = 0;
    // while (K > 0 && index >= 0) {
    //     K -= arr[index];

    //     printf("K : %d\n", K);
    //     cnt++;

    //     while (arr[index] > K) {
    //         index--;
    //     }
    // }

    printf("%d", cnt);


    return 0;
}
