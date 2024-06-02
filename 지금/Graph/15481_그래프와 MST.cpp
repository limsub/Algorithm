#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long

// 15481 그래프와 MST

// 그냥 호기심에...? 풀이 보면서 같이 풀어보자

// 1. MST를 만든다 (크루스칼 이용)
// 2 - 1. 간선이 MST에 포함되었다. -> MST의 가중치 출력
// 2 - 2. 간선이 MST에 포함되어 있지 않다
    // 새로운 간선 u-v를 연결한다
    // 그러면 u-v를 포함하는 사이클이 생긴다
    // 해당 사이클에서 u-v를 제외하고 가장 큰 가중치인 간선을 뺀다 (u-v가 무조건 최댓값일 것이다)


ll N, M;
vector< pair<ll, ll> > v[200010];       // 입력으로 받는 그래프 (모든 그래프)
vector< pair<ll, ll> > MST[200010];     // MST로 살아있는 그래프

// vector<ll> p(200010, -1);
ll p[200010];


ll find(ll x) { // 최종 부모 찾기
    if (p[x] == x) return x; // p값이 음수이면 걔가 최종 부모다.
    return p[x] = find(p[x]);
}

void uni(ll x, ll y) {  // 바로 합치기 (최종 부모가 다를 때만 실행)
    ll x1 = find(x); // x의 최종 부모 찾아 : x1
    ll y1 = find(y); // y의 최종 부모 찾아 : y1

    p[x1] = y1;  // x 그룹 애들은 이제 최종 부모가 y1
}

bool sameP(ll x, ll y) {
    ll x1 = find(x);    // x의 최종 부모 찾아 : x1
    ll y1 = find(y);    // y의 최종 부모 찾아 : y1

    return x1 == y1;
}

// MST 그래프를 만들어 vector MST를 완성시키고, 
// MST의 가중치 합을 리턴하는 함수
ll getMST() {   

    vector< pair<ll, pair<ll, ll> > > graph; // (cost, (x, y))

    for (ll i = 1; i <= N; i++) {   // i : 노드

        for (int j = 0; j < v[i].size(); j++) {
            ll node = v[i][j].first;
            ll cost = v[i][j].second;

            // 중복된 간선을 빼주기 위해, i >= j인 경우만 처리한다
            if (i < node) continue;
            graph.push_back({cost, {i, node}});
        }
    }

    for (ll i = 1; i <= N; i++) p[i] = i;


    ll ans = 0;

    // 간선의 가중치에 대해 정렬
    sort(graph.begin(), graph.end());

    // 크루스칼 알고리즘
    for (int i = 0; i < M; i++) {
        ll cost = graph[i].first;
        ll firstNode = graph[i].second.first;
        ll secondNode = graph[i].second.second;

        // 만약 이미 같은 그룹이면, continue
        if (sameP(firstNode, secondNode)) continue;

        // 다른 부모이면, 
        // 1. 부모 합치기
        uni(firstNode, secondNode);
        // 2. cost 더해주기
        ans += cost;

        // 3. 현재 MST로 인정된 그래프 생성
        MST[firstNode].push_back({secondNode, cost});
        MST[secondNode].push_back({firstNode, cost});
    }

    return ans; // MST의 가중치 합 리턴
}




// DFS : MST에서 각 노드의 depth를 계산.
// - 각 노드에서 조상 노드까지의 최댓값을 저장한다. 이는 두 노드 사이의 경로에서 최대 가중치를 찾기 위해 사용한다.
ll parent[200010][20];  // parent[node][i] : node의 2^i번째 조상 노드를 가리킨다.
ll mx[200010][20];  // 현재 노드에서 특정 조상 노드까지의 경로에서, 최대 간선 가중치를 계산 및 저장
                    // node에서 2^i번째 조상 노드로 가는 경로에서의 최대 간선 가중치를 저장한다.
ll depth[200010];

