# 우선순위 큐
- `vector` 와 같은 **container adaptor** 의 한 종류
- 내부적으로 `heap` 자료구조 사용
- `<queue>` 헤더에 있는 `std::priority_queue` 클래스 사용


<br>


### 선언
- 주의 : `compare` 함수 호출 방법이 정렬할 때와 다름
```c++
// int
struct cmp {
	bool operator()(int a, int b) {
		return a < b;
	}
};
priority_queue<int, vector<int>, greater<int>> pq;
priority_queue<int, vector<int>, less<int>> pq;
priority_queue<int, vector<int>, compare<int>> pq;
```


<br>


### 이슈
- 큐의 원소가 없을 때에도, `top()` 은 **큐의 마지막 원소** 값을 계속해서 반환한다. while문에서 무한루프 주의해야 한다.
- 하지만, 아무것도 `push`하지 않은 상태에서 `top()`을 호출하면 **Segmentation fault** 발생
- 이 이슈는 `vector` 에서도 동일하게 발생. 아마 **STL Container** 의 공통 사항이지 않을까 예상
```c++
// 선언 및 원소 추가
priority_queue<int> pq;
pq.push(1);
pq.push(2);
pq.push(3);


// empty() 이용한 while문
while (!pq1.empty()) {
	cout << pq1.
}

// 출력
/*
3
2
1
*/


// top() 이용한 while문 (무한루프 발생)
while (pq.top() >= 1) {
    cout << pq.top() << "\n";
    pq.pop();
}

// 출력
/*
3
2
1
1
1
...
*/
```


<br>


### 시간복잡도
- 우선순위 큐는 요소를 추가, 제거할 때 내부적으로 **Binary Heap** 구조로 최적화<br>
-> 가장 높은 우선순위 요소에 빠르게 접근할 수 있다.


- 삽입 (Insertion) :    
    **O(log n)** : (**Binary Heap** 사용 시, 데이터 삽입 O(log n) 소요)
    `push(element)`
    
- 최상위 요소 접근 :
    **O(1)**
    `top()` 
    
- 최상위 요소 제거 : 
    **O(log n)**
    `pop()`
    
- 요소 개수 확인 : 
    **O(1)**
    `size()`


<br>


### 활용 알고리즘
- **다익스트라 알고리즘 (Dijkstra’s Algorithm)**
    - 최소 경로 탐색 알고리즘
    - 각 노드까지의 최단 거리를 유지하면서 노드 탐색하며 최단 경로 탐색할 때 활용

- **프림 알고리즘 (Prim’s Algorithm)**
    - 최소 신장 트리 (Minimum Spanning Tree) 탐색 알고리즘
    - 정점들 연결하면서 최소 비용 유지하며 트리 확장하는데 활용

- **A* 알고리즘 (A-start Algorithm)**
    - 지정된 출발점에서 목표 지점까지 최단 경로 탐색 알고리즘
    - 휴리스틱 함수와 함께 사용해서 최적 경로 탐색

- **힙 정렬 (Heap Sort)**
    - 우선순위 큐 활용해서 정렬

- **크루스칼 알고리즘 (Kruskal’s Algorithm)**
    - 그래프에서 가장 적은 비용으로 모든 노드 연결
    - 간선을 가중치에 따라 정렬하고, 우선순위 큐 사용해서 사이클 방지하면서 최소 신장 트리 구성

- **위상 정렬 (Topological Sort)**
    - 방향 그래프에서 노드 간 위상 정렬
    - 선행 조건을 갖는 작업들 순서대로 정렬

- **문자열 검색 알고리즘 (ex. Efficient String Searching)**
    - 우선순위 큐로 인덱스 관리, 먼저 발견된 패턴을 큐에서 꺼낸다.