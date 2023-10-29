// 15649 - 백트래킹 dfs.. 매우 어려움

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int N, M;

int r[10];
int c[10] = {0, };


void DFS(int depth) {

    // 깊이가 M이면, r(result)에 M개의 값이 저장되었으므로 출력할 준비가 됨.
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            printf("%d ", r[i]);
        }
        printf("\n");
    }

    else {
        for (int i = 1; i < N+1; i++) {
            if (c[i] == 0) { // c(check)가 되지 않은 애들로만 r에 저장해주어야 함.
                r[depth] = i;
                c[i] = 1;
                DFS(depth + 1); // depth가 M이 될때까지 DFS 들어감.
                c[i] = 0;
            }
        }
    }
}


int main() {

    scanf("%d %d", &N, &M);

    DFS(0);
    
    return 0;
}
