#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *insertNode(struct node *root, struct node *newNode)
{
    if (root == NULL)
        return newNode;
    if (newNode->data < root->data)
        root->left = insertNode(root->left, newNode);
    else
        root->right = insertNode(root->right, newNode);
    return root;
}

struct node *getNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void displayTree(struct node *root)
{
    if (root == NULL)
        return;
    displayTree(root->left);
    printf("%d ", root->data);
    displayTree(root->right);
}

struct node *findMinNode(struct node *node)
{
    while (node->left != NULL)
        node = node->left;
    return node;
}

struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    struct node *root = NULL;
    root = insertNode(root, getNode(50));
    insertNode(root, getNode(30));
    insertNode(root, getNode(20));
    insertNode(root, getNode(40));
    insertNode(root, getNode(70));
    insertNode(root, getNode(60));
    insertNode(root, getNode(80));

    printf("Binary Search Tree: ");
    displayTree(root);
    printf("\n");

    int keyToDelete = 30;
    root = deleteNode(root, keyToDelete);
    printf("After deleting %d: ", keyToDelete);
    displayTree(root);
    printf("\n");

    return 0;
}
