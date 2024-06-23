#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long


// 20055 컨베이어 벨트 위의 로봇

// 로봇을 올리거나, 어디로 이동하면 그 칸의 내구도 -1
// 이동하기 위한 조건 : 이동하려는 칸에 1. 로봇이 없고, 2. 내구도 >= 1
// 내구도가 0인 칸의 개수가 K개 이상이면 과정 종료

// 참고 : https://hagisilecoding.tistory.com/109
// 0. start : 올리는 위치. end : 내리는 위치
// 1. start와 end를 각각 -1
    // 배열 원소들을 다 옮기는게 아니라, 인덱스로 계산해버린다.
    // 인덱스가 0이면, 2N-1로 바꿔줌
    // end에 로봇이 있으면 내려줌

// 2. 로봇을 옮긴다.
    // end부터 start까지 for loop
    // 1. 다음 위치에 로봇이 없는지
    // 2. 현재 위치에 로봇이 있는지
    // 3. 다음 위치의 내구도가 0보다 큰지
    
    // 이 조건을 만족하면 로봇 옮기기 가능 -> 다음 위치의 내구도 -1
    
    // 내구도 0 되면 개수 추가, 총 개수가 K개 이상이면 종료.
    
    // 다음 좌표에 로봇 추가. 현재 좌표 로봇 제거

// 3. 로봇을 올린다.
    // start의 내구도 확인 후, 로봇 올려준다.

// 3까지 수행하면 result + 1;


int N, K;
int st, en; // 올리는 위치, 내리는 위치 (처음 : 0, N-1)
int arr[202];   // 0 ~ 2N-1까지 내구도
int v[202]; // 0 ~ 2N-1까지 로봇 유무
int cnt;    // 내구도가 0인 위치 개수

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 입력
    cin >> N >> K;
    st = 0; en = N-1;
    for (int i = 0; i < 2 * N; i++) {
        cin >> arr[i];
        if (arr[i] == 0) cnt++;
    }


    // 2. 과정 시작
    bool flag = true;
    int result = 1; // 모두 수행하면 + 1 해주기 때문에 처음에 1로 시작
    while (flag) {
        // cout << st << " - " << en << "\n";
        // 2 - 1. 벨트 움직임
        // cout << " * 2 - 1\n";
        st--; en--;
        if (st == -1) st = 2 * N - 1;
        if (en == -1) en = 2 * N - 1;

        if (v[en]) v[en] = 0;   // 내리는 위치에 로봇이 있으면 내려준다.


        // 2 - 2. 로봇 움직임
        // cout << " * 2 - 2\n";
        int idx = en-1;
        // N-1번 수행해야 함 (en-1 ~ st)
        int T = N-1;
        while (T--) {
            int next = idx+1;   // 로봇의 다음 위치
            if (idx == -1) idx = 2 * N - 1; // 로봇의 현재 위치

            // cout << " ***** \n";
            // cout << "idx : " << idx << " next : " << next << "\n";
            // cout << " ***** \n";

            // 조건에 맞으면, 로봇을 옮긴다
            if (!v[next] && v[idx] && arr[next]) {
                // cout << "move\n";
                
                v[idx] = 0; 
                v[next] = 1;


                arr[next]--;
                // 내구도가 0 되었으면 카운트 추가
                if (arr[next] == 0) {
                    cnt++;
                    // 내구도 개수 이상이면 과정 종료
                    if (cnt >= K) {
                        flag = false;
                        break;
                    }

                }
            }

            // 옮긴 후, end 위치에 있는 로봇 내려준다
            v[en] = 0;


            idx--;
        }

        // 2 - 3. 로봇 올리기
        // cout << " * 2 - 3\n";
        if (arr[st] > 0) {
            // cout << "put\n";
            arr[st]--;
            if (arr[st] == 0) {
                cnt++;
                if (cnt >= K) {
                    flag = false;
                }
            }
            v[st] = 1;
        }
        

        if (!flag) break;

        result++;
    }

    cout << result;



    return 0;
}

