#include <stdio.h>
#include <stdlib.h>

// Sturcture of Doubly Linked List
struct Node
{
    int value;
    struct Node *prev, *next;
};

// Function declarations
struct Node *getNode(int data);
struct Node *insertAtBeginning(struct Node *start, int data);
struct Node *insertAtEnd(struct Node *start, int data);
struct Node *deleteAtBeginning(struct Node *start);
struct Node *deleteAtEnd(struct Node *start);
struct Node *searchNode(struct Node *start, int element);
struct Node *insertAfterNodeX(struct Node *start, struct Node *NodeX, int data);
struct Node *insertBeforeNodeX(struct Node *start, struct Node *NodeX, int data);
struct Node *deleteAfterNodeX(struct Node *start, struct Node *NodeX);
struct Node *deleteBeforeNodeX(struct Node *start, struct Node *NodeX);
void displayLinkedList(struct Node *start);

// Menu Driver Code
int main()
{
    struct Node *start = NULL, *newNode, *NodeX; // Assign head/start node to NULL
    int data, element, choice;

    do
    {
        printf("\nDoubly Linked List Menu\n");
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
        switch (choice)
        {
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
            if (NodeX == NULL)
                printf("Value not found!\n");
            else
                printf("Value is found at node with address (%p)\n", NodeX);
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
            // Deallocate pointers when exiting
            free(start);
            free(newNode);
            free(NodeX);
            exit(1);
        }
    } while (1);
}

// Creating a node in Doubly Linked List
struct Node *getNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = data;
    newNode->prev = NULL; // Initialize previous address to NULL
    newNode->next = NULL; // Initialize next address to NULL
    return newNode;
}

// Insertion in Doubly Linked List
// Insert node at start
struct Node *insertAtBeginning(struct Node *start, int data)
{
    struct Node *newNode;
    // The list is empty
    if (start == NULL)
    {
        start = getNode(data);
        return start;
    }
    // The list is not empty
    newNode = getNode(data);
    newNode->next = start;
    start->prev = newNode;
    start = newNode;
    return start;
}

// Insert node at end
struct Node *insertAtEnd(struct Node *start, int data)
{
    struct Node *newNode, *current;
    // The list is empty
    if (start == NULL)
    {
        start = getNode(data);
        return start;
    }
    // The list is not empty
    newNode = getNode(data);
    current = start;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return start;
}

// Deletion in Doubly Linked List
// Delete start node
struct Node *deleteAtBeginning(struct Node *start)
{
    struct Node *temp;
    // The list is empty
    if (start == NULL)
    {
        printf("The list is empty.\n");
        return start;
    }
    // The list is not empty
    temp = start;
    start = start->next;
    start->prev = NULL;
    free(temp);
    return start;
}

// Delete end node
struct Node *deleteAtEnd(struct Node *start)
{
    struct Node *current, *temp;
    // The list is empty
    if (start == NULL)
    {
        printf("The list is empty.\n");
        return start;
    }
    // The list is not empty
    // If list has only one element
    if (start->next == NULL)
    {
        free(start);
        return NULL;
    }
    else
    {
        current = start;
        while (current->next != NULL)
        {
            current = current->next;
        }
        temp = current;
        current->prev->next = NULL;
        free(temp);
        return start;
    }
}

// Search for element
struct Node *searchNode(struct Node *start, int element)
{
    struct Node *current = start;
    // Traverse till end of linked list
    while (current != NULL)
    {
        if (current->value == element)
        {
            return current;
        }
        current = current->next;
    }
    return NULL; // If node not found
}

// Insertion, Deletion after or before Node X
// Insert node after Node X
struct Node *insertAfterNodeX(struct Node *start, struct Node *NodeX, int data)
{
    struct Node *current = start, *newNode, *temp;
    int found = 0; // To keep track of Node X
    while (current != NULL)
    {
        if (current == NodeX)
        {
            found = 1;
            break;
        }
        current = current->next;
    }
    // If NodeX not found in linked list
    if (!found)
    {
        printf("Node not found!\n");
        return start;
    }
    // If NodeX points to end node
    if (current->next == NULL)
    {
        start = insertAtEnd(start, data);
    }
    else
    {
        newNode = getNode(data);
        temp = current->next;
        current->next = newNode;
        newNode->prev = current;
        newNode->next = temp;
        temp->prev = newNode;
    }
    return start;
}

// Insert node before Node X
struct Node *insertBeforeNodeX(struct Node *start, struct Node *NodeX, int data)
{
    struct Node *current = start, *newNode, *temp;
    int found = 0; // To keep track of Node X
    while (current != NULL)
    {
        if (current == NodeX)
        {
            found = 1;
            break;
        }
        current = current->next;
    }
    // If NodeX is not found in linked list
    if (!found)
    {
        printf("Node not found!\n");
        return start;
    }
    // If NodeX points to starting node
    if (current->prev == NULL)
    {
        start = insertAtBeginning(start, data);
    }
    else
    {
        newNode = getNode(data);
        temp = current->prev;
        current->prev = newNode;
        newNode->next = current;
        newNode->prev = temp;
        temp->next = newNode;
    }
    return start;
}

// Delete node after Node X
struct Node *deleteAfterNodeX(struct Node *start, struct Node *NodeX)
{
    struct Node *current = start, *temp;
    int found = 0; // To keep track of Node X
    while (current != NULL)
    {
        if (current == NodeX)
        {
            found = 1;
            break;
        }
        current = current->next;
    }
    // If Node X is not found or no nodes are found after Node X
    if (!found || current->next == NULL)
    {
        printf("Node not found or no node to delete!\n");
        return start;
    }
    // If NodeX points to last before node
    if (current->next->next == NULL)
    {
        start = deleteAtEnd(start);
    }
    else
    {
        temp = current->next;
        current->next = current->next->next;
        current->next->prev = current;
        free(temp);
    }
    return start;
}

// Delete node before Node X
struct Node *deleteBeforeNodeX(struct Node *start, struct Node *NodeX)
{
    struct Node *current = start, *temp;
    int found = 0; // To keep track of Node X
    while (current != NULL)
    {
        if (current == NodeX)
        {
            found = 1;
            break;
        }
        current = current->next;
    }
    // If Node X is not found or no nodes are found before Node X
    if (!found || current->prev == NULL)
    {
        printf("Node not found or no node to delete!\n");
        return start;
    }
    // If Node X points to second node
    if (current->prev->prev == NULL)
    {
        start = deleteAtBeginning(start);
    }
    else
    {
        temp = current->prev;
        current->prev = current->prev->prev;
        current->prev->next = current;
        free(temp);
    }
    return start;
}

// Display Doubly Linked List
void displayLinkedList(struct Node *start)
{
    struct Node *current = start;
    printf("NULL -> ");
    while (current != NULL)
    {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}
