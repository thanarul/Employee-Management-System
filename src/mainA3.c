#include "../include/headerA3.h"

int main() {

    // initalizing my variables
    struct employee * headA3 = NULL;
    struct employee * temp = NULL;
    int choice;
    loadEmpData (&headA3, "proFile.txt");
    temp = headA3;
    printAll(temp);
    int position;
    int whichOne;
    int whichEmpId;
    int totalNum;
    int fire;
    char choiceFunc9;
    char whichName [100];

    do {
        // printing the menu
    printf("1. Add a new employee\n");
    printf("2. Print data of all employees\n");
    printf("3. Print data of the nth employee\n");
    printf("4. Search for employee based on empId\n");
    printf("5. Search for employee based on full name\n");
    printf("6. Count the total number of employees\n");
    printf("7. Sort the employees based on their empId\n");
    printf("8. Remove the nth employee in the current LL\n");
    printf("9. Remove all employees in the current LL\n");
    printf("10. Exit.\n");
    printf("Choose a menu option: ");
    scanf("%d", &choice);

    // switch statement that contains the function calls for each case
    switch (choice) {
        case 1:
        // Task 1: Add a new Employee
        recruitEmployee (&headA3);
        printf("\n");
        break;

        case 2:
        // Task 2: Print all employees
        printAll(headA3);
        break;

        case 3: 
        // Task 3: Print one employee
        printf("\n");
        printf("Enter a position: ");
        scanf("%d", &whichOne);
        printOne(headA3, whichOne);
        break;

        case 4:
        // Task 4: Find employee by id
        printf("\n");
        printf("Enter an employee ID: ");
        scanf("%d", &whichEmpId);
        position = lookOnId(headA3, whichEmpId);
        printOne(headA3,position);
        break;

        case 5:
        // Task 5: Look by full name
        printf("Enter the full name of the employee: ");
        getchar();
        fgets(whichName, 100, stdin);
        whichName[strlen(whichName)-1] = '\0';
        position = lookOnFullName(headA3, whichName);
        printOne(headA3, position);
        break;

        case 6:
        // Task 6: Count Employees
        totalNum = countEmployees(headA3);
        printf("\n");
        printf("Total number of employees = %d\n", totalNum);
        break;

        case 7:
        // Task 7: Sort Employees By id
        printf("After sorting on empId, the employees are as follows: \n");
        sortEmployeesId(headA3);
        break;

        case 8:
        // Task 8: Fire one employee
        printf("Currently there are %d employees. \n", countEmployees(headA3));
        printf("Please select which number you want to fire - enter a value between 1 and %d: ", countEmployees(headA3));
        scanf("%d", &fire);
        fireOne(&headA3,fire);
        break;

        case 9:
        // Task 9: Fire all employees
        printf("Are you sure you want to fire everyone: ");
        scanf(" %c", &choiceFunc9);
        if (choiceFunc9 == 'y' || choiceFunc9 == 'Y') {
            fireAll(&headA3);
        }
        else if (choiceFunc9 == 'n' || choiceFunc9 == 'N') {
            printf("Nobody has been fired\n");
        }
        break;

        case 10:
        break;

        default: 
        printf("This is an invalid choice. Please enter a number through 1 - 10\n");
    
    }
    
  } while (choice != 10);

  // freeing the memory that was allocated
  while(headA3 != NULL) {
    temp = headA3;
    headA3 = headA3->nextEmployee;
    if(temp->dependents != NULL) {
    for (int i = 0; i < temp->numDependents; i++) {
            free(temp->dependents[i]);
        }
    free(temp->dependents);
    free(temp);
  }
  }

}
