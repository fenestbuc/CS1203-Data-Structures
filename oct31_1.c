// Selection Sort I
// "Given an array (assume int), 
// sort the array using Selection Sort"
#include <stdio.h>

void selection_sort(int *arr, int n) {
  int i, j, min, temp;
  for (i = 0; i < n - 1; i++) {
    min = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }
}

int main() {
  int arr[] = {5, 3, 2, 8, 1, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  selection_sort(arr, n);

  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
