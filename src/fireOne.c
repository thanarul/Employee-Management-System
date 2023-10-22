#include "../include/headerA3.h"

void fireOne (a3Emp ** headLL, int whichOne) {
    struct employee *currEmployee = *headLL;
    struct employee *prevEmployee = NULL;
    int num = 0;

    // counts the number of employees in the linked list
     while (currEmployee != NULL) {
        num++;
        currEmployee = currEmployee -> nextEmployee;
    }
    // checks and see if the index is valid 
    if (whichOne < 1|| whichOne > num) {

        printf("Invalid Number. There are %d employees in the list.\n", num);
        return;
    }

    currEmployee = *headLL;
    for (int i = 1; i < whichOne; i++) {
        prevEmployee = currEmployee;
        currEmployee = currEmployee -> nextEmployee;
    }

    // removes the employee from the linked list
    if (prevEmployee == NULL) {
        *headLL = currEmployee -> nextEmployee;
    }
    else {
         prevEmployee -> nextEmployee = currEmployee -> nextEmployee;
    }

    printf("Employee [Id: %d] fired. \n", currEmployee -> empId);
    num--;
    printf("There are now %d employees\n", num);

    // freeing the memory
    for(int i = 0; i < currEmployee->numDependents; i++){
        free(currEmployee->dependents[i]);
    }
    free(currEmployee->dependents);
    free(currEmployee);
}
