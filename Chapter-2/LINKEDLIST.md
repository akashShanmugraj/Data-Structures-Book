## Linked List - Linear

## Insertion
```c
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the linked list node
struct Node {
    int value;
    struct Node* next_address;
};

// Function to create a new node
struct Node* GetNode(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = item;
    newNode->next_address = NULL;
    return newNode;
}

// Function to insert a node in the linked list
void Insertion_Linkedlist(struct Node** start, int data, int item) {
    struct Node* newNode = GetNode(item);

    if (*start == NULL) {
        *start = newNode;
        return;
    }

    struct Node* current = *start;

    while (current->next_address != NULL) {
        if (current->value == data) {
            newNode->next_address = current->next_address;
            current->next_address = newNode;
            return;
        }
        current = current->next_address;
    }

    current->next_address = newNode;
}

// Function to print the linked list
void PrintList(struct Node* start) {
    struct Node* current = start;

    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next_address;
    }

    printf("NULL\n");
}

int main() {
    struct Node* start = NULL;

    // Example usage
    Insertion_Linkedlist(&start, 3, 10); // Insert 10 after node with data 3
    Insertion_Linkedlist(&start, 5, 20); // Insert 20 after node with data 5

    // Print the linked list
    PrintList(start);

    // Free allocated memory for the nodes
    while (start != NULL) {
        struct Node* temp = start;
        start = start->next_address;
        free(temp);
    }

    return 0;
}
```
## Deletion
```c
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the linked list node
struct Node {
    int value;
    struct Node* next_address;
};

// Function to create a new node
struct Node* GetNode(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = item;
    newNode->next_address = NULL;
    return newNode;
}

// Function to delete a node from the linked list
void Deletion_Linkedlist(struct Node** start, int data) {
    if (*start == NULL) {
        printf("The node is deleted\n");
        return;
    }

    struct Node* current = *start;
    struct Node* previous = *start;

    while (current != NULL) {
        if (current->value == data) {
            if (current == *start) {
                *start = current->next_address;
            } else {
                previous->next_address = current->next_address;
            }
            free(current);
            return;
        } else {
            previous = current;
            current = current->next_address;
        }
    }
}

// Function to print the linked list
void PrintList(struct Node* start) {
    struct Node* current = start;

    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next_address;
    }

    printf("NULL\n");
}

int main() {
    struct Node* start = NULL;

    // Example usage
    start = GetNode(10);
    start->next_address = GetNode(20);
    start->next_address->next_address = GetNode(30);

    // Print the original linked list
    printf("Original Linked List: ");
    PrintList(start);

    // Delete a node with value 20
    Deletion_Linkedlist(&start, 20);

    // Print the modified linked list
    printf("Linked List after Deletion: ");
    PrintList(start);

    // Free allocated memory for the nodes
    while (start != NULL) {
        struct Node* temp = start;
        start = start->next_address;
        free(temp);
    }

    return 0;
}
```

## Doubly Linked List
### Insertion
```c
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the doubly linked list node
struct Node {
    int value;
    struct Node* next_address;
    struct Node* previous_address;
};

// Function to create a new node
struct Node* GetNode(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = item;
    newNode->next_address = NULL;
    newNode->previous_address = NULL;
    return newNode;
}

// Function to insert a node in the doubly linked list
void Insertion_Doublylinkedlist(struct Node** start, int data, int item) {
    struct Node* newNode = GetNode(item);

    if (*start == NULL) {
        *start = newNode;
        return;
    }

    struct Node* current = *start;

    while (current->next_address != NULL) {
        if (current->value == data) {
            newNode->next_address = current->next_address;
            newNode->previous_address = current;
            current->next_address->previous_address = newNode;
            current->next_address = newNode;
            return;
        }
        current = current->next_address;
    }

    current->next_address = newNode;
    newNode->previous_address = current;
}

// Function to print the doubly linked list
void PrintList(struct Node* start) {
    struct Node* current = start;

    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next_address;
    }

    printf("NULL\n");
}

int main() {
    struct Node* start = NULL;

    // Example usage
    Insertion_Doublylinkedlist(&start, 3, 10); // Insert 10 after node with data 3
    Insertion_Doublylinkedlist(&start, 5, 20); // Insert 20 after node with data 5

    // Print the doubly linked list
    PrintList(start);

    // Free allocated memory for the nodes
    while (start != NULL) {
        struct Node* temp = start;
        start = start->next_address;
        free(temp);
    }

    return 0;
}
```

