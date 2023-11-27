#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <cmath>
#include <set>
using namespace std;
#include <string.h>
// #include <bits/stdc++.h>

// 14502 연구소

int N, M;
int arr[10][10];
int tmpArr[10][10];

vector< pair<int, int> > zeroPos;
vector<int> zeroV;

vector< pair<int, int> > twoPos;

int dy[] = {-1, 1, 0, 0 };
int dx[] = {0, 0, -1, 1 };

int maxCnt = 0;



int bfs() {
    

    queue< pair<int, int> > q;
    // 2 위치 (바이러스)를 큐에 다 넣는다.
    for (int i = 0; i < twoPos.size(); i++) {
        q.push(twoPos[i]);
    }
    

    // bfs 시작
    while (!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        // cout << "cur : " << curY << ", " << curX << "\n";
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nextY = curY + dy[dir];
            int nextX = curX + dx[dir];


            if (nextY >= N || nextY < 0 || nextX >= M || nextX < 0) { continue; }
            if (arr[nextY][nextX] != 0) { continue; }


            q.push(make_pair(nextY, nextX));
            arr[nextY][nextX] = 2;
        }
    }


    // 살아있는 0 개수 확인
    int zeroCnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0) { zeroCnt ++; }
        }
    }
 

    return zeroCnt;
}



// depth == 3일 때, BFS 시작
void backTracking(int depth) {

    if (depth == 3) {
        // cout << "*** depth == 3 ***" << "\n";
        int a = bfs();
        // cout << "*** bfs : " << a << "\n";
        if (a > maxCnt) { 
            maxCnt = a;
        }   

        // 배열 초기화
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {

                if (arr[i][j] == 2) {
                    arr[i][j] = 0;
                }

                for (int k = 0; k < twoPos.size(); k++) {
                    arr[twoPos[k].first][twoPos[k].second] = 2;
                }
            }
        }



        // for (int i = 0; i < zeroV.size(); i++) {
        //     cout << zeroV[i] << "  ";
        // }
        // cout << "\n";
        return;
    }


    for (int i = 0; i < zeroPos.size(); i++) {

        if (zeroV[i] == 0) {    // 아직 방문 안했으면 방문.

            zeroV[i] = 1;   
            arr[zeroPos[i].first][zeroPos[i].second] = 1;

            
            // cout << "depth : " << depth << "\n";
            // cout << zeroPos[i].first << "  " << zeroPos[i].second << "\n";
            backTracking(depth + 1);
            zeroV[i] = 0;
            arr[zeroPos[i].first][zeroPos[i].second] = 0;



        }
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    // 입력
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 0) { 
                zeroPos.push_back(make_pair(i, j)); 
                zeroV.push_back(0); // 사이즈 같게 해주기 위함
            }

            if (arr[i][j] == 2) {
                twoPos.push_back(make_pair(i, j));
            }
        }
    }

    // 백트래킹으로 1 3개 박을때까지 진행 (depth = 0 -> 3) 
    backTracking(0);


    cout << maxCnt << "\n";

    return 0;
}