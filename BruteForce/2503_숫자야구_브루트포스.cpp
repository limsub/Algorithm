#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>
#include <cmath>

// 2503 숫자 야구 - 브루트 포스

// 이전에 물어본 것도 기억하고 테스트해야 함


bool checkDuplicateNum(int x) {

    string testNum = to_string(x);

    if (testNum[0] == testNum[1]
        || testNum[0] == testNum[2]
        || testNum[1] == testNum[2]) {
            return false;
    }

    if (testNum[0] == '0'
        || testNum[1] == '0'
        || testNum[2] == '0'
    ) {
        return false;
    }


    return true;
}

vector<int> testNums;
vector<int> testXs;
vector<int> testYs;

int main() {

    // cout << checkDuplicateNum(123) << endl;

    int T;
    cin >> T;

    vector<int> ansArr;
    for (int i = 111; i <= 999; i++) {
        if ( checkDuplicateNum(i) ) {
            ansArr.push_back(i);
            // printf("push back : %d\n", i);
        }
        
    }

    // for (int i = 0; i < ansArr.size(); i++) {
    //     printf("%d\n", ansArr[i]);
    // }



    for (int i = 0; i < T; i++) {

        int N, x, y;

        cin >> N >> x >> y;

        testNums.push_back(N);
        testXs.push_back(x);
        testYs.push_back(y);
        
        // ansArr을 돌면서 조건에 안맞는 애들은 제거
        for (int j = 0; j < ansArr.size(); j++) {
            int testNum = ansArr[j];
            string testStr = to_string(testNum);

            for (int t = 0; t < testNums.size(); t++) {
                
                string ansStr = to_string(testNums[t]);
                
                // 1. 스트라이크 x개만큼 있는지 확인
                int strikeCnt = 0;
                for (int k = 0; k < 3; k++) {
                    if (testStr[k] == ansStr[k]) { strikeCnt++; }
                }

                int ballCnt = 0;
                for (int p = 0; p < 3; p++) {
                    for (int q = 0; q < 3; q++) {
                        if (testStr[p] == ansStr[q] && p != q) { ballCnt ++; }
                    }
                }

                // printf("test : %d  s : %d  b : %d\n", testNum, strikeCnt, ballCnt);
                
                if (strikeCnt != testXs[t] || ballCnt != testYs[t]) { 
                    // ansArr.erase(ansArr.begin() + j);
                    ansArr[j] = -1;
                } else {
                    // printf("통과 : %d\n", testNum);
                }


            }

        }

    }

    int ans = 0;
    for (int i  = 0; i < ansArr.size(); i++) {
        if (ansArr[i] != -1) { ans++; }
        // printf("%d\n", ansArr[i]);
    }

    cout << ans << endl;
    return 0;
}

