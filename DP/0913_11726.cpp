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

int main() {
   
    int N;
    cin >> N;

    vector<int> v(N+1);

    v[0] = 0;
    v[1] = 1;
    v[2] = 2;

    for (int i = 3; i <= N; i++) {
        v[i] = (v[i-1] + v[i-2])%10007;
    }

    cout << v[N] << endl;

    return 0;
}