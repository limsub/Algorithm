#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;
#include <queue>
#include <cstdio>


// 11725 트리의 부모 찾기

int v[100002];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;


    vector< vector<int> > adj(N + 1);

    for (int i = 0; i < N-1; i++) {

        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }



    queue<int> q;
    q.push(1);

    int p[N+1];
    

    while(!q.empty()) {

        int cur = q.front();        
        q.pop();

        // cout << "cur : " << cur << "\n";


        for (int j = 0; j < adj[cur].size(); j++) {

            int next = adj[cur][j];

            // cout << "next : " << next << "\n";

            if (v[next] == 1) { continue; }

            // cout << "good next : " << next << "\n";

            q.push(next);
            v[next] = 1;

            p[next] = cur;
        }
    }

    for (int i = 2; i <= N; i++) {
        cout << p[i] << "\n";
    }

   

    return 0;
}