#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long


// 14003 가장 긴 증가하는 부분 수열
// 3초
// N : 1,000,000
// 각각의 Ai : 1,000,000,000 (10억)


// i = 0 -> N까지 loop
// 새로운 배열 pair<int, int> arr2 생성 : {해당 인덱스까지 가장 긴 길이, 걔의 바로 앞 인덱스}
// 모든 값은 최소 길이 1. 만약 길이가 1, 즉 자기 혼자가 끝이라면 앞 인덱스는 -1 저장
// => 이러면 O(n^2) 떠서 시간초과 날 것 같아.... 일단 해보자

// ㅇㅇ 1% 시간초과 뜸.
// 11053 문제에 넣으면 정답!

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    // 1. 입력
    vector<int> arr;
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }

    // 2. arr2 생성
    vector< pair<int, int> > arr2(N + 1, {1, -1});

    int finalMaxLength = 0;
    int finalMaxIdx = 0;

    for (int i = 0; i < N; i++) {
        // i 번째 수
        int k = arr[i];

        // 앞으로 돌아가면서, 자기보다 작은 애 중 가장 긴 수열을 찾는다.
        int maxLength = 1;
        int maxIdx = -1;
        for (int j = i-1; j >= 0; j--) {
            // - 값이 크거나 같으면 continue
            if (arr[j] >= k) continue;

            // - 현재까지의 최대 길이보다 작으면 continue
            if (arr2[j].first < maxLength) continue;

            // maxLength 및 인덱스 업데이트
            maxLength = arr2[j].first + 1;
            maxIdx = j;
        }

        // arr2[i] 업데이트
        arr2[i] = {maxLength, maxIdx};

        // final 값 업데이트
        if (maxLength > finalMaxLength) {
            finalMaxLength = maxLength;
            finalMaxIdx = i;
        }
    }

    // 출력
    // for (int i = 0; i < N; i++) {
    //     cout << arr2[i].first << "  " << arr2[i].second << "\n";
    // }

    cout << arr2[finalMaxIdx].first << "\n";
    
    vector<int> ans;
    ans.push_back(arr[finalMaxIdx]);
    int k = arr2[finalMaxIdx].second;
    while (k != -1) {
        // cout << arr[k] << " ";
        ans.push_back(arr[k]);
        k = arr2[k].second;
    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }



    return 0;
}

