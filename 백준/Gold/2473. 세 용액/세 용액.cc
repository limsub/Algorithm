#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long
#define INF 0x3F3F3F3F // INF + INF 연산할 일이 생길 수 있기 때문에 7로 안했다.

// 2473 세 용액

// 정렬이 되어있지 않다.
// 정렬 때리고 가야 함.


// st, en과 별개로 추가의 i가 하나 있어야 함 - for loop

ll arr[5010];

ll ans_sum = 1e18;  // ll의 최댓값
ll ans_arr[3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);


    for (int i = 0; i < n-2; i++) { // 얘가 맨 처음 
        int st = i+1;   // 얘가 두번째
        int en = n-1;     // 애가 세번째 (맨 뒤에서 온다)

        while (st < en) {
            ll sum = arr[i] + arr[st] + arr[en];

            if (abs(sum) < ans_sum) {
                ans_sum = abs(sum);
                ans_arr[0] = arr[i];
                ans_arr[1] = arr[st];
                ans_arr[2] = arr[en];
            }

            if (sum < 0) st++;  // 0보다 작으면 더 값을 키워봐
            else en--;          // 0보다 크면 더 값을 줄여봐
        }
    }

    cout << ans_arr[0] << " " << ans_arr[1] << " " << ans_arr[2];


    return 0;
}

