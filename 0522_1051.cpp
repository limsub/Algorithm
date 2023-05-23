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
    int N, M;
    scanf("%d %d", &N, &M);

    
    int arr[N][M];

    //fflush(stdin);
    
    char abc;
    scanf("%c", &abc);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char x;
            scanf("%c", &x);
            arr[i][j] = (int)x;
            //printf("%d", arr[i][j]);
            //printf("%c", x);
        }
        
        char def;
        scanf("%c", &def);
    }

    int maxLength = 0;
    int flag = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            
            int k = 1;

            while (i + k < N && j + k < M) {

                //printf("i : %d, j : %d, k : %d\n", i, j, k);

                //printf("%d %d %d %d\n", arr[i][j], arr[i][j+k], arr[i+k][j], arr[i+k][j+k]);

                if (arr[i][j] == arr[i][j+k] &&
                    arr[i][j] == arr[i+k][j] &&
                    arr[i][j] == arr[i+k][j+k]) {

                    //printf("hi\n");

                    if (k > maxLength) {
                        maxLength = k;
                        flag = 1;
                    }
                }

                k++;
            }
        }
    }
    if (flag == 0) {
        cout << 1 << endl;
    }
    else {
        cout << (maxLength+1) * (maxLength+1);
    }
}