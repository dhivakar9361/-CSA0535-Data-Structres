#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char items[MAX_SIZE];
};

void initialize(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return (s->top == -1);
}

int isFull(struct Stack *s) {
    return (s->top == MAX_SIZE - 1);
}

void push(struct Stack *s, char c) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->items[++(s->top)] = c;
}

char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    struct Stack s;
    initialize(&s);
    int i = 0, j = 0;
    
    while (infix[i] != '\0') {
        if (infix[i] >= 'a' && infix[i] <= 'z') {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(&s, '(');
        } else if (infix[i] == ')') {
            while (!isEmpty(&s) && s.items[s.top] != '(') {
                postfix[j++] = pop(&s);
            }
            if (!isEmpty(&s) && s.items[s.top] == '(') {
                pop(&s); // Remove '(' from stack
            }
        } else if (isOperator(infix[i])) {
            while (!isEmpty(&s) && precedence(infix[i]) <= precedence(s.items[s.top])) {
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i]);
        }
        i++;
    }
    
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter an infix expression: ");
    gets(infix);
    
    infixToPostfix(infix, postfix);
    
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}
