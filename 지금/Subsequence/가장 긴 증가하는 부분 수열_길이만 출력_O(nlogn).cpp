#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long


// 12015 12738 14003
// 12015 : 1초, N : 1,000,000, 길이만 출력 
// 12738 : 3초, N : 1,000,000, 길이만 출력 Ai 범위 큼
// 14003 : 3초, N : 1,000,000, 길이 및 수열 출력 Ai 범위 큼
// 가장 긴 증가하는 부분 수열 - O(nlogn)

// 주의 : 길이만 출력하는 코드와, 길이 + 수열 출력하는 풀이가 다르다.
// 오늘은 일단 길이 출력하는 코드 공부

// 이분 탐색 활용
// 12015, 12738 풀이 가능



int N;
int arr[1000010];
vector<int> lis;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    // 1. 입력
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 2. 구현
    for (int i = 0; i < N; i++) {
        if (lis.empty() || lis.back() < arr[i]) lis.push_back(arr[i]);

        else {
            int pos = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
            lis[pos] = arr[i];
        }
    }
    cout << lis.size() << "\n";


    return 0;
}

