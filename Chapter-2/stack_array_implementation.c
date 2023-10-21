// Program to implement stack using array in C.
#include<stdio.h>
#include<stdlib.h>


// Structure for stack.
struct Stack{
    int top;
    int *array;
    int size;
};


// Function to create a new stack with specified size.
struct Stack create_stack(int size){
    struct Stack new_stack;
    new_stack.array  = (int*)malloc(sizeof(int) * size);
    new_stack.top = -1;
    new_stack.size = size;

    return new_stack;
}

// Function to push an element into the stack.
void push(struct Stack *stack, int element){

    // Check for stackoverflow.
    if(is_full(stack)){
        printf("Stackoverflow..\n");
    }
    else{
        stack->top++;
        stack->array[stack->top] = element;
    }

}

// Function to pop an element from the stack.
int pop(struct Stack *stack){

    // Check for underflow.
    if(is_empty(stack)){
        printf("Stackunderflow.\n");
    }
    else{
        return stack->array[stack->top--];
    }
}

// Function to get the peek element from the stack.
int peek(struct Stack *stack){
    
    if(is_empty(stack)){
        printf("Stack has no elements to peek.\n");
    }
    else{
        return stack->array[stack->top];
    }
}

// Function to check if the stack is full.
int is_full(struct Stack *stack){
    if(stack->top == stack->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}

// Function to check if the stack is empty.
int is_empty(struct Stack *stack){
    if(stack->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}


int main(void){

    struct Stack new_stack = create_stack(10);

    push(&new_stack, 10);
    push(&new_stack, 20);
    push(&new_stack, 30);
    push(&new_stack, 40);

    printf("Peek element : %d\n", peek(&new_stack));
    pop(&new_stack);
    printf("Peek element : %d\n", peek(&new_stack));
    printf("Popped element : %d\n", pop(&new_stack));
    printf("Peek element : %d\n", peek(&new_stack));

    pop(&new_stack);
    pop(&new_stack);

    // Below will throw stackunderflow.
    pop(&new_stack);
    
    printf("Is the stack full : %d\n", is_full(&new_stack));
    printf("Is the stack empty : %d\n", is_empty(&new_stack));

}
