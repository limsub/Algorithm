#include <bits/stdc++.h>
using namespace std;


// 16928 뱀과 사다리 게임
// BFS.

// 사다리 - 사다리 타고 위로
// 뱀 - 뱀 타고 아래로 
// 1에서 출발. 100에 도착. 최소 몇 번?

int s[101];
int b[101];
int v[101]; 

int main() 
{
    // // 기본 초기화 
    // for (int i = 1; i <= 100; i++) {
    //   s[i] = i; b[i] = i;
    // }
    
    int n, m; cin >> n >> m;  // 사다리, 뱀 
    
    // 사다리 
    for (int i = 0; i < n; i++) {
      int x, y; cin >> x >> y;
      s[x] = y; 
    }
    // 뱀 
    for (int i = 0; i < m; i++) {
      int x, y; cin >> x >> y;
      b[x] = y; 
    }
    
    // bfs 시작 
    queue<int> q;
    q.push(1); 
    v[1] = 1;
    
    while (!q.empty()) {
      int c = q.front(); q.pop();
      
      if (c == 100) break; 
      
      // 주사위는 1 ~ 6 
      for (int d = 1; d <= 6; d++) {
        int n = c + d;
        if (n > 100) continue; 
        
        // 사다리 
        if (s[n]) {
          n = s[n];
        }
        
        // 뱀 
        if (b[n]) {
          n = b[n];
        }
        
        if (v[n]) continue; 
        
        
        q.push(n); v[n] = v[c] + 1;
        
      }
    }
    
    cout << v[100] - 1;
    
    
    
    return 0;
}