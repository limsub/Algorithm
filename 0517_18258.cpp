#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);


    int N;
    cin >> N;


    
    queue<int> s_queue;

    for (int i = 0; i < N; i++) {
        string str;
        
        cin >> str;


        
        if (str.substr(0, 4) == "push") {
            //printf("push come\n");

            //int x = atoi((str.substr(5, 6)).c_str());
            int x;
            cin >> x;

            s_queue.push(x);
        }

        else if (str.substr(0, 5) == "front") {
            if (s_queue.empty()) {
                cout << -1 << "\n";
                //printf("%d\n", -1);
            }
            else {
            cout << s_queue.front() << "\n";
            }
        }

        else if (str.substr(0, 4) == "back") {
            if (s_queue.empty()) {
                cout << -1 << "\n";
                //printf("%d\n", -1);
            }
            else {
            cout << s_queue.back() << "\n";
            }
        }

        else if (str.substr(0, 5) == "empty") {
            if (s_queue.empty()) {
                cout << 1 << "\n";
                //printf("%d\n", 1);
            }
            else {
                cout << 0 << "\n";
                //printf("%d\n", 0);
            }
        }

        else if (str.substr(0, 4)== "size") {
            cout << s_queue.size() << "\n";
        }

        else if (str.substr(0, 3) == "pop") {
            if (s_queue.empty()) {
                cout << -1 << "\n";
                //printf("%d\n", -1);
            }
            else {
                cout << s_queue.front() << "\n";
                s_queue.pop();
            }
        }
    
    }

}