### Deletion
```c
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the doubly linked list node
struct Node {
    int value;
    struct Node* next_address;
    struct Node* previous_address;
};

// Function to create a new node
struct Node* GetNode(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = item;
    newNode->next_address = NULL;
    newNode->previous_address = NULL;
    return newNode;
}

// Function to delete a node from the doubly linked list
void Deletion_DoublyLinkedlist(struct Node** start, int data) {
    if (*start == NULL) {
        printf("The list is empty\n");
        return;
    }

    struct Node* current = *start;
    struct Node* previous = *start;

    while (current != NULL) {
        if (current->value == data) {
            if (current == *start) {
                *start = current->next_address;
                if (*start != NULL) {
                    (*start)->previous_address = NULL;
                }
            } else {
                previous->next_address = current->next_address;
                if (current->next_address != NULL) {
                    current->next_address->previous_address = previous;
                }
            }

            printf("The node is deleted\n");
            free(current);
            return;
        } else {
            previous = current;
            current = current->next_address;
        }
    }

    printf("Node with data %d not found\n", data);
}

// Function to print the doubly linked list
void PrintList(struct Node* start) {
    struct Node* current = start;

    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next_address;
    }

    printf("NULL\n");
}

int main() {
    struct Node* start = NULL;

    // Example usage
    start = GetNode(50);
    start->next_address = GetNode(150);
    start->next_address->previous_address = start;
    start->next_address->next_address = GetNode(3);
    start->next_address->next_address->previous_address = start->next_address;
    start->next_address->next_address->next_address = GetNode(320);
    start->next_address->next_address->next_address->previous_address = start->next_address->next_address;

    // Print the original doubly linked list
    printf("Original Doubly Linked List: ");
    PrintList(start);

    // Delete a node with value 150
    Deletion_DoublyLinkedlist(&start, 150);

    // Print the modified doubly linked list
    printf("Doubly Linked List after Deletion: ");
    PrintList(start);

    // Free allocated memory for the nodes
    while (start != NULL) {
        struct Node* temp = start;
        start = start->next_address;
        free(temp);
    }

    return 0;
}

```

### Polynomial Addition
```c
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the polynomial node
struct Node {
    int coefficient;
    int exponent;
    struct Node* next_address;
};

// Function to create a new node
struct Node* GetNode(int coefficient, int exponent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next_address = NULL;
    return newNode;
}

// Function to perform polynomial addition
struct Node* Polynomial_Addition(struct Node* start1, struct Node* start2) {
    struct Node* result = NULL;
    struct Node* temp1 = start1;
    struct Node* temp2 = start2;
    struct Node* newNode = NULL;

    while (temp1 != NULL && temp2 != NULL) {
        if (result == NULL) {
            result = newNode = GetNode(0, 0);
        } else {
            newNode->next_address = GetNode(0, 0);
            newNode = newNode->next_address;
        }

        if (temp1->exponent > temp2->exponent) {
            newNode->coefficient = temp1->coefficient;
            newNode->exponent = temp1->exponent;
            temp1 = temp1->next_address;
        } else if (temp1->exponent < temp2->exponent) {
            newNode->coefficient = temp2->coefficient;
            newNode->exponent = temp2->exponent;
            temp2 = temp2->next_address;
        } else {
            newNode->coefficient = temp1->coefficient + temp2->coefficient;
            newNode->exponent = temp1->exponent;
            temp1 = temp1->next_address;
            temp2 = temp2->next_address;
        }
    }

    while (temp1 != NULL) {
        newNode->next_address = GetNode(temp1->coefficient, temp1->exponent);
        temp1 = temp1->next_address;
        newNode = newNode->next_address;
    }

    while (temp2 != NULL) {
        newNode->next_address = GetNode(temp2->coefficient, temp2->exponent);
        temp2 = temp2->next_address;
        newNode = newNode->next_address;
    }

    return result;
}

// Function to print the polynomial
void PrintPolynomial(struct Node* start) {
    struct Node* current = start;

    while (current != NULL) {
        printf("(%dx^%d) ", current->coefficient, current->exponent);
        current = current->next_address;
        if (current != NULL) {
            printf("+ ");
        }
    }

    printf("\n");
}

int main() {
    struct Node* start1 = GetNode(2, 3);
    start1->next_address = GetNode(3, 2);
    start1->next_address->next_address = GetNode(5, 0);

    struct Node* start2 = GetNode(1, 3);
    start2->next_address = GetNode(4, 1);
    start2->next_address->next_address = GetNode(2, 0);

    struct Node* result = Polynomial_Addition(start1, start2);

    printf("Polynomial 1: ");
    PrintPolynomial(start1);

    printf("Polynomial 2: ");
    PrintPolynomial(start2);

    printf("Resultant Polynomial: ");
    PrintPolynomial(result);

    // Free allocated memory for the nodes
    while (start1 != NULL) {
        struct Node* temp = start1;
        start1 = start1->next_address;
        free(temp);
    }

    while (start2 != NULL) {
        struct Node* temp = start2;
        start2 = start2->next_address;
        free(temp);
    }

    while (result != NULL) {
        struct Node* temp = result;
        result = result->next_address;
        free(temp);
    }

    return 0;
}
```

