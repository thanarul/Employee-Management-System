#include "../include/headerA3.h"

int lookOnFullName (struct employee * headLL, char whichName [100]) {

    // assigns the pointer to the head of the linked list 
    struct employee *currEmployee = headLL;
    int currPosition = 0;
    // splitting the string into the first name and last name using strtok 
    char *firstName;
    char *lastName;
    firstName = strtok(whichName, " ");
    lastName = strtok(NULL, " ");
    // check if the linked list is null
    if (headLL == NULL) {
      printf("LL is empty");
      return -1;
    }  

    // iterating through the linked list 
    while (currEmployee != NULL) {
        // increment the counter
        currPosition++;

        // check to see if the current employee's first name and last name matches the inputted first name and last name
        if ((strcmp(currEmployee->fname, firstName) == 0 ) && (strcmp(currEmployee->lname, lastName) == 0)) {
            
            return currPosition;
        }

        // moves the current employee pointer to the next employee 
        currEmployee = currEmployee->nextEmployee;
    }

     return -1;

}