void dfs(ll node, ll up) {  // 얜 뭐하는걸까....?
    // (1, 0). 즉, 1부터 시작.
    // 1의 depth = 1. parent

    // 1. 여기서 무언가를 한다.
    depth[node] = depth[up] + 1;    // node의 depth는 up에 1 더한거 (depth 계산 후 저장)
    parent[node][0] = up;           // node의 parent는 방금 통해서 들어온 up (현재 노드의 부모 노드 저장)

    for (int i = 1; i < 20; i++) {
        
        ll p = parent[node][i-1];
        ll m = mx[node][i-1];

        parent[node][i] = parent[p][i-1];   // // 노드의  2^i단계 조상 설정
        mx[node][i] = max(m, mx[p][i-1]);   // 현재 노드에서 조상 조드까지의 경로에서 최대 간선 가중치 갱신
    }


    // 2. 이건 그냥 재귀함수 더 들어가는 코드.
    for (int i = 0; i < MST[node].size(); i++) {
        // node에 연결된 다음 노드로 간다

        ll nextNode = MST[node][i].first;
        ll cost = MST[node][i].second;


        if (nextNode != up) {   // 방금 넘어온게 아닌거 예외처리
            mx[nextNode][0] = cost;
            dfs(nextNode, node);
        }
    }
}


// MST에서 x와 y 사이 경로의 최대 간선 가중치를 찾는다.
// 즉, x-y 간선을 추가하게 되면 사이클이 생길거니까, 
// 기존에 연결되어 있던 것 중 최댓값을 빼려고 한다.
ll getMX(ll x, ll y) {

    ll ans = 0;
    if (depth[x] < depth[y]) {
        // x가 더 깊도록 조정한다. 이를 통해 깊이를 맞추는 과정에서 x를 더 쉽게 조정 가능
        swap(x, y);
    }

    // 1. 2^19단계부터 시작하여 깊이 맞춤을 진행한다
    for (int i = 19; i >= 0; i--) {
        
        ll p = parent[x][i];    // x의 2^i번째 조상
        if (depth[p] >= depth[y]) {
            // p가 y보다 깊이가 큰 경우, 즉, x를 한 번에 2^i단계만큼 위로 이동 가능한 경우.
            ans = max(ans, mx[x][i]);   // ans 갠신 : x에서 2^i단계 조상 노드까지의 경로의 최대 가중치와 비교
            x = p;  // x 갱신. y와 같은 깊이로 맞춘다.
        }
    }

    // 깊이를 맞추는 과정에서 두 노드가 동일한 노드가 되면, 
    // ans 반환. 두 노드는 이미 같은 노드로 올라갔기 때문에 최대 가중치가 계산되었다.
    if (x == y) return ans;
    

    // 2. 이제 같은 깊이에 있을 때, 공통 조상을 찾기 위해 각 단계에서 위로 올라간다
    for (int i = 19; i >= 0; i--) {
        if (parent[x][i] != parent[y][i]) {
            // x와 y의 2^i번째 조상이 다르면, 
            ll xm = mx[x][i];
            ll ym = mx[y][i];
            ans = max(ans, max(xm, ym));

            x = parent[x][i];
            y = parent[y][i];
        }
    }

    ans = max(ans, max(mx[x][0], mx[y][0]));
    return ans;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    vector< pair< pair<ll, ll>, ll> > edges;

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y, cost; cin >> x >> y >> cost;
        v[x].push_back({y, cost});
        v[y].push_back({x, cost});

        edges.push_back({{x, y}, cost});
    }

    ll MST_value = getMST();
    dfs(1, 0);  

    for (int i = 0; i < M; i++) {
        ll firstNode = edges[i].first.first;
        ll secondNode = edges[i].first.second;  
        ll cost = edges[i].second;

        if (parent[firstNode][0] == secondNode || parent[secondNode][0] == firstNode) {
            // first와 second를 잇는 간선이 MST에 포함되어있다.
            
            cout << MST_value << "\n";
        }
        else {
            // 그렇지 않다면, 
            // first와 second를 잇는 간선을 추가하고, 
            // 발생하는 사이클 내에서
            // 가장 큰 코스트를 뺀다
            cout << MST_value - getMX(firstNode, secondNode) + cost << "\n";
        }
    }


    return 0;
}