### Sparse Matrices 1
```c
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the sparse matrix node
struct Node {
    int value;
    int rowNum;
    int columnNum;
    struct Node* nextRow;
    struct Node* nextColumn;
};

// Function to create a new node
struct Node* GetNode(int value, int rowNum, int columnNum) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->rowNum = rowNum;
    newNode->columnNum = columnNum;
    newNode->nextRow = NULL;
    newNode->nextColumn = NULL;
    return newNode;
}

// Function to create a sparse matrix
void Create_SparseMatrix(int m, int n) {
    struct Node* start_Row[m + 1]; // +1 to account for 1-based indexing
    struct Node* start_Column[n + 1]; // +1 to account for 1-based indexing
    int row_Number, column_Number, input_Value;

    // Create the header nodes for the rows
    for (int i = 1; i <= m; i++) {
        start_Row[i] = GetNode(0, i, 0);
        start_Row[i]->nextRow = start_Row[i];
        start_Row[i]->nextColumn = NULL;
    }

    // Create the header nodes for the columns
    for (int j = 1; j <= n; j++) {
        start_Column[j] = GetNode(0, 0, j);
        start_Column[j]->nextRow = NULL;
        start_Column[j]->nextColumn = start_Column[j];
    }

    // Input data
    while (1) {
        printf("Enter row number, column number, and value (separated by spaces, enter -1 to stop): ");
        scanf("%d %d %d", &row_Number, &column_Number, &input_Value);

        if (row_Number == -1 || column_Number == -1 || input_Value == -1) {
            break;
        }

        struct Node* newNode = GetNode(input_Value, row_Number, column_Number);

        // Place node in the row list
        struct Node* temp = start_Row[row_Number]->nextRow;
        struct Node* previous = start_Row[row_Number];

        while (temp != start_Row[row_Number] && temp->columnNum < column_Number) {
            previous = temp;
            temp = temp->nextRow;
        }

        previous->nextRow = newNode;
        newNode->nextRow = temp;

        // Place node in the column list
        temp = start_Column[column_Number]->nextColumn;
        previous = start_Column[column_Number];

        while (temp != start_Column[column_Number] && temp->rowNum < row_Number) {
            previous = temp;
            temp = temp->nextColumn;
        }

        previous->nextColumn = newNode;
        newNode->nextColumn = temp;
    }
}

int main() {
    int m, n;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);

    Create_SparseMatrix(m, n);

    // Print the sparse matrix (if needed)
    // This will depend on how you want to represent and print the matrix

    return 0;
}
```

