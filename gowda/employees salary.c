#include <stdlib.h>
#include <stdio.h>

struct emp {
    int id;
    char name[20];
    float salary;
};
int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    struct emp *e = (struct emp*) malloc(sizeof(struct emp) * n);
    if (e == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Enter ID for employee %d: ", i + 1);
        scanf("%d", &e[i].id);
        printf("Enter name for employee %d: ", i + 1);
        scanf("%s", e[i].name);
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &e[i].salary);
    }
    float total = 0;
    printf("\n--- Employee Details ---\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f\n",
               e[i].id, e[i].name, e[i].salary);
        total += e[i].salary;
    }
    printf("\nTotal Salary = %.2f\n", total);
    printf("Average Salary = %.2f\n", total / n);
    free(e); 
    return 0;
}

