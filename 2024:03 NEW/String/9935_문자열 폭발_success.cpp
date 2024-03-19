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

    int str_len = str.length();
    int expStr_len = expStr.length();

    int st_idx = 0;

    stack< pair<char, int> > s;
    int match_len = 0;

    for (int i = 0; i < str_len; i++) {

        if (str[i] == expStr[match_len]) { match_len++; }

        else if (str[i] == expStr[0]) { match_len = 1; }

        else { match_len = 0; }

        s.push(make_pair(str[i], match_len));

        if (match_len == expStr_len) {
            for (int j = 0; j < expStr_len; j++) { s.pop(); }

            if (!s.empty()) { match_len = s.top().second; }
            else { match_len = 0; }
        }
    }

    int stack_sz = s.size();
    if (stack_sz == 0) { cout << "FRULA"; }
    
    char result[1000004];
    result[stack_sz] = 0;
    for (int i = stack_sz - 1; i >= 0; i--) {
        result[i] = s.top().first;
        s.pop();
    }
    cout << result << "\n";


    return 0;
}