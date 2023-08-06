#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

#include <queue>



// 1931
// 그리디

// 맨 처음 : 가장 빨리 끝나는 회의 선택
// 회의 끝나는 시간 기준으로 가장 빠른 시작 시간 탐색 (같은 시작 시간일 때, 종료 시간이 빠른 회의 선택)

// pair를 어떻게 정렬하지? -> sort, compare

// 끝나는 시간 기준으로 정렬하자
bool compare(const pair<int, int>&a, const pair<int, int>&b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }

    return a.second < b.second;
}


int main() {
    int N;
    cin >> N;

    vector< pair<int, int> > arr;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        arr.push_back(make_pair(x, y));
    }

    sort(arr.begin(), arr.end(), compare);
    int cnt = 0;
    
    // 첫 회의 선택
    int end_time = arr[0].second;
    cnt++;

    int index = 1;
    while (index < N) {
        if (arr[index].first >= end_time) {
            cnt++;
            end_time = arr[index].second;
        }
        index++;
    }

    printf("%d", cnt);


    return 0;
}
