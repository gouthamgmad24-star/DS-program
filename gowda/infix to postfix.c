#include <stdio.h>
#include <ctype.h>

#define SIZE 100

char stack[SIZE];
int top = -1;
 
int precedence(char c) {
    switch (c) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return -1;
    }
}

int isoperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void push(char c) {
    if (top < SIZE - 1) {
        stack[++top] = c;
    } 
    else {
        printf("Stack overflow\n");
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    } 
    else {
        return '\0';
    }
}

char peek() {
    if (top >= 0) {
        return stack[top];
    } 
    else {
        return '\0';
    }
}

int main() {
    char exp[SIZE];
    printf("Enter an infix expression:\n");
    scanf("%s", exp);

    printf("Postfix expression: ");

    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        if (c == ' ') continue;

        if (isalnum(c)) {
            printf("%c", c);  // Operand
        } 
        else if (c == '(') {
            push(c);
        } 
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                printf("%c", pop());
            }
            if (peek() == '(') pop();  // Remove '('
        } 
        else if (isoperator(c)) {
            while (top != -1 && precedence(c) <= precedence(peek())) {
                printf("%c", pop());
            }
            push(c);
        }
    }

    while (top != -1) {
        if (peek() != '(') {
            printf("%c", pop());
        } 
        else {
            pop();  // Discard any remaining '('
        }
    }

    printf("\n");
    return 0;
}