// 15652 - 백트래킹 dfs.. 15649 코드에서 수정하기
// 중복해서 선택 가능 -> 기존에 check 을 통해 중복 선택이 안되게 했으니까 그거 없애면 된다.
// 비내림차순 (오름차순이랑 비슷한데 같은 것도 가능 --> 15651 코드에서 check을 i 이전까지만 1로 만들어주자)


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

            if (c[i] == 0) {
                r[depth] = i;

                // i가 1이면 for 문이 돌아가지 않기 때문에 i > 1로 조건을 걸어주었다.
                if (i > 1) {
                    for (int j = 1; j < i; j++) {
                        c[j] = 1;
                    }
                }

                DFS(depth + 1);

                if (i > 1) {
                    for (int j = 1; j < i; j++) {
                        c[j] = 0;
                    }
                }
            }
        }
    }
}


int main() {

    scanf("%d %d", &N, &M);

    DFS(0);
    
    return 0;
}
