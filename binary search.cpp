#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void init(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    stack->data[++stack->top] = value;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    return stack->data[stack->top--];
}

int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1;
    }
    return stack->data[stack->top];
}

int main() {
    Stack stack;
    init(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Peek: %d\n", peek(&stack));  // Should print 30

    printf("Pop: %d\n", pop(&stack));    // Should print 30
    printf("Pop: %d\n", pop(&stack));    // Should print 20

    push(&stack, 40);

    printf("Peek: %d\n", peek(&stack));  // Should print 40

    return 0;
}
