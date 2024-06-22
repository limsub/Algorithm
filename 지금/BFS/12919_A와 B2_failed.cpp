#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long

// 12919 A와 B 2

// S에 연산 해서 T로 바꾸는 게임
// BFS 생각.

// 두 가지 경로 탐색 가능. 
// 1. 문자열 뒤에 A 추가.
// 2. 문자열 뒤에 B 추가하고 문자열 뒤집기
// 각 경로에 대해 cost와 동일하기 때문에 priority queue 쓸 필요 없다.
// v에 cost 저장하기. (v[next] = v[cur] + 1)
// -> 아 이거 필요 없는 문제였다. 
// 만약 nextS의 길이가 T 이상이면 stop


// 10% 메모리 초과. 큐 터지는지 확인해보자

// => 찾아본 결과, s에서 t를 만들려고 하면 모든 방법을 다 탐색하기 때문에 메모리 초과가 발생한다.
// => t에서 s를 만드는 방식으로 구현해야 한다.

unordered_map<string, int> um;

// 문자열을 뒤집어주는 메서드
string reverse_str(string s) {
    string ans = "";

    for (int i = s.size() - 1; i >= 0; i--) {
        ans += s[i];
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 입력
    string s, t; cin >> s >> t;

    
    // 2. BFS
    queue<string> q;
    q.push(s);
    um[s] = 1;

    while (!q.empty()) {
        string cur = q.front(); q.pop();

        if (cur == t) { 
            cout << "1"; 
            return 0;
        }

        // 1. 뒤에 A 붙이기
        string next1 = cur + "A";
        // cout << "n1 : " << next1 << "\n";
        if (next1.size() <= t.size() && !um[next1]) {
            // cout << "n1 clear : " <<  next1 << "\n";
            q.push(next1);
            um[next1] = um[cur] + 1;
        }

        // 2. 뒤에 B 붙이고 뒤집기
        string next2 = reverse_str(cur + "B");
        // cout << "n2 : " << next2 << "\n";
        if (next2.size() <= t.size() && !um[next2]) {
            // cout << "n2 clear : " <<  next2 << "\n";
            q.push(next2);
            um[next2] = um[cur] + 1;
        }
        
    }
    

    cout << "0";

    return 0;
}

