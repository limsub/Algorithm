#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

// 1149 RGB 거리
int main() {
    int N;
    scanf("%d", &N);
    //printf("N : %d\n", N);

    vector< vector<int> > cost(N+1, vector<int> (3));
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    cost[1][0] = x;
    cost[1][1] = y;
    cost[1][2] = z;
    //printf("x, y, z : %d %d %d\n", x, y, z);

    for (int i = 2; i <= N; i++) {
        int r, g, b;
        scanf("%d %d %d", &r, &g, &b);
        //printf("x, y, z : %d %d %d\n", r, g, b);
        cost[i][0] = min(cost[i-1][1], cost[i-1][2]) + r;
        cost[i][1] = min(cost[i-1][0], cost[i-1][2]) + g;
        cost[i][2] = min(cost[i-1][0], cost[i-1][1]) + b;
        //printf("Good\n");
    }

    cout << min(cost[N][0], min(cost[N][1], cost[N][2])) << endl;
    return 0;
}