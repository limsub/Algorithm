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

int N, M;
vector<int> A;
vector<bool> ans(0);

bool binarySearch(int start, int end, int num) {

    //printf("s, e, n : %d %d %d\n", start, end, num);

    

    if (start <= end) {

        if ( num == A[start] || num == A[end]) {
            //printf("hi\n");
            return true;
        }


        int medium = (start + end )/2;

        if (num == A[medium]) {
            return true;
        }

        else if (num > A[medium]) {
            return binarySearch(medium+1, end, num);
        }

        else {
            return binarySearch(start, medium - 1, num);
        }
    }
    return false;
}


int main() {

    cin >> N >> M;
    A.resize(N);

    int startNum = 10001;
    int endNum = 0;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        
        if (A[i] < startNum) {
            startNum = A[i];
        }

        endNum += A[i];
        
    }

    return 0;
}
