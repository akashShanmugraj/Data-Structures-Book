#include <stdio.h>
#include <stdlib.h>

// Sturcture of Doubly Linked List
struct Node {
    int value;
    struct Node* prev, *next;
};

struct Node* getNode(int data);
struct Node* insertAtBeginning(struct Node* start, int data);
struct Node* insertAtEnd(struct Node* start, int data);
struct Node* deleteAtBeginning(struct Node* start);
struct Node* deleteAtEnd(struct Node* start);
struct Node* searchNode(struct Node* start, int element);
struct Node* insertAfterNodeX(struct Node* start, struct Node* NodeX, int data);
struct Node* insertBeforeNodeX(struct Node* start, struct Node* NodeX, int data);
struct Node* deleteAfterNodeX(struct Node* start, struct Node* NodeX);
struct Node* deleteBeforeNodeX(struct Node* start, struct Node* NodeX);
void displayLinkedList(struct Node* start);

// Menu Driver Code
int main() {
    struct Node* start = NULL, *newNode, *NodeX;
    int data, element, choice;

    do {
        printf("\nCircular Doubly Linked List Menu\n");
        printf("1. Add a node at beginning\n");
        printf("2. Add a node at end\n");
        printf("3. Delete the beginning node\n");
        printf("4. Delete the end node\n");
        printf("5. Search for a node with specific value\n");
        printf("6. Insert a node after a specific node\n");
        printf("7. Insert a node before a specific node\n");
        printf("8. Delete a node after a specific node\n");
        printf("9. Delete a node before a specific node\n");
        printf("10. Display Linked List\n");
        printf("Any other to Terminate\n");

        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                start = insertAtBeginning(start, data);
                break;
            
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                start = insertAtEnd(start, data);
                break;
            
            case 3:
                start = deleteAtBeginning(start);
                break;

            case 4:
                start = deleteAtEnd(start);
                break;
            
            case 5:
                printf("Enter the value to be searched: ");
                scanf("%d", &element);
                NodeX = searchNode(start, element);
                if (NodeX == NULL) printf("Value not found!\n");
                else printf("Value is found at node with address (%p)\n", NodeX);
                break;
            
            case 6:
                printf("Enter the value of NodeX: ");
                scanf("%d", &element);
                NodeX = searchNode(start, element);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                start = insertAfterNodeX(start, NodeX, data);
                break;
            
            case 7:
                printf("Enter the value of NodeX: ");
                scanf("%d", &element);
                NodeX = searchNode(start, element);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                start = insertBeforeNodeX(start, NodeX, data);
                break;

            case 8:
                printf("Enter the value of NodeX: ");
                scanf("%d", &element);
                NodeX = searchNode(start, element);
                start = deleteAfterNodeX(start, NodeX);
                break;
            
            case 9:
                printf("Enter the value of NodeX: ");
                scanf("%d", &element);
                NodeX = searchNode(start, element);
                start = deleteBeforeNodeX(start, NodeX);
                break;

            case 10:
                displayLinkedList(start);
                break;
            
            default:
                printf("Terminating..\n");
                exit(1);
        }
    } while (1);
}

// Creating a node in Doubly Linked List
struct Node* getNode(int data) {
    struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));
    newNode->value = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

// Insertion in Doubly Linked List
struct Node* insertAtBeginning(struct Node* start, int data) {
    struct Node* newNode = getNode(data), *current = start;
    // The list is empty
    if (start == NULL) {
        return newNode;
    }
    // The list is not empty
    current->prev = newNode;
    newNode->next = current;
    while (current->next != start) current = current->next;
    current->next = newNode;
    newNode->prev = current;
    start = newNode;
    return start;
}

struct Node* insertAtEnd(struct Node* start, int data) {
    struct Node* newNode = getNode(data), *current = start;
    // The list is empty
    if (start == NULL) {
        return newNode;
    }
    // The list is not empty
    current->prev = newNode;
    newNode->next = current;
    while (current->next != start) current = current->next;
    current->next = newNode;
    newNode->prev = current;
    return start;
}

