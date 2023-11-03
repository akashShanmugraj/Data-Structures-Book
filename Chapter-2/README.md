# Chapter 2, Linear Data Structures

## Linked List

### Creation Function
```c
struct Node *getNode(int num)
{
    struct Node *node = malloc(sizeof(struct Node));
    node->data = num;
    node->next = NULL;
    return node;
}
```

### Search Function
```c
char *searchNode(struct Node *x, int val)
{
    if (x == NULL)
        return "Not Found\n";
    if (x->data == val)
        return "Found\n";
    searchNode(x->next, val);
}
```

## Insertion
### Insertion after some element (X)
```c
struct Node *insertAfterNodeX(struct Node *start, struct Node *new, int x)
{
    if (new == NULL)
        return start;
    else if (start == NULL)
        return new;

    struct Node *newIterator = new, *lastOfNew = new, *orginalIterator = start;

    for (; newIterator; newIterator = newIterator->next)
        lastOfNew = newIterator;
    // new points to 1st node of new linked list and lastOfNew points to the last node of the new linked list

    for (int i = 1; i <= x; i++, orginalIterator = orginalIterator->next)
    {
        if (orginalIterator == NULL)
            return start;
        if (i == x)
        {
            // originalIterator points to node x now
            // the end of the new linkde list is joines with the begining of the 2nd part of the original one
            lastOfNew->next = orginalIterator->next;
            // the begining of the new one is joined with the end of the 1st part of the original
            orginalIterator->next = new;
            return start;
        }
    }
}
```

### Insert Before an Element (X)
```c
struct Node *insertBeforeNodeX(struct Node *start, struct Node *new, int x)
{
    if (new == NULL)
        return start;
    else if (start == NULL)
        return new;

    struct Node *newIterator = new, *lastOfNew = new, *orginalIterator = start;

    for (; newIterator; newIterator = newIterator->next)
        lastOfNew = newIterator;
    // new points to 1st node of new linked list and lastOfNew points to the last node of the new linked list

    for (int i = 1; i <= x + 1; i++, orginalIterator = orginalIterator->next)
    {
        if (orginalIterator == NULL)
            return start;
        if (x == 1)
        {
            lastOfNew->next = start;
            start = new;
            return start;
        }
        if (i == x - 1)
        {
            // originalIterator points to node x now
            // the end of the new linkde list is joines with the begining of the 2nd part of the original one
            lastOfNew->next = orginalIterator->next;
            // the begining of the new one is joined with the end of the 1st part of the original
            orginalIterator->next = new;
            return start;
        }
    }
}
```

## Deletion
### Delete First element
```c
struct Node *deleteFirstNode(struct Node *start)
{
    if (start == NULL)
        return NULL;
    else
    {
        struct Node *tmp = start;
        start = start->next;
        free(tmp);
        return start;
    }
}
```

### Delete Last node
```c
struct Node *deleteLastNode(struct Node *start)
{
    if (start == NULL)
        return NULL;
    if (start->next == NULL)
    {
        free(start);
        return NULL;
    }
    else
    {
        struct Node *tmp = start;
        while (tmp)
        {
            if (tmp->next->next == NULL)
            {
                free(tmp->next);
                tmp->next = NULL;
                return start;
            }
            tmp = tmp->next;
        }
    }
}

### Delete Elements after a node (X)
```c
struct Node *deleteNodeAfterX(struct Node *start, int x)
{
    struct Node *iterator = start;
    for (int i = 1; i <= x; i++, iterator = iterator->next)
    {
        if (iterator == NULL)
            return start;
        if (i == x)
        {
            struct Node *tmp = iterator->next;
            iterator->next = iterator->next->next;
            free(tmp);
            return start;
        }
    }
}
```
### Delete Elements before a node (X)
```c
struct Node *deleteNodeBeforeX(struct Node *start, int x)
{
    struct Node *iterator = start;
    for (int i = 1; i <= x + 1; i++, iterator = iterator->next)
    {
        if (iterator == NULL || x == 1)
            return start;
        if (x == 2)
        {
            struct Node *tmp = start;
            start = start->next;
            free(tmp);
            return start;
        }
        if (i == x - 2)
        {
            struct Node *tmp = iterator->next;
            iterator->next = iterator->next->next;
            free(tmp);
            return start;
        }
    }
}
```
