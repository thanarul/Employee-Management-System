#include "../include/headerA3.h"

void printAll (struct employee * headLL) {

    // assigns the pointer to the head of the linked list 
    struct employee *currentEmp = headLL;
    int num = 0;
    // iterates through the linked list 
    while (currentEmp != NULL) {
        // increment the counter
        num++;
        // prints out information
        printf("Employee %d:\n", num);

        printf("Employee Id: %d\n", currentEmp->empId);

        printf("First Name: %s\n", currentEmp->fname);

        printf("Last Name: %s\n", currentEmp->lname);

        printf("Dependents [%d]: ", currentEmp->numDependents);
        for (int i = 0; i < currentEmp->numDependents; i++) {
            printf("%s", currentEmp->dependents[i]);
            // if it is not the last dependent then print a comma to seperate it 
            if (i < currentEmp->numDependents - 1 ) {
                printf(",");
            }
        }
        printf("\n");
        printf("\n");

        // Move the current employee pointer to the next employee in the linked list
        currentEmp = currentEmp->nextEmployee;
    
    }

    printf("Currently there are %d employees.\n", num);
    // freeing the memory
    free(currentEmp);

}
