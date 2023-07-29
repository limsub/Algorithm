#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>



// 1920
// 이진 탐색

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

    cin >> N;
    A.resize(N+1);
    A[0] = 0;
    for (int i = 1; i < N+1; i++) {
        cin >> A[i];
    }
    sort(A.begin() + 1, A.end());

    // for (int i = 0; i < N+1; i++) {
    //     printf("%d  ", A[i]);
    // }


    cin >> M;
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;

        ans.push_back(binarySearch(1, N, x));
    }

    for (int i = 0; i < M; i++) {
        if (ans[i]) {
            printf("%d\n", 1);
        }
        else {
            printf("%d\n", 0);
        }
    }

    // sorting 먼저 때리고, 이진 탐색 ㄱ

    return 0;
}
