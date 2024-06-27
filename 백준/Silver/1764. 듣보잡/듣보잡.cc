#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long
#define INF 0x3F3F3F3F // INF + INF 연산할 일이 생길 수 있기 때문에 7로 안했다.


// 1764 듣보잡

unordered_map<string, int> um;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        um[s] ++;
    }
    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        um[s] ++;
    }

    vector<string> ans;
    for (auto iter = um.begin(); iter != um.end(); iter++) {
        if (iter->second >= 2) {
            ans.push_back(iter->first);
        }
    }

    cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }



    return 0;
}

