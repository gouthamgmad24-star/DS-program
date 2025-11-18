#include <stdio.h>
#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;
int isFull() {
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}
int isEmpty() {
    return (front == -1);
}
void insertFront(int x) {
    if (isFull()) {
        printf("Deque is Full!\n");
        return;
    }
    if (front == -1) { // first element
        front = rear = 0;
    } else if (front == 0) {
        front = SIZE - 1;
    } else {
        front--;
    }
    deque[front] = x;
    printf("%d inserted at front.\n", x);
}
void insertRear(int x) {
    if (isFull()) {
        printf("Deque is Full!\n");
        return;
    }
    if (front == -1) { // first element
        front = rear = 0;
    } else if (rear == SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = x;
    printf("%d inserted at rear.\n", x);
}
void deleteFront() {
    if (isEmpty()) {
        printf("Deque is Empty!\n");
        return;
    }
    printf("%d deleted from front.\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}
void deleteRear() {
    if (isEmpty()) {
        printf("Deque is Empty!\n");
        return;
    }
    printf("%d deleted from rear.\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = SIZE - 1;
    } else {
        rear--;
    }
}
void display() {
    if (isEmpty()) {
        printf("Deque is Empty!\n");
        return;
    }
    int i = front;
    printf("Deque elements are: ");
    while (i != rear) {
        printf("%d ", deque[i]);
        i = (i + 1) % SIZE;
    }
    printf("%d\n", deque[rear]);
}

int main() {
    int choice, x;
    while (1) {
        printf("\n--- Double Ended Queue Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insertFront(x);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &x);
                insertRear(x);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid Choice!\n");
        }
    }
}
