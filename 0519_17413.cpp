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
    
    string s_str;
    getline(cin, s_str);
    s_str += " ";

    stack<char> support_str;

    string result_str;

    int i = 0;
    
    while (i < s_str.length()) {

    

        if (s_str[i] == '<') {  // 괄호 안에 든 것들 처리

            while(!support_str.empty()) {
                    //cout << support_str.size() << endl;
                    result_str += support_str.top();
                    support_str.pop();
            }

            while (s_str[i] != '>') {   // > 나오기 전까지 순서대로 넣어주기
                result_str += s_str[i];
                i++;
            }
            result_str += s_str[i];     // > 까지 추가해주기
            i++;
        }


        else {

            support_str.push(s_str[i]);

            if (s_str[i] == ' ')  {  // 공백

                support_str.pop();      // 공백 하나 들어간거  빼준다.

                while(!support_str.empty()) {
                    //cout << support_str.size() << endl;
                    result_str += support_str.top();
                    support_str.pop();
                }
                // 공백 전에 넣어뒀던거 다 거꾸로 빼서 result에 더해준다

                result_str += " "; // 마지막으로 공백 추가해서 마무리

            }
            i++;
        }
    }

    string final_result_str = result_str.substr(0, result_str.length() - 1);

    cout << final_result_str << endl;
}