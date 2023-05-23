#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int maxCalculate(vector <vector<char> > arr, int N) {

    int max_cnt = 0;

    // 가로로 같은게 최대 몇개인지 찾아보자
    for (int i = 0; i < N; i++) {
    

        for (int j = 0; j < N - 1; j++) {
            int cnt = 1;

            for (int k = j; k < N - 1; k++) {
                if (arr[i][k] == arr[i][k+1]) {
                    cnt++;
                }
                else {
                    break;
                }
            }
            if (cnt > max_cnt) {
                max_cnt = cnt;
            }
        }
    }

    // 세로로 같은거
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N-1; i++) {
            int cnt = 1;

            for (int k = i; k < N - 1; k++) {
                if (arr[k][j] == arr[k+1][j]) {
                    cnt++;
                }
                else {
                    break;
                }
            }
            if (cnt > max_cnt) {
                max_cnt = cnt;
            }
        }
    }

    return max_cnt;
}

int main()
{
    int N;
    scanf("%d", &N);

    vector< vector<char> > arr(N, vector<char>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];

            
        }
    }

    //cout << maxCalculate(arr, N) << endl;

    int max_cnt = 0;

    // 오른쪽, 아래쪽만 바꾸는 경우를 생각하면 모든 케이스 커버 가능
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            // 오른쪽 끝이 아닌 경우, 오른쪽과 바꾸기
            if (j < N-1) {
                char x = arr[i][j];
                arr[i][j] = arr[i][j+1];
                arr[i][j+1] = x;

                int t = maxCalculate(arr, N);
                if (t > max_cnt) {
                    max_cnt = t;
                }

                // 원상복귀
                arr[i][j+1] = arr[i][j];
                arr[i][j] = x;
            }

            // 아래쪽 끝이 아닌 경우, 아래쪽과 바꾸기
            if (i < N-1) {
                char y = arr[i][j];
                arr[i][j] = arr[i+1][j];
                arr[i+1][j] = y;

                int p = maxCalculate(arr, N);
                if (p > max_cnt) {
                    max_cnt = p;
                }

                // 원상복귀
                arr[i+1][j] = arr[i][j];
                arr[i][j] = y;
            }
        }
    }

    cout << max_cnt << endl;




}