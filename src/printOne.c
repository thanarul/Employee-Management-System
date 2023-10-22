#include "../include/headerA3.h"

void printOne (struct employee * headLL, int whichOne) {
    struct employee * currEmployee = headLL;
     int currPosition = 1;
     // finds the employee at the position
     while (currPosition < whichOne && currEmployee != NULL) {
        
        currPosition++;
        currEmployee = currEmployee -> nextEmployee;
     }
     // if its not found it prints an error message
     if (currEmployee == NULL) {
        printf("Error: position %d does not exist", whichOne);
     }
     // prints all the details
        printf("Employee Id: %d\n", currEmployee -> empId);

        printf("First Name: %s\n", currEmployee -> fname);

        printf("Last Name: %s\n", currEmployee -> lname);

        printf("Dependents [%d]: ", currEmployee -> numDependents);
        for (int i = 0; i <  currEmployee -> numDependents; i++) {
            printf("%s", currEmployee -> dependents[i]);

            if (i < currEmployee -> numDependents - 1 ) {
                printf(",");
            }
        }

        printf("\n");
         
}
