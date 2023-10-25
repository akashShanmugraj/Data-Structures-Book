#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int fillTree(int *arr, int length) {
    int i = 0;
    while (i < length) {
        printf("Enter the value of node %d: ", i);
        scanf("%d", &arr[i]);
        i++;
    }
    return 0;
}

void displayTree(int *arr, int length) {
    int levels = log2(length);
    int i = 0;
    while (i < length) {
        printf("%d ", arr[i]);
        i++;
    }
}

void addNode(int *arr, int length, int value) {
    for (int i = 0; i < length; i++) {
        if (arr[i] == -1) {
            arr[i] = value;
            return;
        }
    }
    printf("The tree is already full. Cannot add more nodes.\n");
}

void deleteNode(int *arr, int length, int value) {
    // Find the node with the specified value
    for (int i = 0; i < length; i++) {
        if (arr[i] == value) {
            arr[i] = -1;
            return;
        }
    }
    printf("Node with value %d not found in the tree.\n", value);
}

int main() {
    int length, levels;
    printf("Enter the number of levels of the tree: ");
    scanf("%d", &levels);
    length = pow(2, levels);
    int *tree = (int *)malloc(length * sizeof(int));

    for (int i = 0; i < length; i++) {
        tree[i] = -1;
    }

    // Entering values in the tree
    fillTree(tree, length);

    // Displaying the tree
    displayTree(tree, length);

    // addNode and deleteNode functions
    addNode(tree, length, 42); 
    deleteNode(tree, length, 20); 

    // Display the tree after adding and deleting nodes
    displayTree(tree, length);

    free(tree); 
}
