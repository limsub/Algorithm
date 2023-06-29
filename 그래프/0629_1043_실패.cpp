#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

// 1043 거짓말
int main() {

    // 첫번째 줄
    int N, M;
    scanf("%d %d", &N, &M);
    printf("N, M : %d %d\n", N, M);

    // 두번째 줄 - 진실 아는 애들 리스트
    int n; // 인원수
    scanf("%d", &n);
    vector<int> trueMan;
    if (n != 0 ) {
        int x;
        scanf("%d", &x);
        trueMan.push_back(x);
    }
    printf("n: %d\n", n);

    // 거짓말할 수 있는 파티의 수
    int ans_cnt = 0;

    // 앞으로 M개의 줄 - 각 파티 별 애들 리스트
    for (int i = 0; i < M; i++) {
        int m;  // 인원수
        scanf("%d", &m);
        int flag = 0;   // 거짓말을 할 수 있을까
        vector<int> thisMan; // 현재 파티 애들 리스트를 미리 저장해둔다.
        printf("m: %d\n", m);

        for (int j = 0; j < m; j++) {
            int y;
            scanf("%d", &y);
            thisMan.push_back(y);

            // 진실된 애가 있으면 거짓말을 할 수 없어.
            if (find(trueMan.begin(), trueMan.end(), y) != trueMan.end()) {
                flag = 1;
            }
        }

        // 거짓말을 할 수 없는 파티라면, 그 파티 애들을 모두 trueMan에 추가시켜줘
            if (flag == 1) {
                for (int k = 0; k < thisMan.size(); k++) {
                    trueMan.push_back(thisMan[k]);
                }
            }

            // 거짓말을 할 수 있는 파티라면, count ++
            if (flag == 0) {
                ans_cnt ++;
            }

            // thisMan에 있는 애들을 모두 초기화
            thisMan.clear();
    }

    printf("%d\n", ans_cnt);
    return 0;
}