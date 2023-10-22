#include "../include/headerA3.h"

int countEmployees (a3Emp * headLL) {

    int num = 0;

    struct employee *currEmployee = headLL;
    // checking to see if the linked list is empty
    if (headLL == NULL) {
      printf("LL is empty");
      return 0;
    }
    // iterating the linked list and counting the employees
    while (currEmployee != NULL) {
        num++;
        currEmployee = currEmployee -> nextEmployee;
    }
    // return the total number of employees
    return num;
}
