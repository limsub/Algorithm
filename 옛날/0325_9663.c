// 9663

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int N; // (1 <= N < 15)

int b[20];


int N_queen(int depth) {

    // depth 는 0부터 시작. 즉 몇 번째 행인지를 의미함.

    // depth가 N이면 모든 인덱스를 다 끝냈다는 것. 개수 하나 추가.
    if (depth == N)
        return 1;
    
    else {
        int cnt = 0; // 이번 depth에서 리턴할 값. 어쨌든 depth가 0일 때만 진짜 0부터 시작할 것.
        for (int i = 0; i < N; i++) {   // depth번째 행에 i번째 열을 확인한다.
            int check = 0; // 겹치는 게 있으면 1로 바꿔준다.
            for (int j = 0; j < depth; j++) {   // j는 몇 번째 열에 있는 퀸 때문에 실패하는지 확인한다. 여태까지 퀸을 놓은 개수가 depth일 것이므로 depth만큼 loop을 돌려준다
                if (b[j] == i // 같은 열에 있다는 뜻.
                    || abs(depth - j) == abs(i - b[j])) {   // 대각선에 있다는 뜻
                    check = 1;
                    break;
                }
            }

            // 여태까지 둔 퀸에 대해 검사했는데 멀쩡하면 그 위치에 새로운 퀸을 두고 재귀 시작
            if (!check) {
                b[depth] = i;
                cnt += N_queen(depth + 1);
            }
        }

        return cnt;
    }
}

int main() {

    scanf("%d", &N);

    for (int i = 0; i < N; i++) 
        b[i] = 0;

    printf("%d", N_queen(0));
    

    
    return 0;
}
