#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long
#define INF 0x3F3F3F3F // INF + INF 연산할 일이 생길 수 있기 때문에 7로 안했다.


// 1488 연산자

// 1% 틀
// -> max_ans의 초기값을 0으로 했다. 음수가 나올 수도 있기 때문에 -0x7F7F7F7F로 바꿔줘

// 백트래킹
int n;
int d[4];   // 연산자의 개수 저장. +, -, *, / 의 개수 의미
ll num[12]; // 수 저장.

ll min_ans = 0x7F7F7F7F;
ll max_ans = -0x7F7F7F7F;

// 1 + 2 + 3 + 4 + 5라고 하면,
// 맨 처음에 1을 넣어
// 그럼 함수에서 +, -, *, / 2 를 계산해
// 그 다음에는 +, -, *, / 3 을 계산해 이런 식.
// depth가 n + 1이 되면, 그 때까지의 결과값을 min, max와 비교해

void bt(int depth, ll result) {

    if (depth == n) {
        min_ans = min(min_ans, result);
        max_ans = max(max_ans, result);
        return;
    }


    for (int i = 0; i < 4; i++) {
        if (!d[i]) continue; // 남은 연산자 개수가 없으면 사용 못해

        ll new_result;

        d[i]--;
        switch (i) {
            case 0: // +
            new_result = result + num[depth];
            break;
            case 1: // -
            new_result = result - num[depth];
            break;
            case 2: // *
            new_result = result * num[depth];
            break;
            case 3: // /
            new_result = result / num[depth];
            break;
        }
        bt(depth + 1, new_result);

        d[i]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 입력
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
    for (int i = 0; i < 4; i++) cin >> d[i];


    // 2. 백트래킹 레츠고
    bt(1, num[0]);

    cout << max_ans << "\n" << min_ans;

    return 0;
}

