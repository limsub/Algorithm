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

    vector< vector<int> > course(N);
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        for (int j = 0; j < x; j++) {
            int y;
            scanf("%d", &y);
            course[i].push_back(y);
        }
    }


    int M;
    scanf("%d", &M);

    vector< vector<int> > student(M);
    for (int i = 0 ; i < M; i++) {
        int x;
        scanf("%d", &x);
        for (int j = 0; j < x; j++) {
            int y;
            scanf("%d", &y);
            student[i].push_back(y);
        }
    }

    // 정답 저장할 배열
    int ans[M];

    // 학생 도는 loop
    for (int i = 0; i < M; i++) {
        ans[i] = 0;
        
        // 수업 도는 loop
        for (int j = 0; j < N; j++) {
            
            // 수업의 모든 시간이 학생에 있는지 확인
            int flag = 0;
            
            for (int k = 0; k < course[j].size(); k++) {
                if (find(student[i].begin(), student[i].end(), course[j][k]) == student[i].end() ) { // 없으면
                    flag = 1; // 없으면 flag = 1
                }
                
            }
            
            if (flag == 0) {  // 모든 수업이 있으면
                ans[i]++;
            }
        }
    }


    for (int i = 0; i < M;i++) {
        printf("%d\n", ans[i]);
    }


}