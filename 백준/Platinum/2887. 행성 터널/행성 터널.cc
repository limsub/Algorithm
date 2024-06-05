#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long

// 2887 행성 터널

// Minimum Spanning Tree

// 3차원 좌표..
// 기존 MST : 간선의 cost가 가장 작은 것부터..
// 여긴 간선의 cost를 주는게 아니라, 좌표로 위치를 주기 때문에 cost를 직접 계산해야 한다.
// 그렇다고 모든 정점마다... 간선을 모두 계산하고 있기에는 N^2이니까 이미 시간초과

// 그렇다면, 축 별로 나눠서, x축 방향에서의 최소, y축 방향에서의 최소 이런식으로 계산?

// 오케이 포기하고 구글링 ㄱㄱ

// https://chanhuiseok.github.io/posts/baek-34/


// x축, y축, z축 방향으로 cost를 저장해두는 방식

int N;
pair<int, int> x_axis[100010];   // x좌표, 인덱스
pair<int, int> y_axis[100010];   // y좌표, 인덱스
pair<int, int> z_axis[100010];   // z좌표, 인덱스
// 초기 주어진 인덱스로 점을 구분한다

tuple<int, int, int> edge[300010];

vector<int> p(100010, -1);

// 1. find_p : 최종 부모 찾기
int find_p(int x) {
    if (p[x] < 0) return x;
    return p[x] = find_p(p[x]);
}

// 2. union_p : p 합치고, 이미 같은 최종 부모이면 return false
bool union_p(int x, int y) {
    x = find_p(x); y = find_p(y);

    if (x == y) return false;

    else {
        if (p[x] == p[y]) p[x]--;

        if (p[x] < p[y]) p[y] = x;
        else p[x] = y;
    }

    return true;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    // 1. 입력
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y, z; cin >> x >> y >> z;
        x_axis[i] = {x, i};
        y_axis[i] = {y, i};
        z_axis[i] = {z, i};
    }


    // 2. 정렬
    sort(x_axis, x_axis + N);
    sort(y_axis, y_axis + N);
    sort(z_axis, z_axis + N);


    // 3. edge 저장
    for (int i = 0; i < N-1; i++) {
        // i번째 점과 i-1번째 점의 차이 저장. i+1번째 점의 인덱스 저장. i번째 점의 인덱스 저장
        edge[3 * i] = {x_axis[i+1].first - x_axis[i].first, x_axis[i+1].second, x_axis[i].second};
        edge[3 * i + 1] = {y_axis[i+1].first - y_axis[i].first, y_axis[i+1].second, y_axis[i].second};
        edge[3 * i + 2] = {z_axis[i+1].first - z_axis[i].first, z_axis[i+1].second, z_axis[i].second};
    }
    // edge에 저장 : N-1 번을 3번 => 3*(N-1)

    


    // 4. edge sort
    sort(edge, edge + 3 * (N-1));




    


    // 5. Kruskal Algorithm
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < 3*(N-1); i++) {

        int point1, point2, cost;
        tie(cost, point1, point2) = edge[i];


        if (!union_p(point1, point2)) continue;

        // cout << "\n";
        // cout << point1 << " 0 " << point2 << " - " << cost;
        // cout << "\n";


        cnt++;
        ans += cost;

        if (cnt == N-1) break;
    }

    cout << ans;


    

}
