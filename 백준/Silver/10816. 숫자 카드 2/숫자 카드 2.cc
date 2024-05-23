#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;
#include <queue>
#include <cstdio>
#include <set>
#include <map>
// #include <pair>
// #include <bits/stdc++.h>


// 10816 숫자 카드 2
// 이분 탐색

// 이분 탐색 돌려서 인덱스 위치 찾는다. -> 해당 배열에서 그 위치 지워.

// 1% 틀. M개로 주는 숫자 중에 중복된 값이 있을 수 있기 때문에, 이미 지워버린 배열을 계속 사용할 수가 없다.

// 뭔가를 지우려고 하지 말고, 
// STL 메서드를 이용해서 해당 요소가 등장한 처음/마지막 인덱스를 가져온다.

int N; 
int arr[500010];
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
  
    // 1. 입력
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int x; cin >> x;
        v.push_back(x);
    }

    // 2. 정렬
    sort(arr, arr + N);


    // 3. 이분 탐색
    for (int i = 0; i < M; i++) {
        int num = v[i];

        int *first_idx = lower_bound(arr, arr + N, num);
        int *last_idx = upper_bound(arr, arr + N, num);

        cout << last_idx - first_idx << " ";
    }
    



    return 0;
}