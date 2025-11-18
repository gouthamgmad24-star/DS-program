#include <stdio.h>

#define MAX_SIZE 20

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void push(Stack *stk, int elem);
void pop(Stack *stk, int *popped);
void peek(Stack stk);
void display(Stack stk);

// int main(){

//     Stack stk;
//     stk.top = -1;
//     int cont = 1;
//     int ch;

    
//     while (cont){
        
//         printf("\nEnter a choice:\n");
//         scanf("%d", &ch);

//         switch(ch){

//             case 0: display(stk); break;
//             case 1: {
//                     int elem;
//                     printf("Enter value to push:\n");
//                     scanf("%d", &elem);
//                     push(&stk, elem); break;
//                 }
//             case 2:{ 
//                     int popped;
//                     pop(&stk, &popped); break;
//             }

//             case 3: peek(stk); break;

//             case 4: display(stk); break;

//             default: cont=0; break;
//         }

//     }

//     return 0;

// }

void push(Stack *stk, int elem){

    int top = stk->top;
    if (top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }

    stk->top ++;

    stk->arr[stk->top] = elem;
    printf("Pushed %d into the stack\n", elem);
}

void pop(Stack *stk, int *popped){
    if (stk->top == -1){
        printf("Empty stack\n");
        return;
    }

    *popped = stk->arr[stk->top];
    printf("Popped element: %d\n", *popped);
    stk->top--;

    if (stk->top == -1) printf("Stack emptied\n");
}

void peek(Stack stk){
    if (stk.top == -1) {
        printf("Empty stack\n"); 
        return;
    }

    printf("The top value is:%d\n", stk.arr[stk.top]);
}

void display(Stack stk){
    printf("Stack: \n");
    for (int i=0; i <= stk.top; i++){

        printf("%d\n", stk.arr[i]);
    }
}