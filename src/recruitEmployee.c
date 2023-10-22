#include "../include/headerA3.h"

void recruitEmployee (struct employee ** headLL) {
    // assigns the pointer to the head of the linked list 
    a3Emp *newEmployee = *headLL;
    newEmployee = newEmployee->nextEmployee;
    newEmployee = malloc(sizeof(a3Emp));
    newEmployee -> nextEmployee = NULL;

    // asks the user to enter the first name and the last name 
    printf("Enter the first name of the employee: ");
    scanf("%s", newEmployee->fname);
    printf("Enter the last name of the employee: ");
    scanf("%s", newEmployee->lname);

    int empId = 0;
    // generating the empId
    for (int i = 0; i < strlen(newEmployee -> fname); i++) {
        empId += (int)newEmployee -> fname[i];
    }
    empId += strlen(newEmployee -> lname);
    // checking to see if the empId is unique and hasnt been used by another employee
    a3Emp *currentEmp = *headLL;
    while (currentEmp != NULL) {
        // if the employeeId is not unique it adds a random nunmber to it 
        if (currentEmp -> empId == empId) {

            empId += (rand() % 999) + 1;

            currentEmp = *headLL;
        }
        else {
            currentEmp = currentEmp -> nextEmployee;
        }
    }
    newEmployee -> empId = empId;

    // asking the user to enter the names of the employees dependents
    char c = 'y';
    int i = 0;
    char dependent[MAX_LENGTH];
    newEmployee -> numDependents = 0;
    newEmployee -> dependents = malloc(sizeof(char *));
    do {
        printf("Enter name of Dependent #%d: ", newEmployee -> numDependents + 1);
        scanf("%s", dependent);
        newEmployee->dependents[i] = malloc(sizeof(strlen(dependent)) + 1);
        strcpy(newEmployee->dependents[i], dependent);
        newEmployee -> numDependents++;
        i++;
        newEmployee->dependents = realloc(newEmployee->dependents, sizeof(char *) * (i+1));
        printf("Do you have any more dependents? ");
        scanf(" %c", &c);
        printf("\n");
    } while (c == 'y' || c == 'Y');
    
    // adding the new employee to the linked list
    if (*headLL == NULL) {
        *headLL = newEmployee;
    }
    else {
        currentEmp = *headLL;
        while (currentEmp -> nextEmployee != NULL) {
            currentEmp = currentEmp -> nextEmployee;
        }
        currentEmp -> nextEmployee = newEmployee;
    }

    // printing the number of dependents and the empId
    printf("You have %d dependents.\n",newEmployee -> numDependents);
    printf("Your computer-generated empId is %d\n", empId);  
}
