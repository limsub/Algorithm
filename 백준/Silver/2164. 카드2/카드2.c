#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_SIZE 1000000

int queue[MAX_SIZE];
int rear = -1;
int front = -1;

void addq(int x) {
    if (rear == MAX_SIZE-1)
        return;
    rear ++;
    queue[rear] = x;
}

int deleteq() {
    if (front == rear)
        return -1;
    front ++;
    return queue[front];
}



int main() {

    int N;
    scanf("%d", &N);

    if (N == 1) {
        printf("%d", 1);
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        addq(i);
    }

    while (1) {
        int x = deleteq();

        if (rear - front == 1)
            break;

        int y = deleteq();
        addq(y);
    }

    printf("%d", queue[rear]);

    return 0;
}