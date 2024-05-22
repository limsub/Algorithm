#include <iostream>
#include <vector>
#include <string>
#include <stack>

#include <sstream>


using namespace std;

int main() {
	
    int N;
    scanf("%d", &N);
    char c;
    scanf("%c", &c);

    
    vector< stack<string> > S(N);

    string s;
    for (int i = 0; i < N; i++) {
        getline(cin, s);
        stringstream ss(s);

        string word;
        while (ss >> word) {
            S[i].push(word);
        }
    }

    string ans;
    getline(cin, ans);

    int ansflag = 0;
    
    stringstream sk(ans);
    string word2;

    stack<string> ans_S;
    while (sk >> word2) {
        ans_S.push(word2);
    }

    while (!ans_S.empty()) {

        int flag = 0;

        for (int i = 0; i < N; i++) {
            //cout << S[i].top() << endl;
            //cout << ans_S.top() << endl;

            if (!S[i].empty()) {
                if (S[i].top() == ans_S.top()) {
                    S[i].pop();
                    ans_S.pop();
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 0) {
            ansflag = 1;
            break;
        }
    }

    if (ansflag == 1) {
        cout << "Impossible" << endl;
    }
    else {
        cout << "Possible" << endl;
    }



    return 0;
}