#include "../include/headerA3.h"

void sortEmployeesId (struct employee * headLL) {
    // assigns the pointer to the head of the linked list 
    struct employee *currEmployee = headLL;
    int *array;
    int len = countEmployees(headLL);
    // allocating memory
    array = malloc(sizeof(int)*len);
    int num = 0;
    int temp;

    // // iterating through the linked list and storing the empId in the array
    while (currEmployee != NULL) {
        array[num] = currEmployee->empId;
        num++;
        currEmployee = currEmployee->nextEmployee;
    }

    // bubble sort algorithm
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (array[j] > array [j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    // printing out the sorted list
    for (int i = 0; i < len; i++) {
        printf("Employee #%d: ", i+1);
        printOne(headLL, lookOnId(headLL,array[i]));
    }

    // freeing memory
    free(array);
    
}
