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

    int N, M, B;
    scanf("%d %d %d", &N, &M, &B);

    vector< vector<int> > arr(N, vector<int>(M, 0));

    // 소요 시간
    
    int min_time = 0x7f7f7f7f;
    int max_height = 0;


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j] ;
        }
    }

    for (int h = 0; h <= 256; h++) {

        int to_build = 0;
        int to_remove = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {

                if (arr[i][j] > h) {
                    to_remove += (arr[i][j] - h);

                }
                else if (arr[i][j] < h) {
                    to_build += (h - arr[i][j]);
                }
            }
        }

        if (to_remove + B >= to_build) {
            int time_building = 2 * to_remove + to_build;
            if (time_building <= min_time) {
                min_time = time_building;
                max_height = h;
            }

        }

    }

    cout << min_time << ' ' << max_height << "\n";





}