#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;
#include <queue>
#include <cstdio>
#include <set>


// 2250 트리의 높이와 너비
int N;

int arr[10010][3];  // [0]: parent, [1]: left_child, [2]: right_child

int row_height[10010][2]; // [0] : row, [1] : level


int row_num = 1;
void inorder(int cur) {
    if (arr[cur][1] != -1) { inorder(arr[cur][1]); }
    // 탐색 -> row_num 지정
    row_height[cur][0] = row_num;
    row_num++;
    // cout << cur << " ";
    if (arr[cur][2] != -1) { inorder(arr[cur][2]); }
}




void bfs() {    // 시작 : 1
    int level_num = 1;
    row_height[1][1] = 1; // 1 (root node)의 level = 1

    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        // left child
        int lc = arr[cur][1];
        if (lc != -1) {
            row_height[lc][1] = row_height[cur][1] + 1;
            q.push(lc);
        }

        // right child
        int rc = arr[cur][2];
        if (rc != -1) {
            row_height[rc][1] = row_height[cur][1] + 1;
            q.push(rc);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int node, left_child, right_child;
        cin >> node >> left_child >> right_child;

        arr[node][1] = left_child;
        arr[node][2] = right_child;

        if (left_child != -1) { arr[left_child][0] = node; }
        if (right_child != -1) { arr[right_child][0] = node; }
    }

    // row 지정 -> inorder 이용해서 탐색하는 순서대로 번호 지정
    inorder(1);

    // level 지정 -> bfs 탐색하면서 parent + 1 만큼씩 level 지정
    bfs();

    // for (int i = 1; i <= N; i++) {
    //     cout << "i : " << i << " level : " << row_height[i][1] << " row : " << row_height[i][0] << "\n";
    // }


    // 레벨 별 가장 큰 너비를 가지는 값 찾는다
    // 시간복잡도 너무 별로야...
    int level_idx = 1;
    int max_width = 0;
    int v[10010]; // 탐색한 level

    for (int i = 2; i <= N; i++) {

        int level = row_height[i][1];
        int min_row = row_height[i][0];
        int max_row = row_height[i][0];

        if (v[level] != 0) { continue; }

        v[level] = 1;

        // 돌면서 같은 레벨의 min_row와 max_row 값 찾는다.
        for (int j = 2; j <= N; j++) {
            int new_level = row_height[j][1];
            int new_min_row = row_height[j][0];
            int new_max_row = row_height[j][0];

            if (level == new_level) {
                if (new_min_row < min_row) { min_row = new_min_row; }
                if (new_max_row > max_row) { max_row = new_max_row; }
            }
        }

        // cout << "000000\n";

        // cout << "level : " << level << " min_row : " << min_row << " max_row : " << max_row << "\n";

        int width = max_row - min_row + 1;
        
        if (width > max_width) { 
            max_width = width;
            level_idx = level; 
        }
    }

    cout << level_idx << " " << max_width;



    return 0;
}