#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;
#include <queue>
#include <cstdio>
#include <set>


// 9084 


// 1. 로직 구상
// 실패

// 2. 정답 확인
// d[j] += d[j - a[i]]
// 신기한 로직. 결국은 각각의 조합으로 이루어지는 식

int n, m;
int arr[10005], d[10005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int T; 
    cin >> T;

    while (T--) {

        fill(d, d + 10005, 0); // 0으로 초기화
        
        cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];

        cin >> m;
        d[0] = 1;   // 0을 만들 수 있는 개수는 항상 고정. 1가지 (아무것도 안내는 경우)

        for (int i = 0; i < n; i++) {
            int k = arr[i]; // 동전의 종류.

            for (int j = k; j <= m; j++) {
                // 특정 동전 종류부터, 최대 금액까지 for문
                // 이 동전을 이용해서 만들 수 있는 모든 금액에 대한 loop이다.
                
                // d[j]번째에 k원짜리를 하나 쓴다고 생각하면, k원 하나 + j-k에 대한 경우의 수
                d[j] += d[j - k];
            }
        }

        cout << d[m] << "\n";
    }
  




    return 0;
}