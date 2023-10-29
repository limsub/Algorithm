#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main()
{
    stack<int> x;
    int sum = 0;


    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int p;
        scanf("%d", &p);

        if (p == 0) {
            x.pop();
            //printf("pop\n");
        }
        else {
            x.push(p);
            //printf("push\n");
        }
    }

    int k = x.size();
    //printf("size : k\n");

    for (int i = 0; i < k; i++) {
        sum += x.top();
        x.pop();
        //printf("sum : %d\n", sum);
    }
    
    printf("%d", sum);

};