#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long
#define INF 0x3F3F3F3F // INF + INF 연산할 일이 생길 수 있기 때문에 7로 안했다.

// 2586 전깃줄 - 2

int n;
vector< pair<int, int> > arr;   // 전봇대 저장 (x, y)
vector<int> sort_arr;           // 전봇대 x 정렬 시 b 배열
map<int, int> m;                // (key, value) = 전봇대 (b, a)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 입력 및 초기화
    cin >> n;
    arr = vector< pair<int, int> > (n);
    sort_arr = vector<int> (n);

    for (int i = 0; i < n; i++) {
        int k, v; cin >> v >> k;
        arr[i].first = v;
        arr[i].second = k;
        m[k] = v;
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        sort_arr[i] = arr[i].second;
    }




    vector<int> v;          // 이분탐색 진행할 배열
    vector<int> idx_arr;    // 배열에 추가되는 숫자의 인덱스 저장 배열

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            v.push_back(sort_arr[i]);
            idx_arr.push_back(1);
            continue;
        }

        int idx = lower_bound(v.begin(), v.end(), sort_arr[i]) - v.begin();
        int len = v.size();

        if (idx == len) v.push_back(sort_arr[i]);
        else v[idx] = sort_arr[i];


        idx_arr.push_back(idx + 1);
    }




    int len = v.size();
    vector<int> ans(len);

    for (int i = n-1, n = len; i >= 0; i--) {
        if (idx_arr[i] == n) {
            ans[--n] = sort_arr[i];
        }
    }

    for (int i = 0; i < len; i++) {
        m[ans[i]] = -1;
    }


    cout << n - len << "\n";
    for (int i = 0; i < n; i++) {
        int k = sort_arr[i];
        if (m[k] == -1) continue;
        cout << m[k] << " \n";
    }

    return 0;
}

