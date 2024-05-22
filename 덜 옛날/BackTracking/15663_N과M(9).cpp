#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>

#include <set>


// 15663 N과 M (9)
int N, M;
int K;

int cnt[10001] = {0, };
vector<int> arr;
int ansArr[10];

void backTracking(int depth) {

    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << ansArr[i] << " ";
        }
        printf("\n");
    }

    for (int i = 0; i < arr.size(); i++) {
        int x = arr[i];

        if (cnt[x] > 0) {
            ansArr[depth] = x;
            cnt[x]--;
            backTracking(depth+1);
            cnt[x]++;
        }
    }
}

int main() {

    set<int> s;
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        s.insert(x);
        cnt[x] ++;
        // cin >> arr[i];
    }

    // arr에 넣어주기
    for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++) {
        arr.push_back(*iter);
    }

    // arr 정렬
    sort(arr.begin(), arr.end());

    // for (int i = 0; i < arr.size(); i++) {
    //     cout << arr[i] << "  ";
    // }

    // 백트래킹 시작
    backTracking(0);


    return 0;
}