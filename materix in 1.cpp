#include <stdio.h>
void insertElement(int arr[], int n, int element, int pos) {
  if (pos > n) {
    printf("Invalid position!\n");
    return;
  }

  for (int i = n - 1; i >= pos; i--) {
    arr[i + 1] = arr[i];
  }

  arr[pos] = element;
  n++;
}

void deleteElement(int arr[], int n, int pos) {
  if (pos > n - 1) {
    printf("Invalid position!\n");
    return;
  }

  for (int i = pos; i < n - 1; i++) {
    arr[i] = arr[i + 1];
  }

  n--;
}

void displayArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[100];
  int n, element, pos;

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("Enter element %d: ", i + 1);
    scanf("%d", &arr[i]);
  }

  printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");

  while (1) {
    printf("Enter your choice: ");
    scanf("%d", &ch);

    switch (ch) {
      case 1:
        printf("Enter the element to insert: ");
        scanf("%d", &element);
        printf("Enter the position to insert: ");
        scanf("%d", &pos);
        insertElement(arr, n, element, pos);
        break;
      case 2:
        printf("Enter the position to delete: ");
        scanf("%d", &pos);
        deleteElement(arr, n, pos);
        break;
      case 3:
        displayArray(arr, n);
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid choice!\n");
    }
  }

  return 0;
}
