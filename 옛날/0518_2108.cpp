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
    int N;
    scanf("%d", &N);

    int arr[N];
    map<int, int> countMap;

    int sum = 0;
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        sum += x;

        arr[i] = x;

        countMap[x] = 0;
    }

    for (int i = 0; i < N; i++) {
        int t = arr[i];
        countMap[t]++;
    }

    //printf("---\n");
    // 1.
    double ans1_sum = sum;
    double ans1_N = N;
    double ans1 = round((ans1_sum / ans1_N));
    if (ans1 < 0.5 && ans1 >= -0.5) {
        ans1 = 0;
    }
    
    printf("%.0f\n", ans1);
    

    // 2. 
    sort(arr, arr + N);
    printf("%d\n", arr[N/2]);

    // 3. 
    vector<int> modes;
    int max = 0;
    int max_i = -1;
    for (auto iter = countMap.begin(); iter != countMap.end(); iter++) {
        if (iter->second > max) {
            modes.clear();
            modes.push_back(iter->first);
            max = iter->second;
        }
        else if (iter->second == max) {
            modes.push_back(iter->first);
        }
    }
    int ans3 = modes.size() > 1 ? modes[1] : modes[0];
    printf("%d\n", ans3);


    // 4. 
    int ans4 = arr[N-1] - arr[0];
    printf("%d\n", ans4);

}