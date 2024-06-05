#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long

// 20303 할로윈의 양아치

// union-find, dp


int N, M, K;
int candy[30010];

vector<int> p(30010, -1); // 최종 부모라면, -1 * 연결된 노드의 개수가 저장된다. 

// 최종 부모 인덱스 :  {인원수, candy 합} 로 저장된다.
pair<int, int> arr[30010];    
// int dp[30010][30010];
vector< vector<int> > dp(30010, vector<int>(30010, 0));

// 1. find : 최종 부모 찾기
int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

// 2. union_p : 최종 부모를 합친다
void union_p(int x, int y) {
    x = find(x); y = find(y);  
    // 이렇게 하면, 일단 p[x]와 p[y]는 무조건 음수이고,
    // -1 * 연결된 노드의 개수가 저장되어 있다.


    // 무조건 값이 작은 게 부모가 되도록 구현한다
    if (x < y) {
        p[x] += p[y];
        p[y] = x;
    }
    else {
        p[y] += p[x];
        p[x] = y;
    }
}




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    // 1. 입력
    cin >> N >> M >> K;
    // 1부터 N까지의 아이가 있다.
    for (int i = 0; i < N; i++) cin >> candy[i+1];
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        union_p(x, y);
    }


    // 2. arr 채우기
    vector<int> final_p;
    for (int i = 1; i <= N; i++) {
        // 1). 최종 부모 찾는다.
        int parent = find(i);

        if (arr[parent].second == 0) {
            final_p.push_back(parent);
        }

        arr[parent].first = p[parent] * -1; // 이건 아마 계속 중복될거다. p[parent] 값은 고정이니까.
        arr[parent].second += candy[i];
    }

    // cout << final_p.size() << "\n";

    // for (int i = 0; i < final_p.size(); i++) {
    //     int p = final_p[i];

    //     cout << p << " : " <<  arr[p].first << " - " << arr[p].second << "\n";
    // }
    
    // 3. dp
    // dp[i][j] : i번째 뭉텅이까지 고려했을 때, j명을 고른다면 최대 사탕 개수
    // - 1st loop : 그래프 뭉텅이
    // - 2nd loop : 0 -> K

    // i = 0;

    int ans = 0;
    for (int j = 1; j < K; j++) {
        dp[0][j] = 0;

        int fp = final_p[0];

        if (j >= arr[fp].first) {
            dp[0][j] = arr[fp].second;
            ans = max(ans, dp[0][j]);
        }
    }

    

    for (int i = 1; i < final_p.size(); i++) {
        int f_p = final_p[i];   // 최종 부모
        cout << "i : " << i << "\n";
        cout << "fp : " << f_p << "\n";

        for (int j = 1; j < K; j++) {  
            cout << "j : " << j << "\n";
            // dp[i][0]은 일단 무조건 다 0이다.

            // 1. 일단, 최소 d[i-1][j] 이상은 가져감
            dp[i][j] = dp[i-1][j];
            
            


            // 2. 만약, 
            // 현재 j명까지 선택이 가능해. i번째 뭉텅이의 인원 수는 arr[f_p].first야.
            // 만약 j명 - i번째 뭉텅이의 인원수 를 했는데, 여유가 있다면, 
            // 그만큼 또 dp에서 가져올 수 있다는 뜻

            // 즉, extra = j - arr[f_p].first 라고 하면,
            // arr[i].second + dp[i-1][extra] 도 고려해주어야 한다는 뜻이다.

            // 계속해서 내가 고민했던게, 중복으로 선택하지 않을까에 대한 고민이었는데, 
            // dp[i-1][extra]로 하게 되면, 현재 그룹을 선택하기 전 애들에 대한 최선값이기 때문에, 
            // 현재 그룹은 arr[i].second로만 고려하게 되어서 중복이 발생하지 않게 된다.
            
            int extra = j - arr[f_p].first;
            if (extra >= 0) {
                dp[i][j] = max(dp[i][j], arr[i].second + dp[i-1][extra]);
            }


            ans = max(ans, dp[i][j]);
        }
    }

    cout << "\n-------\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n-------\n";

    int size = final_p.size();
    // cout << dp[size-1][K-1];
    cout << ans;

    

    // for (int i = 0; i < N; i++) {
    //     if (arr[i].first != 0) {
    //         cout << i << " : " << arr[i].first << "  --  " << arr[i].second << "\n";
    //     }
    // }

    // for (int i = 1; i < N+1; i++) {
    //     cout << i << " : " << p[i] << "\n";
    // }


}

