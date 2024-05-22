#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>

// 11048 DP
// 세 방향에서 오는 것중에 maximum 잡기

int main() {
    
    int N, M;
    cin >> N >> M;

    vector< vector<int> > v(N, vector<int>(M));
    vector< vector<int> > ans(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
        }
    }

    ans[0][0] = v[0][0];
    for (int i = 1; i < N; i++) {
        ans[i][0] = ans[i-1][0] + v[i][0];
    }
    for (int j = 0; j < M; j++) {
        ans[0][j] = ans[0][j-1] + v[0][j];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            int max = ans[i-1][j];
            if (ans[i-1][j-1] > max) {
                max = ans[i-1][j-1];
            } 
            if (ans[i][j-1] > max) {
                max = ans[i][j-1];
            }
            ans[i][j] = max + v[i][j];
        }
    }

    cout << ans[N-1][M-1] << endl;
    

    return 0;
}