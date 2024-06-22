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
// 길이 + 수열 출력하는 코드!!! - 14003 적용 가능

int N;
int arr[1000010];
int idx[1000010];
vector<int> lis;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    // 1. 입력
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 2. 구현 (binary search)
    for (int i = 0; i < N; i++) {
        if (lis.empty() || lis.back() < arr[i]) {
            lis.push_back(arr[i]);
            idx[i] = lis.size() - 1;
        }

        else {
            int pos = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
            lis[pos] = arr[i];
            idx[i] = pos;   // arr의 i번째 있는 수는 lis의 pos에 위치한다.
        }
    }
    cout << lis.size() << "\n";


    // 정답 수열 찾기 위함
    vector<int> ans;
    int find_idx = lis.size() - 1; // 제일 끝부터 들어가야 하는 인덱스를 찾는다. 찾으면 -1씩 해준다.
    for (int i = N-1; i >= 0; i--) {    
        

        if (find_idx < 0) break;

        // idx[i] : arr의 i번째 있는 수가 lis의 몇 번째 인덱스에 있는지
        if (idx[i] == find_idx) {
            find_idx--;

            ans.push_back(arr[i]);   // arr[i] 가 find_idx 위치에 위치할 수다.
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }


    return 0;
}

