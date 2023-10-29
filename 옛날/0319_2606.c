#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int N, M;

typedef struct {
    int name;
    struct Node* next;
} Node;


Node *list[110];
int visited[110];

int cnt = 0;

void dfs(int v) {

    Node* w = list[v];
    visited[v] = 1;
    cnt++;


    while(w->next != NULL) {
        w = w ->next;
        

        if (visited[w->name]== 0) {
            dfs(w->name);
        }
    }
    

    /*for (w = list[v]; w; w->next) {
        if (!visited[w->name])
            dfs(w->name);
    }*/
}

Node *newnode(int name) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->name = name;
    newNode->next = NULL;

    return newNode;
}

void addNode(Node *head, int name) {
    Node *addnode = newnode(name);

    Node *cur = head;
    while(cur->next != NULL) {
        cur = cur->next;
    } 
  
    cur->next = addnode;
}

int main() {

    int N, M;
    scanf("%d %d", &N, &M);


    // 맨 앞 노드 생성    
    for (int i = 1; i < N+1; i++) {
        list[i] = newnode(i);
    }
    for (int i = 0; i < M; i++) {
        int p, q;
        scanf("%d %d", &p, &q);

        addNode(list[p], q);
        addNode(list[q], p);
        
    }

    dfs(1);

    printf("%d", cnt - 1);
  
    return 0;
}
