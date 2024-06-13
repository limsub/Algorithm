#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long

// 2352 반도체 설계

// LIS - O(nlogn) - 길이만 출력

int arr[40010];
vector<int> lis;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;

    for (int i = 0; i < N; i++) cin >> arr[i];


    for (int i = 0; i < N; i++) {
        // 맨 뒤에 붙이는 경우
        if (lis.empty() || lis.back() < arr[i]) lis.push_back(arr[i]);

        // 기존 위치를 대체하는 경우
        else {
            int pos = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
            lis[pos] = arr[i];
        }
    }
    cout << lis.size();


    return 0;
}