// Deletion in Doubly Linked List
struct Node* deleteAtBeginning(struct Node* start) {
    // The list is empty
    if (start == NULL) {
        printf("The list is empty!\n");
        return start;
    }
    // The list is not empty
    // One element
    if (start->next == start) {
        free(start);
        return NULL;
    }
    else {
        struct Node* temp = start;
        start = start->next;
        start->prev = temp->prev;
        temp->prev->next = start;
        free(temp);
        return start;
    }
}

struct Node* deleteAtEnd(struct Node* start) {
    // The list is empty
    if (start == NULL) {
        printf("The list is empty!\n");
        return start;
    }
    // The list is not empty
    // One element
    if (start->next == start) {
        free(start);
        return NULL;
    }
    else {
        struct Node* temp = start->prev;
        start->prev = temp->prev;
        temp->prev->next = start;
        free(temp);
        return start;
    }
}

// Search for element
struct Node* searchNode(struct Node* start, int element) {
    struct Node* current = start;
    // If first node
    if (current->value == element) return current;
    current = current->next;
    while (current != start) {
        if (current->value == element) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Insertion, Deletion after or before NodeX
struct Node* insertAfterNodeX(struct Node* start, struct Node* NodeX, int data) {
    struct Node* current = start;
    int found = 0;
    // First node
    if (current == NodeX) found = 1;
    else {
        current = current->next;
        while (current != start) {
            if (current == NodeX) {
                found = 1;
                break;
            }
            current = current->next;
        }
    }
    if (!found) {
        printf("Node not found!\n");
        return start;
    }

    struct Node* newNode = getNode(data);
    newNode->next = current->next;
    current->next->prev = newNode;
    current->next = newNode;
    newNode->prev = current;
    return start;
}

struct Node* insertBeforeNodeX(struct Node* start, struct Node* NodeX, int data) {
    struct Node* current = start;
    int found = 0;
    if (current == NodeX) found = 1;
    else {
        current = current->next;
        while (current != start) {
            if (current == NodeX) {
                found = 1;
                break;
            }
            current = current->next;
        }
    }
    if (!found) {
        printf("Node not found!\n");
        return start;
    }

    struct Node* newNode = getNode(data);
    struct Node* beforeNode = current->prev;
    beforeNode->next = newNode;
    newNode->prev = beforeNode;
    newNode->next = current;
    current->prev = newNode;
    return start;
}

struct Node* deleteAfterNodeX(struct Node* start, struct Node* NodeX) {
    struct Node* current = start;
    int found = 0;
    if (current == NodeX) found = 1;
    else {
        current = current->next;
        while (current != start) {
            if (current == NodeX) {
                found = 1;
                break;
            }
            current = current->next;
        }
    }
    if (!found) {
        printf("Node not found!\n");
        return start;
    }

    // End node
    if (current->next == start) {
        struct Node* temp = current->next;
        current->next = start->next;
        start->next->prev = current;
        start = current;
        free(temp);

    }
    else {
        struct Node* temp = current->next;
        current->next = temp->next;
        temp->next->prev = current;
        free(temp);
    }
    return start;
}

struct Node* deleteBeforeNodeX(struct Node* start, struct Node* NodeX) {
    struct Node* current = start;
    int found = 0;
    if (current == NodeX) found = 1;
    else {
        current = current->next;
        while (current != start) {
            if (current == NodeX) {
                found = 1;
                break;
            }
            current = current->next;
        }
    }
    if (!found) {
        printf("Node not found!\n");
        return start;
    }

    if (current->prev == start) {
        struct Node* temp = current->prev;
        current->prev = start->prev;
        start->prev->next = current;
        start = current;
        free(temp);

    }
    else {
        struct Node* temp = current->prev;
        current->prev = temp->prev;
        temp->prev->next = current;
        free(temp);
    }
    return start;

}

// Display Doubly Linked List
void displayLinkedList(struct Node* start) {
    struct Node* current = start;
    // No nodes
    if (current == NULL) {
        printf("NULL");
        return;
    }
    printf("Start -> ");
    // Single node
    if (current->next == start) {
        printf("(%d) %d (%d) -> Start\n", current->prev, current->value, current->next);
        return;
    }
    // Multiple nodes
    else {
        printf("(%d) %d (%d) -> ", current->prev, current->value, current->next);
        current = current->next;
        while (current != start) {
            printf("(%d) %d (%d) -> ", current->prev, current->value, current->next);
            current = current->next;
        }
        printf("Start\n");
    } 
}