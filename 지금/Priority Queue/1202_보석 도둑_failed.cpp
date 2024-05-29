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


// 1202 보석 도둑
// 우선순위큐, 그리디, 정렬

// 약간 knapsack같기도 하고

// N : 보석의 개수
// K : 가방의 개수
// Mi : 보석의 무게, Vi : 보석의 가치 -> 보석은 총 N개
// Ci : 가방에 담을 수 있는 최대 무게 -> 가방은 총 K개

// <M, V>를 우선순위 큐에 넣는다. (V가 큰 거 우선, 만약 V 같으면 M 작은거)
// 큐에서 보석을 꺼내면, 적절한 가방에 넣어야 하는데, 이 기준을 잡기가 쉽지 않다.

// 가장 이상적인 방법
// 1. pq에 <M, V> 삽입 (V 큰거 우선, V 같으면 M 작은거)
// 2. 하나씩 pop() -> 가방에 넣는다.
// 3. 가방을 선택하는 기준 : 가방의 최대 무게(C)가 M과 가장 큰 차이가 나지 않는 것. => 이게 가장 이상적임.

// 원래 C를 그냥 정렬 때려서 하려고 했는데,,, 그렇다면 "M과 가장 큰 차이가 나지 않는" 게 보장되지 않음.
// 여기서 이분 탐색을 써야할까..?

// "가장 가까운"이라는게 굉장히 애매하다.
// 포기.

int N, K;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    


    return 0;
}