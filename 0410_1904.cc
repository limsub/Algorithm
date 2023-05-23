// #1904
// 피보나치 수열과 동일. long long 범위와, 이걸로도 커버 안되는 것 때문에 15746로 나눈 나머지로 배열에 넣어주기
// 왜 피보나치 수열과 동일한지 증명(?)까지 하진 않았다.
// 일단 1 차이나는 애들한테는 앞에 '1' 붙여주고, 2 차이나는 애들한테는 앞에 '00' 붙여주니까 가능한 모든 케이스가 나왔다.

#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <list>
#include <fstream>
#include <vector>


using namespace std;

int main() {

    int N;
    cin >> N ;

    int N1 = 1, N2 = 2;

    vector<long long> ans(N);
    ans[0] = 1;
    ans[1] = 2;

    for (int i = 2; i < N; i++) {
        ans[i] = (ans[i-1] + ans[i-2])%15746;
    }

    printf("%lld", ans[N-1]%15746);



    return 0;
}