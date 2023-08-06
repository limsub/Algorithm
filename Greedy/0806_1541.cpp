#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>



// 1541
// 그리디

// 더하기 빼기 문제
// 연속 더하기 애들 먼저 싹 계산하고 (괄호로 묶어줌)
// 그리고 빼기는 그냥 계산

// 입력 받는거에서 많이 막힌다.. 
// 따로따로 받지 말고, string으로 한 번에 받아야 할 듯

// 답지 참고 많이 함.. 알고리즘은 이해했는데 문자열로 구현하는 거에서 많이 헤멤

// 문자 기준으로 문자열 구분 -> return vector<string>
vector<string> split(string s, char x) {
    vector <string> tokens;
    stringstream mystream(s);
    string splitData;

    while (getline(mystream, splitData, x)) {
        tokens.push_back(splitData);
    }

    return tokens;
}

// + 기준으로 숫자 구분 -> return Sum (더하기로 묶인 숫자들의 합)
int mySum(string s) {
    int sum = 0;

    vector<string> tmp = split(s, '+');

    for (int i = 0; i < tmp.size(); i++) {
        sum += atoi(tmp[i].c_str());
    }

    return sum;
}



int main() {

    string s;
    cin >> s;

    vector<string> arr = split(s, '-');

    int ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        int sSum = mySum(arr[i]);

        if (i == 0) {
            ans += sSum;
        }
        else {
            ans -= sSum;
        }
    }

    printf("%d", ans);


    return 0;
}
