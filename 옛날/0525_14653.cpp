#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main() {
    int N, K, Q;

    scanf("%d %d %d", &N, &K, &Q);

    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string member = alphabet.substr(1, N-1);

    int arr[K];
    char arr2[K];
    
    int flag = 0;

    for (int i = 0; i < K; i++) {
        int numDontRead;
        char sender;

        scanf("%d %c", &numDontRead, &sender);

        arr[i] = numDontRead;
        arr2[i] = sender;
        

        // 사실상 이때부터 시작
        if (i >= Q-1) {

            // 만약 이전과 값이 연속으로 동일하다면, 그 동일한 애들은 모두 읽었다는 뜻.
            int p = i;
            while (arr[p] == arr[p-1]) {
                for (int k = 0; k < member.length(); k++) {
                    if (member[k] == arr2[p-1]) {
                        member.erase(k, 1);
                    }
                }
                p--;
                if (p < 0) {
                    break;
                }

            }

            // 읽지 않은 수가 0이면 바로 종료
            if (numDontRead == 0) {
                flag = 1;
            }
            // member 문자열에 sender가 있다면 문자열에서 삭제
            for (int k = 0; k < member.length(); k++) {
                if (member[k] == sender) {
                    member.erase(k, 1);
                    break;
                }
            }

        }
    }

    if (flag == 1) {
        printf("%d", -1);
        return 0;
    }
    if (member.empty()) {
        printf("%d", -1);
        return 0;
    }

    for (int i = 0; i < member.length(); i++) {
        printf("%c ", member[i]);
    }

    

    // Q번째 메시지를 안읽었다는 증거(?)
    // - Q 이후에 메시지를 보내지 않았다. 
    // 이거 말고 또 있나?

    // 모든 사람들이 읽었다는 증거
    // - 메시지를 읽지 않은 사람의 수가 0
    // - 그 메시지 이후에 모든 애들이 메시지를 다 보냈어.

    // 그럼 앞에 입력되는 값들은 필요가 없는건가?

}