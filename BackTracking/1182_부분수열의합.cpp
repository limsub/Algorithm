#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>


// 1182 부분수열의 합
// 트리 구조 처음에 잘못 짬. 



int N, S;
int arr[21];
int cnt = 0;

void backTracking(int p, int sum) {

    // 맨 바닥까지 내려간 상태에서, sum이 일치하면 cnt 증가 후 종료
    if (p == N  && sum == S) {
        cnt++;
        return;
    }
    // 맨 바닥까지 내려갔는데, sum이 일치하지 않으면 그냥 종료
    if (p == N) {
        return;
    }


    backTracking(p+1, sum + arr[p]);
    backTracking(p+1, sum);
}

int main() {

    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    backTracking(0, 0);

    // sum 초기값이 0이기 때문에, S가 0인 경우, 아무것도 선택하지 않은 케이스가 포함될 수 있다
    if (S == 0) {
        cnt --;
    }

    cout << cnt << endl;



    return 0;
}