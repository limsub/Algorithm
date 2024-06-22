#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long


// 4195 친구 네트워크

// union - find

// 문자열이 들어오기 때문에, 이건 해시 (unordered_map) 사용하기

// 5% 런타임 에러 OutOfBounds
// -> 왜지? p 범위가 100000이라서 100010으로 했더니 런타임에러고, 뒤에 0 붙이니까 해결되었음.

int T, N;

vector<int> p(1000100, -1);  // 직접적으로 연결된 부모 저장
unordered_map<string, int> um;

// 1. 최종 부모 찾기
int find_p(int x) {
    if (p[x] < 0) return x;
    return p[x] = find_p(p[x]); // 계속 업데이트를 하는건가....?
}

// 2. 부모 합치기 (이미 같은 부모이면 false)
bool union_p(int x, int y) {
    x = find_p(x); y = find_p(y);

    // 이미 같은 부모 -> return false
    if (x == y) return false;

    // 다른 부모
    // - p값을 하나를 낮춰서, 한 쪽이 부모가 되도록 함 (그냥 단순히 먼저 들어온 쪽)
    // if (p[x] == p[y]) p[x] --;
    // => 얘를 넣게 되면, p값에 자식의 개수를 저장하는 데 지장이 생김

    // p값이 더 작은 애가 부모가 될 수 있도록 함
    if (p[x] < p[y]) {
        p[x] += p[y];   // 이 때, 자식의 개수를 플러스해줌 (실제로는 음수 값으로 들어가지만, 어쨌든 자식의 개수이다.)
        p[y] = x;
    }
    else {
        p[y] += p[x];
        p[x] = y;
    }

    return true;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    cin >> T;

    while (T--) {
        cin >> N;

        int idx = 0;    // 0부터 시작한다. 새로운 애가 들어오면 1씩 추가

        for (int i = 0; i < N; i++) {
            string s1, s2; cin >> s1 >> s2;

            // cout << "\n";
            // for (int j = 0; j < 10; j++) {
            //     cout << p[j] << " ";
            // }
            // cout << "\n";

            // 1. 아직 해시에 없는 문자열들이라면, 먼저 추가해준다.
            if (um.find(s1) == um.end()) {
                // s1이 없다. 추가해준다.
                um[s1] = idx;
                idx++;
            }

            if (um.find(s2) == um.end()) {
                // s2가 없다. 추가해준다.
                um[s2] = idx;
                idx++;
            }


            int idx1 = um[s1]; int idx2 = um[s2];

            // 이미 같은 부모인지 확인
            int p1 = find_p(idx1); int p2 = find_p(idx2);

            // 1). 이미 같은 부모이다 - 한 쪽 애만 계산해서 출력
            if (p1 == p2) {
                cout << p[p1] * -1 << "\n";
            }

            // 2). 다른 부모이다 - 각각 계산해서 합 출력
            else {
                cout << p[p1] * -1 + p[p2] * -1 << "\n";

                // 결과적으로 둘을 합쳐주긴 해야 한다.
                union_p(idx1, idx2);
            }


            // cout << "\n";
            // for (int j = 0; j < 10; j++) {
            //     cout << p[j] << " ";
            // }
            // cout << "\n";

        }


        // p, um 초기화
        fill(p.begin(), p.end(), -1);
        um.clear();
    }

    


    return 0;
}

