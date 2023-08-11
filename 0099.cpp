#include <stdio.h>
#include <stdlib.h>

struct stack {
  char data;
  struct stack *next;
};

struct stack *top = NULL;

void push(char data) {
  struct stack *new_node = (struct stack *)malloc(sizeof(struct stack));
  new_node->data = data;
  new_node->next = top;
  top = new_node;
}

char pop() {
  if (top == NULL) {
    return '\0';
  }

  char data = top->data;
  top = top->next;
  return data;
}

int is_empty() {
  return top == NULL;
}

void print_notations(char *expression) {
  for (int i = 0; expression[i] != '\0'; i++) {
    if (expression[i] == '(') {
      push(expression[i]);
    } else if (expression[i] == ')') {
      while (top != NULL && top->data != '(') {
        char c = pop();
        printf("%c ", c);
      }

      if (top == NULL) {
        printf("Invalid expression\n");
        return;
      }

      pop();
    } else {
      printf("%c ", expression[i]);
    }
  }

  while (!is_empty()) {
    char c = pop();
    printf("%c ", c);
  }

  printf("\n");
}

int main() {
  char expression[] = "(a+b)*(c-d)";
  print_notations(expression);

  return 0;
}
