// 15651 - 백트래킹 dfs.. 15649 코드에서 수정하기
// 중복해서 선택 가능 -> 기존에 check 을 통해 중복 선택이 안되게 했으니까 그거 없애면 된다.

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

            r[depth] = i;
            DFS(depth + 1);
        }
    }
}


int main() {

    scanf("%d %d", &N, &M);

    DFS(0);
    
    return 0;
}
