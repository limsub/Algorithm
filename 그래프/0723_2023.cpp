#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>


// 2034
// 먼저 한자리 수 (맨 앞자리) 가 소수여야 하기 때문에
// 맨 앞자리 수는 2, 3, 5, 7 중에 하나여야 한다.

// 두 자리 이후 수도 소수여야 한다
// 최소한 짝수는 아니기 때문에
// 이후 자리 수는 1, 3, 5, 7, 9 중에 하나여야 한다.

// 이런 식으로 DFS를 이어간다. 만약 이어가는 중에 소수가 아닌 수로 판단되면
// DFS를 중단한다

// 맨 마지막 자리 수까지 소수인 게 판단되면 출력한다

vector<int> firstNum;
vector<int> afterNum;

bool isPrime(int x) {
    for (int i = 2; i < x/2; i++) {
        if (x%i == 0) {
            return false;
        }
    }

    return true;
}

void dfs(int n, int currentN, int currentNum) {

    if (n == currentN) {
        printf("%d\n", currentNum);
        return;
    }

    for (int i = 0; i < 5; i++) {
        int x = currentNum * 10 + afterNum[i];

        if (isPrime(x)) {
            dfs(n, currentN + 1, x);
        }
    }

}

int main() {

    int N;
    cin >> N;


    firstNum.push_back(2);
    firstNum.push_back(3);
    firstNum.push_back(5);
    firstNum.push_back(7);
    //firstNum = vector<int> {2, 3, 5, 7};
    
    afterNum.push_back(1);
    afterNum.push_back(3);
    afterNum.push_back(5);
    afterNum.push_back(7);
    afterNum.push_back(9);
    //afterNum = vector<int> {1, 3, 5, 7, 9};

    for (int i = 0; i < 4; i++) {
        dfs(N, 1, firstNum[i]);
    }

    return 0;
}
