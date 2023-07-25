#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initialize(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
bool isEmpty(Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the queue is full
bool isFull(Queue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Function to push (enqueue) an element into the queue
bool push(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue overflow!\n");
        return false;
    } else if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }
    queue->items[queue->rear] = value;
    return true;
}

// Function to pop (dequeue) an element from the queue
bool pop(Queue* queue, int* value) {
    if (isEmpty(queue)) {
        printf("Queue underflow!\n");
        return false;
    } else if (queue->front == queue->rear) {
        *value = queue->items[queue->front];
        queue->front = queue->rear = -1;
    } else {
        *value = queue->items[queue->front];
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return true;
}

int main() {
    Queue myQueue;
    initialize(&myQueue);

    push(&myQueue, 10);
    push(&myQueue, 20);
    push(&myQueue, 30);

    int dequeuedValue;
    if (pop(&myQueue, &dequeuedValue)) {
        printf("Dequeued value: %d\n", dequeuedValue);
    }

    if (pop(&myQueue, &dequeuedValue)) {
        printf("Dequeued value: %d\n", dequeuedValue);
    }

    if (pop(&myQueue, &dequeuedValue)) {
        printf("Dequeued value: %d\n", dequeuedValue);
    }

    // Try dequeuing from an empty queue
    if (pop(&myQueue, &dequeuedValue)) {
        printf("Dequeued value: %d\n", dequeuedValue);
    }

    return 0;
}
