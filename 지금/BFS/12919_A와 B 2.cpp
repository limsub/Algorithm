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

// 1. (가능하다면) 뒤에서 A를 제거한 문자열 큐에 삽입
// 2. (가능하다면) 뒤집고 뒤에서 B를 제거한 문자열 큐에 삽입


unordered_map<string, int> um;

// 문자열을 뒤집었는데, 맨 뒤가 B인지 확인하는 메서드
string erase_b(string s) {
    string ans = "";

    for (int i = s.size() - 1; i >= 0; i--) {
        ans += s[i];
    }

    if (ans[ans.size() - 1] == 'B') {
        return ans.substr(0, ans.size() - 1);
    }
    else {
        return "-1";
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 입력
    string s, t; cin >> s >> t;

    
    // 2. BFS
    // (수정) t에서 시작해서 s를 찾는 방식
    queue<string> q;
    q.push(t);
    um[t] = 1;

    while (!q.empty()) {
        string cur = q.front(); q.pop();

        if (cur == s) { 
            cout << "1"; 
            return 0;
        }

        // 1. 뒤에서 A 제거하기
        if (cur[cur.size() - 1] == 'A') {
            string n1 = cur.substr(0, cur.size() - 1);

            if (n1.size() >= s.size() && !um[n1]) {
                q.push(n1);
                um[n1] = 1;
            }
        }

        // 2. 뒤집고 뒤에서 B 제거하기
        string n2 = erase_b(cur);
        if (n2 != "-1") {
            if (n2.size() >= s.size() && !um[n2]) {
                q.push(n2);
                um[n2] = 1;
            }
        }
    }
    

    cout << "0";

    return 0;
}

