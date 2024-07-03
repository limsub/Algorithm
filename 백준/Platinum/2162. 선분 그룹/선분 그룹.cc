#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long
#define INF 0x3F3F3F3F // INF + INF 연산할 일이 생길 수 있기 때문에 7로 안했다.

// 2162 선분 그룹
typedef struct _Line {
    int x1, y1;
    int x2, y2;
} Line;

int n; 
Line l[3010];
int p[3010];
// vector<int> p(3010, -1);
int cnt[3010];

int findP(int x) {
    // if (p[x] < 0) return p[x];
    if (p[x] == x) return p[x];

    return p[x] = findP(p[x]);
}

void unionP(int x, int y) {
    x = findP(x); y = findP(y);

    if (x < y) p[y] = x;
    else p[x] = y;
}

int CCW(int x1, int y1, int x2, int y2, int x3, int y3) {
    ll tmp = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);

    if (tmp < 0) return -1;
    else if (tmp > 0) return 1;
    
    return 0;
}

bool isCross(Line l1, Line l2) {
    int x1 = l1.x1; int y1 = l1.y1; int x2 = l1.x2; int y2 = l1.y2;
    int x3 = l2.x1; int y3 = l2.y1; int x4 = l2.x2; int y4 = l2.y2;

    if (CCW(x1, y1, x2, y2, x3, y3) * CCW(x1, y1, x2 ,y2, x4, y4) <= 0 &&
        CCW(x3, y3, x4, y4, x1, y1) * CCW(x3, y3, x4, y4, x2, y2) <= 0) 
    {

            if ( (x1 > x3 && x1 > x4 && x2 > x3 && x2 > x4) ||
                 (x3 > x1 && x3 > x2 && x4 > x1 && x4 > x2)
            ) {
                return false;
            }

            else if ( (y1 > y3 && y1 > y4 && y2 > y3 && y2 > y4) ||
                      (y3 > y1 && y3 > y2 && y4 > y1 && y4 > y2)
            ) {
                return false;
            }

            return true;
    }

    return false;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l[i].x1 >> l[i].y1 >> l[i].x2 >> l[i].y2;
        p[i] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (isCross(l[i], l[j])) {
                unionP(i, j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cnt[findP(i)]++;
    }


    int gCnt = 0;
    int max_ans = 0;

    for (int i = 0; i < n; i++) {
        if (cnt[i]) gCnt++;

        max_ans = max(max_ans, cnt[i]);
    }

    cout << gCnt << "\n";
    cout << max_ans << "\n";

    return 0;
}

