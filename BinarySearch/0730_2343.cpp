#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>



// 2343

// 어떻게 해야 하지..?
// 1. 총합 계산 -> 나누기 M => x
// 2. 앞에서부터 x에 가까워지면(?) 끊어주기
//  2 - 1. 가까워진다는게 얼마나 가까워져야 하냐?
//      - 이상이 되는 순간!을 잡아버리자 도 안된다.. 작을 수도 있으니까;;


// 방법
// 1. 이진 탐색 준비 (자연수 배열) - (입력의 최댓값 ~ 입력의 총합)
// 2 - 1. midNum으로 넣었을 때 가능하면 (start ~ mid - 1)
// 2 - 2. 불가능하면 (mid + 1 ~ end)
// 계속 진행하다가 start > end이면 종료 후 start 출력

int N, M;
vector<int> A;


int check(int midNum) {
    int ans = 0;

    // 쭉 더하다가 midNum보다 커지는 순간 -> 그 직전까지 인정
    int i = 0;
    while(i <= N-1) {
        int cnt = 0;

        while (1) {
            cnt += A[i];
            i++;

            if (cnt > midNum) {
                ans++;
                i--;
                break;
            }

            if (i >= N && cnt <= midNum) {
                ans++;
                break;
            }
        }

        
    }
    return ans;
}

int main() {

    cin >> N >> M;
    A.resize(N+1);

    int startNum = 0;
    int endNum = 0;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        
        // 인덱스 시작값 (받은 길이의 최댓값)
        if (A[i] > startNum) {
            startNum = A[i];
        }

        // 인덱스 마지막값 (받은 길이의 총합)
        endNum += A[i];
    }

    while (startNum <= endNum) {
        // 중간값
        int midNum = (startNum + endNum) / 2;
        //printf("midNum : %d\n", midNum);
        // M개 안에 다 커버할 수 있는지 확인
        if (check(midNum) <= M) {
            //printf("endNum--\n");
            endNum = midNum - 1;
        }
        else {
            //printf("startNum--\n");
            startNum = midNum + 1;
        }

    }

    printf("%d", startNum);

    return 0;
}