### Addition of Sparse Matrices
```c
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the sparse matrix node
struct Node {
    int value;
    int rowNum;
    int columnNum;
    struct Node* nextRow;
    struct Node* nextColumn;
};

// Function to create a new node
struct Node* GetNode(int value, int rowNum, int columnNum) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->rowNum = rowNum;
    newNode->columnNum = columnNum;
    newNode->nextRow = NULL;
    newNode->nextColumn = NULL;
    return newNode;
}

// Function to create the header nodes for the columns
void Create_Header_Columns(struct Node* start_Column[], int n) {
    for (int j = 1; j <= n; j++) {
        start_Column[j] = GetNode(0, 0, j);
        start_Column[j]->nextRow = NULL;
        start_Column[j]->nextColumn = start_Column[j];
    }
}

// Function to create the header nodes for the rows
void Create_Header_Rows(struct Node* start_Row[], int m) {
    for (int i = 1; i <= m; i++) {
        start_Row[i] = GetNode(0, i, 0);
        start_Row[i]->nextRow = start_Row[i];
        start_Row[i]->nextColumn = NULL;
    }
}

// Function to perform addition of sparse matrices
void Addition_SparseMatrix(struct Node* start_Row1[], struct Node* start_Column1[],
                           struct Node* start_Row2[], struct Node* start_Column2[],
                           int m, int n) {
    struct Node* tempRow1;
    struct Node* tempRow2;
    struct Node* tempColumn1[n + 1];

    // Create the header nodes for the rows
    Create_Header_Rows(start_Row1, m);
    Create_Header_Rows(start_Row2, m);

    // Create the header nodes for the columns
    Create_Header_Columns(start_Column1, n);
    Create_Header_Columns(start_Column2, n);

    // Initialize tempColumn1
    for (int j = 1; j <= n; j++) {
        tempColumn1[j] = start_Column1[j];
    }

    // For each row in the matrices
    for (int i = 1; i <= m; i++) {
        tempRow1 = start_Row1[i]->nextRow;
        tempRow2 = start_Row2[i]->nextRow;

        struct Node* newNode;
        struct Node* tempRow3 = start_Row1[i];

        // Traverse until both row nodes are null
        while (tempRow1 != start_Row1[i] && tempRow2 != start_Row2[i]) {
            newNode = GetNode(0, 0, 0);

            if (tempRow1->columnNum == tempRow2->columnNum) {
                newNode->value = tempRow1->value + tempRow2->value;
                newNode->rowNum = tempRow1->rowNum;
                newNode->columnNum = tempRow1->columnNum;
                tempRow1 = tempRow1->nextRow;
                tempRow2 = tempRow2->nextRow;
            } else if (tempRow1->columnNum < tempRow2->columnNum) {
                newNode->value = tempRow1->value;
                newNode->rowNum = tempRow1->rowNum;
                newNode->columnNum = tempRow1->columnNum;
                tempRow1 = tempRow1->nextRow;
            } else {
                newNode->value = tempRow2->value;
                newNode->rowNum = tempRow2->rowNum;
                newNode->columnNum = tempRow2->columnNum;
                tempRow2 = tempRow2->nextRow;
            }

            tempRow3->nextRow = newNode;
            newNode->nextRow = tempRow1;
            tempRow3 = tempRow3->nextRow;
        }

        // Traverse until row1 nodes are null
        while (tempRow1 != start_Row1[i]) {
            newNode = GetNode(tempRow1->value, tempRow1->rowNum, tempRow1->columnNum);
            tempRow3->nextRow = newNode;
            newNode->nextRow = tempRow1->nextRow;
            tempRow1 = tempRow1->nextRow;
            tempRow3 = tempRow3->nextRow;
        }

        // Traverse until row2 nodes are null
        while (tempRow2 != start_Row2[i]) {
            newNode = GetNode(tempRow2->value, tempRow2->rowNum, tempRow2->columnNum);
            tempRow3->nextRow = newNode;
            newNode->nextRow = tempRow2->nextRow;
            tempRow2 = tempRow2->nextRow;
            tempRow3 = tempRow3->nextRow;
        }

        tempRow3->nextRow = start_Row1[i];
    }

    // Print the result (if needed)
    // This will depend on how you want to represent and print the resultant matrix
}

int main() {
    int m, n;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);

    struct Node* start_Row1[m + 1];
    struct Node* start_Column1[n + 1];
    struct Node* start_Row2[m + 1];
    struct Node* start_Column2[n + 1];

    Addition_SparseMatrix(start_Row1, start_Column1, start_Row2, start_Column2, m, n);

    return 0;
}
```
