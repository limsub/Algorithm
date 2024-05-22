#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

// 1043 거짓말

// 자구 시간에 배운 union-find 사용
int find_parent(int x, int *parent) {
    if (parent[x] != x) {
        parent[x] = find_parent(parent[x], parent);
        return parent[x];
    }

    return x;
}

void union_parent(int a, int b, int* parent) {
    int x = find_parent(a, parent);
    int y = find_parent(b, parent);

    if (x != y) {
        if (x < y ) {
            parent[y] = x;
        }
        else {
            parent[x] = y;
        }
    }
}


int main() {

    // 첫번째 줄
    int N, M;
    scanf("%d %d", &N, &M);
    //printf("N, M : %d %d\n", N, M);

    // 초기 parent는 자기 자신
    int parent[N+1];
    for (int i = 0; i < N+1; i++) {
        parent[i] = i;
    }
    

    // 두번째 줄 - 진실 아는 애들 리스트
    int n; // 인원수
    scanf("%d", &n);
    vector<int> trueMan;
    if (n != 0 ) {
        for (int p = 0; p < n; p++) {
            int x;
            scanf("%d", &x);
            trueMan.push_back(x);
            parent[x] = 0;      // 진실 아는 애들은 parent = 0
        }
        
    }
    //printf("n: %d\n", n);

    



    vector< vector<int> > thisMan(M);   // 파티 별 애들 리스트

    // 앞으로 M개의 줄 - 각 파티 별 애들 리스트
    for (int i = 0; i < M; i++) {
        int m;  // 인원수
        scanf("%d", &m);

        // vector<int> thisMan; // 현재 파티 애들 리스트를 미리 저장해둔다.
        //printf("m: %d\n", m);

        // 첫번째 애 부터 저장
        int y;
        scanf("%d", &y);
        thisMan[i].push_back(y);

        // 두번째 애들부터 받아서 첫번째 애랑 같은 parent로 union
        // 문제는 여기서 맨 마지막 애만 parent가 0이면 그 앞에 애들은 아직 업데이트가 안된다
        // 그래서 마지막에 ans_cnt 검사할 때 모든 애들에 대해 검사를 진행해야 한다
        // 라고 생각했지만 그렇게 해도 아닌 애들만 있는 party는 또 해당이 되지 않는다...
        // 그렇다면 parent를 union할 때, 기존에 값들도 전부 update해주는 과정이 필요하지 않을까
        // 라고까지 복잡하게 생각했지만, 사실 이게 아니고 find_parent 함수를 사용하면 되는 문제였구나
        for (int j = 1; j < m; j++) {
            int t;
            scanf("%d", &t);
            thisMan[i].push_back(t);
            union_parent(y, t, parent);
        }
    }


    /*for (int i = 1; i < N+1; i++) {
        printf("parent %d : %d\n", i, parent[i]);    
    }*/


    // thisMan 돌면서 parent가 0인 party는 거짓말 불가능
    int ans_cnt = 0;
    for (int i = 0; i < M; i++) {
        if (find_parent(thisMan[i][0], parent) != 0) {
            ans_cnt++;
        }

    }

    printf("%d\n", ans_cnt);



   
    return 0;
}