#include "../include/headerA3.h"

int lookOnId (struct employee * headLL, int whichEmpId) {
  // initializing the pointer to the head of the linked list
  struct employee * currEmployee = headLL;
  int currPosition = 1;
  // if the linked lisr is empty, print an error message
  if (headLL == NULL) {
    printf("LL is empty");
    return -1;
  }
  // iterating through the linked list 
  while (currEmployee != NULL) {

    if ((currEmployee -> empId) == whichEmpId) {

      return currPosition;
    }

    currEmployee = currEmployee -> nextEmployee;
    currPosition++;

  }
  
  return -1;

}
