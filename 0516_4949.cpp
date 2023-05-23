#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main()
{

    vector<string> ans_arr;

    while (1) {
        string str;
        getline(cin, str);

        if (str == ".") {
            break;
        }

        stack<char> s_stack;

        string ans = "yes";

        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(' || str[i] == '[') {
                s_stack.push(str[i]);
            }

            else if (str[i] == ')') {
                if (s_stack.empty()) {
                    ans = "no";
                    break;
                }

                if (s_stack.top() != '(' || s_stack.empty() ) {
                    ans = "no";

                    break;
                }
                s_stack.pop();
            }

            else if (str[i] == ']' ) {
                if (s_stack.empty()) {
                    ans = "no";
                    break;
                }
                if (s_stack.top() != '[' || s_stack.empty() ) {
                    ans = "no";

                    break;
                }
                s_stack.pop();
            }
        }


        if (!s_stack.empty()) {
            ans = "no";
        }
        ans_arr.push_back(ans);
    }

    for (int i = 0; i < ans_arr.size(); i++) {
        cout << ans_arr[i] << endl;
    }



}