#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;
#include <queue>
#include <cstdio>


// 21276 계보 복원가 호석

// 0. 변수
int N, M;
vector<string> arr(1001);

// 아래 벡터들은 모두 arr과 같은 인덱스로 판단
vector<int> indegree(1001); 

vector< vector<string> > adj(1001, vector<string>());
vector< vector<string> > reverseAdj(1001, vector<string>());    // 출력을 위한 자식 저장 배열


// arr의 몇 번째 인덱스에 해당 문자열이 저장되어있는지 반환
int findStringAdj(string s) {
    return find(arr.begin(), arr.end(), s) - arr.begin();
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    // 1. 입력
    // 1 - 1. N 입력
    cin >> N;

    // 1 - 2. 주민들 이름 입력
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 1 - 3. M 입력
    cin >> M;

    // 1 - 4. 그래프 입력
    for (int i = 0; i < M; i++) {
        string x, y;

        cin >> x >> y;  // cin : 공백이 들어오면 문자열의 끝이라고 판단

        // cout << "* : " << x << "\n";
        // cout << "* : " << y << "\n";

        // (1). y의 indegree 1 추가
        int yIndex = findStringAdj(y);
        indegree[yIndex]++;

        // (2). adj 그래프 추가 (뻗어나가는 것)
        int xIndex = findStringAdj(x);
        adj[xIndex].push_back(y);

        // (3). reverseAdj 그래프 추가 (들어오는 것)
        reverseAdj[yIndex].push_back(x);
    }


    // // 임시 확인
    // cout << "***** readj *****" << "\n";
    // for (int i = 0; i < N; i++) {
    //     cout << " ! " << i << " ! \n";
    //     for (int j = 0; j < reverseAdj[i].size(); j++) {
    //         cout << reverseAdj[i][j] << "  ";
    //     }
    //     cout << "\n";
    // }


    // 음.. 위상정렬 하지 말고, reverseAdj 이용해서 바로 풀어보자
    // -> 불가능. 자식 출력할 때 모든 자식을 출력하는게 아니라, 다이렉트로 연결된 자식만 출력해야 함.

    // 1. 시조 
    vector<string> ansParent;
    for (int i = 0; i < N; i++) {

        if (adj[i].empty()) {
            ansParent.push_back(arr[i]);
        }
    }
    sort(ansParent.begin(), ansParent.end());
    
    // 2. 자식
    vector<string> sortedArr;
    for (int i = 0; i < N; i++) {
        sortedArr.push_back(arr[i]);
    }
    sort(sortedArr.begin(), sortedArr.end());

    
    // final. 출력

    // 1. 시조 수
    cout << ansParent.size() << "\n";

    // 2. 시조 이름
    for (int i = 0; i < ansParent.size(); i++) {
        cout << ansParent[i] << " ";
    }
    if (ansParent.size() != 0) {
        cout << "\n";
    }
    

    for (int i = 0; i < N; i++) {
        string s = sortedArr[i];

        cout << s << " ";

        cout << reverseAdj[findStringAdj(s)].size();

        if (reverseAdj[findStringAdj(s)].size() != 0) {
            cout << " ";
        }

        for (int j = 0; j < reverseAdj[findStringAdj(s)].size(); j++) {
            cout << reverseAdj[findStringAdj(s)][j] << " ";
        }

        if (i != N-1) {
            cout << "\n";
        }
    }


    return 0;
}