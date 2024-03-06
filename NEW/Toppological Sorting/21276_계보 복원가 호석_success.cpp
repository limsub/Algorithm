#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;
#include <queue>
#include <cstdio>


// 21276 계보 복원가 호석
// 바킹독

int N, M;
string s1, s2;
string names[1002]; // 이름 저장 배열 (정렬)
unordered_map<string, int> id;  // 이름 인덱스로 받으면 사전순 정렬 시 (names) 고유번호 반환

int indegree[1002]; 
vector<int> adj[1002];  // 그래프 저장 - int 값으로 저장!! (해시 이용)
vector<int> ch[1002];   // children 정보 저장


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // N, names 입력
    cin >> N;
    for (int i = 1; i <= N; i++) {  // i = 1부터 시작
        cin >> names[i];
    }
    sort(names + 1, names + N + 1); // 정렬

    // id 저장 (인덱스 저장)
    for (int i = 1; i <= N; i++) {
        id[names[i]] = i;   // 문자열이 names에서 몇 번째인지 저장함
    }

    // M, adj, indegree 입력
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> s1 >> s2;    // cin으로 문자열 입력을 받을 때는 공백으로 끊긴다.
        
        adj[id[s2]].push_back(id[s1]);

        indegree[id[s1]]++; // 본인한테 들어오는 간선
    }


    // 시조 저장 (indegree가 0이면 시조)
    vector<int> finalParent;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) { finalParent.push_back(i); }
    }


    // 자식 정보 저장 (연결된 노드 중 indegree가 1 차이 나는 노드)
    for (int i = 1; i <= N; i++) {
        
        for (int j = 0; j < adj[i].size(); j++) {
            
            int p = adj[i][j];

            // cout << "i : " << i << " " << "p : " << p << "\n";

            if (indegree[p] - indegree[i] == 1) { ch[i].push_back(p); }
        }

        sort(ch[i].begin(), ch[i].end());
    }


    // 최종 출력
    // 1. 
    cout << finalParent.size() << "\n";

    // 2. 
    for (int i = 0; i < finalParent.size(); i++) {
        cout << names[finalParent[i]] << " ";
    }
    cout << "\n";

    // 3. 
    for (int i = 1; i <= N; i++) {

        cout << names[i] << " " << ch[i].size() << " ";

        for (int j = 0; j < ch[i].size(); j++) {
            cout << names[ch[i][j]] << " ";
        }

        cout << "\n";

    }


    return 0;
}