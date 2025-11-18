#include <stdio.h>

int isvalid(char str[]) {
    int top = -1;
    char stk[100];

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];

        if (c == '(' || c == '{' || c == '[')
            stk[++top] = c;

        else if (c == ')' || c == '}' || c == ']') {
            if (top == -1) return 0; 

            char open = stk[top--];
            
            if ((c == ')' && open != '(') || (c == '}' && open != '{') || (c == ']' && open != '['))
                return 0;
            
        }
    }

    return top == -1;
}

int main() {
    char str[100];
    printf("Enter exp: ");
    scanf("%s", str); 
    printf("%d\n", isvalid(str));
    return 0;
}