#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>

// 11726

// x보다 값이 작은 애들 중
// 수열의 길이가 가장 긴 값 + 1

int main() {

    int N;
    cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; i++)   {
        cin >> v[i];
    }

    vector<int> ans(N);

    ans[0] = 1;

    for (int i = 1; i < N; i++) {
        int max = 0;

        // v[i]보다 작은 값
        for (int j = 0; j < i; j++) {
            
            if (v[j] < v[i]) {
                if (ans[j] > max) {
                    max = ans[j];
                }
            }

        }
        ans[i] = max + 1;
    }

    int max_ans = ans[0];
    for (int i = 1; i < N; i++) {
        if (ans[i] > max_ans) {
            max_ans = ans[i];
        }
    }

    cout << max_ans << endl;
   
    
    return 0;
}