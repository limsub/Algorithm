#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>

// 17829

// divide and conquer
// merge sort랑 비슷한 느낌으로 가자

int N;
vector< vector<int> > v;

int secondNum(int a, int b, int c, int d) {
    int tmp = a;

    vector<int> v2;
    v2.push_back(a);
    v2.push_back(b);
    v2.push_back(c);
    v2.push_back(d);

    sort(v2.begin(), v2.end());

    return v2[2];
}

int make(int size, int startX, int startY) {

    // 4분할 해주기

    if (size > 2) {
        // 1
        int a = make(size/2, startX, startY);

        // 2
        int b = make(size/2, startX + size/2, startY);

        // 3
        int c = make(size/2, startX, startY + size/2);

        // 4
        int d = make(size/2, startX + size/2, startY + size/2);

        // merge

        return secondNum(a, b, c, d);
    }
    else {
        int a = v[startX][startY];
        int b = v[startX + 1][startY];
        int c = v[startX][startY + 1];
        int d = v[startX + 1][startY + 1];

        return secondNum(a, b, c, d);
    }

}



int main() {

    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        v[i].resize(N);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }

    int ans = make(N, 0, 0);
    cout << ans << endl;
   
    return 0;
}