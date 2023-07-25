#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initialize(Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
bool isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
bool push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return false;
    } else {
        stack->items[++stack->top] = value;
        return true;
    }
}

// Function to pop an element from the stack
bool pop(Stack* stack, int* value) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return false;
    } else {
        *value = stack->items[stack->top--];
        return true;
    }
}

int main() {
    Stack myStack;
    initialize(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    int poppedValue;
    if (pop(&myStack, &poppedValue)) {
        printf("Popped value: %d\n", poppedValue);
    }

    if (pop(&myStack, &poppedValue)) {
        printf("Popped value: %d\n", poppedValue);
    }

    if (pop(&myStack, &poppedValue)) {
        printf("Popped value: %d\n", poppedValue);
    }

    // Try popping from an empty stack
    if (pop(&myStack, &poppedValue)) {
        printf("Popped value: %d\n", poppedValue);
    }

    return 0;
}
