#include "../include/headerA3.h"

void fireAll (a3Emp ** headLL) {
    
    // starting at the head of the linked list
    a3Emp *currEmployee = *headLL;
    // if the linked list is empty then it prints a message and exits
     if (*headLL == NULL) {
      printf("LL is empty");
      return;
     }

    // iterating through the employee in the linked list and freeing their memory
    while(*headLL != NULL) {
        currEmployee = *headLL;
        *headLL = (*headLL)->nextEmployee;
        for(int i = 0; i < currEmployee->numDependents; i++){
            free(currEmployee->dependents[i]);
        }
        free(currEmployee->dependents);
        free(currEmployee);

    }
    // set the head of the linked list to null
    *headLL = NULL;
    printf("All fired. Linked list is now empty\n");    

}

