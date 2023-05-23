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
    // 1m2의 참외 개수
    int N;
    scanf("%d", &N);

    // 넓이 구하기 -> 전체 사각형 - 작은 사각형
    // 전체 사각형 : (좌/우로 받은거중에 가장 큰거) * (위/아래로 받은거중에 가장 큰거)


    vector<int> direction; // 방향 저장하는 벡터
    vector<int> distance;   // 길이 저장하는 벡터

    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int num4 = 0;

    
    // 변 6개 -> input 6개
    for (int i = 0; i < 6; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        switch(x) {
            case 1 :
                num1++;
                break;
            case 2 :
                num2++;
                break;
            case 3 :
                num3++;
                break;
            case 4 :
                num4++;
                break;
            default :
                break;
        }
        
        direction.push_back(x);
        distance.push_back(y);
    }

    int max_x = 0;
    int max_y = 0;

    for (int i = 0; i < 6; i++) {
        if (direction[i] == 1 || direction[i] == 2) {
            if (distance[i] > max_x) {
                max_x = distance[i];
            }
        }
        if (direction[i] == 3 || direction[i] == 4) {
            if (distance[i] > max_y) {
                max_y = distance[i];
            }
        }

    }

    
    int i = 0;

    int small_x;
    int small_y;

    while (1) {
        if (i == 6) {
            i = 0;
        }

        int x = i;
        int y = i+1;
        int z = i+2;
        int w = i+3;

        if (x > 5) {
            x = x - 6;
        }
        if (y > 5) {
            y = y - 6;
        }
        if (z > 5) {
            z = z - 6;
        }
        if (w > 5) {
            w = w - 6;
        }


        if (direction[x] == direction[z] && direction[y] == direction[w]) {
            small_x = distance[y];
            small_y = distance[z];          
            break;
        }


        i++;
    }

    //printf("max x : %d", max_x);
    //printf("max y : %d", max_y);
    //printf("small x : %d", small_x);
    //printf("small y : %d\n", small_y);

    cout << (max_x * max_y - small_x * small_y) * N << endl;


}