/*
 * example_vars.c
 * A tiny C program demonstrating variables, identifiers, and keywords.
 * - Variables: int, float, char, const, unsigned, static, global, local
 * - Identifiers: names like age, price, show_scope
 * - Keywords: if, else, for, while, return, static, const
 */

#include <stdio.h>

/* Global variable (identifier: global_count). Has program-wide scope. */
int global_count = 42;

/* Demonstrates local and static storage inside a function. */
void show_scope(void) {
    int local_var = 5;          /* automatic (local) variable */
    static int static_var = 0;  /* static local — retains value between calls */
    static_var++;
    printf("[show_scope] local_var=%d, static_var=%d, global_count=%d\n",
           local_var, static_var, global_count);
}

int main(void) {
    /* Identifiers and variable declarations + initialization */
    int age = 25;               /* identifier: age (type: int) */
    float price = 99.99f;       /* identifier: price (type: float) */
    char grade = 'A';           /* identifier: grade (type: char) */
    const int MAX_USERS = 100;  /* const keyword + identifier */
    unsigned int u = 300u;      /* unsigned integer */

    printf("age=%d, price=%.2f, grade=%c, MAX_USERS=%d, u=%u\n",
           age, price, grade, MAX_USERS, u);

    /* Keywords in action: if / else */
    if (age > 18) {
        printf("Status: Adult\n");
    } else {
        printf("Status: Minor\n");
    }

    /* for loop (keyword: for) */
    for (int i = 0; i < 3; i++) {
        printf("for loop iteration: i=%d\n", i);
    }

    /* while loop (keyword: while) */
    int count = 0;
    while (count < 2) {
        printf("while loop count=%d\n", count);
        count++;
    }

    /* Show scope behavior and static variable persistence */
    show_scope();
    show_scope();

    /* Return (keyword: return) */
    return 0;
}
