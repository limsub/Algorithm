#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long
#define INF 0x3F3F3F3F // INF + INF 연산할 일이 생길 수 있기 때문에 7로 안했다.

// 2467 용액

// 투 포인터
// 범위가 10억, 10억이기 때문에 o(n) 으로 끝내야 한다.
// 이미 정렬된 상태로 배열이 주어진다.

// 양수 or 음수냐에 따라 값을 빼줄지 or 값을 더해줄지 정하기 때문에
// st, en을 처음부터 같이 가는게 아니라, 양 끝에서 다가오도록 한다.

int arr[100010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 입력 및 초기화
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 2. 투 포인터
    int st = 0; int en = n-1;
    int ans = 0x7F7F7F7F;
    int ans_st = st; int ans_en = en;
    while (st != en) {
        int sum = arr[st] + arr[en];
        if (abs(sum) < abs(ans)) {
            ans = sum;
            ans_st = st; ans_en = en;
        }

        if (sum > 0) {
            // 0보다 크면, 조금 줄이기 위한 노력
            en--;
        }
        else if (sum < 0) {
            // 0보다 작으면, 조금 키우기 위한 노력
            st++;
        }
        else if (sum == 0) {
            // 0 이면, 걍 끝낸다.
            break;
        }

    }

    cout << arr[ans_st] << " " << arr[ans_en];


    return 0;
}

