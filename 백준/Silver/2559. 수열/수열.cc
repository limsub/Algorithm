#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long


// 2559 수열
// 연속적인 K값의 합이 최대가 되는 값 출력 (최대 부분 수열? 같은 유형)

// 개수가 K로 정해져 있기 때문에, 시작 위치가 정해져있으면 연속합은 정해진다.
// -> 새로운 배열에 저장한다

int N, K;
int arr[100010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 입력
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];

    // 2. 풀이
    vector<int> ans;
    int sum = 0;
    // 처음 K개
    for (int i = 0; i < K; i++) {
        sum += arr[i];
    }
    ans.push_back(sum);

    for (int i = K; i < N; i++) {
        sum += arr[i];
        sum -= arr[i-K];
        ans.push_back(sum);
    }


    cout << *max_element(ans.begin(), ans.end());




    for (int i = 0; i < N - K + 1; i++) {


        

    }





    return 0;
}

