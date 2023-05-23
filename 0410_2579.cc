// #2579
// 계단 오르기 문제. 맨 마지막 계단(i번째)을 밟을 수 있는 케이스를 나눈다
// 먼저 단순하게 (i-2) -> (i) 와 (i-1) -> (i)로 나눌 수 있다
// 첫 번째 케이스는 두 칸을 넘어왔기 때문에 제약조건 없지만
// 두 번째 케이스는 세 칸 연속 밟으면 안되기 때문에 (i-3) -> (i-1) -> (i)로 제약 조건을 준다.

#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <list>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {

    int N;
    vector<int> ans(301);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> ans[i];
    }

    vector<int> m(301);

    m[1] = ans[1];
    m[2] = ans[1] + ans[2];

    for (int i = 3; i <= N; i++) {
        m[i] = max(m[i-2] + ans[i], m[i-3] + ans[i-1] + ans[i]);
    }

    printf("%d", m[N]);
    return 0;
}