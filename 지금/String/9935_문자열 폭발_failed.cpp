#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;
#include <queue>
#include <cstdio>
#include <set>


// 9935 문자열 폭발

string str;
string expStr;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    cin >> str >> expStr;

    while (str.find(expStr) != string::npos) {  // expStr이 포함되어 있으면 계속 반복

        size_t pos = str.find(expStr);

        str.erase(pos, expStr.size());
    }

    if (str.empty()) { cout << "FRULA"; }
    else { cout << str << "\n"; }
    

    return 0;
}