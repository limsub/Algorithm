#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>



// 1715
// 그리디


int main() {

    int N;
    cin >> N;
    vector<int> arr(N);
    priority_queue<int, vector<int>, greater<int> > arr2;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        arr2.push(arr[i]);
    }

    int ans = 0;
    while (arr2.size() > 1) {
        int x = arr2.top();
        arr2.pop();
        int y = arr2.top();
        arr2.pop();
        
        ans += (x+y);
        arr2.push(x+y);
    }

    printf("%d", ans);


   
    return 0;
}
