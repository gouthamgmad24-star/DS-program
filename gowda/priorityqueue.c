#include <stdio.h>

#define MAX 100

int priority_queue[MAX];

int front = -1, rear = -1;

int check();
void push(int val);
int pop(int val);

int check(){
    for (int i = front; i < rear; i++){
        if (priority_queue[i] < priority_queue[i+1])
            return 0;
    }

    return 1;
}

void push(int val){
    int indexToPush;

    for (int i = front; i < rear; i++){
        if (priority_queue[i] > val && priority_queue[i+1] <= val)
            indexToPush = i+1;
    }
    for (int i = rear+1; i > indexToPush; i--){
        priority_queue[i] = priority_queue[i-1];
    }

    priority_queue[indexToPush] = val;

}

int main(){
    front = 0;
    rear = 3;

    priority_queue[0] = 9;
    priority_queue[1] = 10;
    priority_queue[2] = 7;
    priority_queue[3] = 6;
    printf("%d", check());
}
