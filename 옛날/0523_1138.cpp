#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;


int main()
{
    int N;
    scanf("%d", &N);

    int arr[N];
    int real[N];

    for (int i = 0; i < N; i++ ) {
        scanf("%d", &arr[i]);   // 배열에 순서대로 저장
        real[i] = -1;           // real은 일단 모두 -1로 초기화
    }

    for (int i = 0; i < N; i++) {
        int x = arr[i];     // i의 왼쪽에 있는 i보다 큰 애들의 개수
        int cnt = 0;        // 맨 왼쪽부터 빈칸 개수
        

        for (int j = 0; j < N; j++) {
            if (real[j] == -1) { // 빈칸일 때마다 cnt++
                cnt++;
                if (cnt == x+1) { // 왼쪽부터 빈칸 개수가 i보다 큰 애들의 개수와 같아지면 그 다음 index가 i가 되어야 한다 그래서 그냥 x+1과 같은 걸로 잡아준다
                    real[j] = i+1;    // real에 (i+1)를 넣어준다.
                    break;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", real[i]);
    }



}