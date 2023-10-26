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
    newNode->next = newNode; // Link next node to original node
    newNode->prev = newNode; // Link previous node to original node
    return newNode;
}

// Insert node at start of the linked list
struct Node *insertAtBeginning(struct Node *start, int data)
{
    struct Node *newNode = getNode(data), *current = start;
    // The list is empty
    if (start == NULL)
    {
        return newNode;
    }
    // The list is not empty
    // Link for previous node
    current->prev = newNode;
    newNode->next = current;
    // Link for last node
    while (current->next != start)
        current = current->next;
    current->next = newNode;
    newNode->prev = current;
    start = newNode; // Make start point to newNode
    return start;
}

// Insert node at end of the linked list
struct Node *insertAtEnd(struct Node *start, int data)
{
    struct Node *newNode = getNode(data), *current = start;
    // The list is empty
    if (start == NULL)
    {
        return newNode;
    }
    // The list is not empty
    // Link for previous node
    current->prev = newNode;
    newNode->next = current;
    // Link for last node
    while (current->next != start)
        current = current->next;
    current->next = newNode;
    newNode->prev = current;
    return start;
}

// Delete start node of the linked list
struct Node *deleteAtBeginning(struct Node *start)
{
    struct Node *temp;
    // The list is empty
    if (start == NULL)
    {
        printf("The list is empty!\n");
        return start;
    }
    // The list is not empty
    // If the list has only one element
    if (start->next == start)
    {
        free(start);
        return NULL;
    }
    else
    {
        temp = start;
        start = start->next;
        start->prev = temp->prev;
        temp->prev->next = start;
        free(temp);
        return start;
    }
}

// Delete end node of the linked list
struct Node *deleteAtEnd(struct Node *start)
{
    struct Node *temp;
    // The list is empty
    if (start == NULL)
    {
        printf("The list is empty!\n");
        return start;
    }
    // The list is not empty
    // If the list has only one element
    if (start->next == start)
    {
        free(start);
        return NULL;
    }
    else
    {
        temp = start->prev;
        start->prev = temp->prev;
        temp->prev->next = start;
        free(temp);
        return start;
    }
}

// Search for element in the linked list
struct Node *searchNode(struct Node *start, int element)
{
    struct Node *current = start;
    // If element is found at first node of the linked list
    if (current->value == element)
        return current;
    // Else traverse till current->next equals start node
    current = current->next;
    while (current != start)
    {
        // If element is found
        if (current->value == element)
        {
            return current;
        }
        current = current->next;
    }
    return NULL; // If element is not found, return NULL pointer
}

// Insert node after Node X in the linked list
struct Node *insertAfterNodeX(struct Node *start, struct Node *NodeX, int data)
{
    struct Node *current = start, *newNode;
    int found = 0; // To keep track of Node X
    // If Node X is found at first node of linked list
    if (current == NodeX)
        found = 1;
    else
    {
        // Else traverse till current->next equals start node
        current = current->next;
        while (current != start)
        {
            // If Node X is found
            if (current == NodeX)
            {
                found = 1;
                break;
            }
            current = current->next;
        }
    }
    // If Node X is not found
    if (!found)
    {
        printf("Node not found!\n");
        return start;
    }

    newNode = getNode(data);
    newNode->next = current->next;
    current->next->prev = newNode;
    current->next = newNode;
    newNode->prev = current;
    return start;
}

// Insert node before Node X in the linked list
struct Node *insertBeforeNodeX(struct Node *start, struct Node *NodeX, int data)
{
    struct Node *current = start, *newNode, *beforeNode;
    int found = 0; // To keep track of Node X
    // If Node X is found at first node of linked list
    if (current == NodeX)
        found = 1;
    else
    {
        // Else traverse till current->next equals start node
        current = current->next;
        while (current != start)
        {
            // If Node X is found
            if (current == NodeX)
            {
                found = 1;
                break;
            }
            current = current->next;
        }
    }
    // If Node X is not found
    if (!found)
    {
        printf("Node not found!\n");
        return start;
    }

    newNode = getNode(data);
    beforeNode = current->prev; // To store the Node X's previous node's address
    beforeNode->next = newNode;
    newNode->prev = beforeNode;
    newNode->next = current;
    current->prev = newNode;
    return start;
}

// Delete node after Node X in the linked list
struct Node *deleteAfterNodeX(struct Node *start, struct Node *NodeX)
{
    struct Node *current = start, *temp;
    int found = 0; // To keep track of Node X
    // If Node X is found at first node of linked list
    if (current == NodeX)
        found = 1;
    else
    {
        // Else traverse till current->next equals start node
        current = current->next;
        while (current != start)
        {
            // If Node X is found
            if (current == NodeX)
            {
                found = 1;
                break;
            }
            current = current->next;
        }
    }
    // If Node X is not found
    if (!found)
    {
        printf("Node not found!\n");
        return start;
    }

    // If Node X is found at end
    if (current->next == start)
    {
        temp = current->next;
        current->next = start->next;
        start->next->prev = current;
        start = current;
        free(temp);
    }
    else
    {
        temp = current->next;
        current->next = temp->next;
        temp->next->prev = current;
        free(temp);
    }
    return start;
}

// Delete node before Node X in the linked list
struct Node *deleteBeforeNodeX(struct Node *start, struct Node *NodeX)
{
    struct Node *current = start, *temp;
    int found = 0; // To keep track of Node X
    // If Node X is found at first node of linked list
    if (current == NodeX)
        found = 1;
    else
    {
        // Else traverse till current->next equals start node
        current = current->next;
        while (current != start)
        {
            // If Node X is found
            if (current == NodeX)
            {
                found = 1;
                break;
            }
            current = current->next;
        }
    }
    // If Node X is not found
    if (!found)
    {
        printf("Node not found!\n");
        return start;
    }

    // If Node X is found at second node of the linked list
    if (current->prev == start)
    {
        temp = current->prev;
        current->prev = start->prev;
        start->prev->next = current;
        start = current;
        free(temp);
    }
    else
    {
        temp = current->prev;
        current->prev = temp->prev;
        temp->prev->next = current;
        free(temp);
    }
    return start;
}

// Display Doubly Linked List
void displayLinkedList(struct Node *start)
{
    struct Node *current = start;
    /// If linked list has no nodes or list is empty
    if (current == NULL)
    {
        printf("NULL");
        return;
    }
    printf("Start -> ");
    // If linked list has single node
    if (current->next == start)
    {
        printf("%d -> Start\n", current->value);
        return;
    }
    else
    {
        printf("%d -> ", current->value);
        current = current->next;
        // Traverse till current->next equals start
        while (current != start)
        {
            printf("%d -> ", current->value);
            current = current->next;
        }
        printf("Start\n");
    }
}
