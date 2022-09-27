// Pointers and Arrays
// Play around with pointers, malloc, realloc and free while building arrays (normal and dynamic)
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // Declare a normal array of integers with size 10
  int normal_array[10];

  // Fill the normal array with some values
  for (int i = 0; i < 10; i++) {
    normal_array[i] = i;
  }

  // Print the values in the normal array
  printf("Values in normal array:\n");
  for (int i = 0; i < 10; i++) {
    printf("%d ", normal_array[i]);
  }
  printf("\n");

  // Declare a pointer to an integer, and allocate memory for a dynamic array of integers with size 10 using malloc
  int *dynamic_array = malloc(10 * sizeof(int));
  if (dynamic_array == NULL) {
    // malloc failed, handle the error
    fprintf(stderr, "Error allocating memory for dynamic array\n");
    return 1;
  }

  // Fill the dynamic array with some values
  for (int i = 0; i < 10; i++) {
    dynamic_array[i] = i;
  }

  // Print the values in the dynamic array
  printf("Values in dynamic array:\n");
  for (int i = 0; i < 10; i++) {
    printf("%d ", dynamic_array[i]);
  }
  printf("\n");

  // Reallocate the dynamic array to have a size of 15 using realloc
  dynamic_array = realloc(dynamic_array, 15 * sizeof(int));
  if (dynamic_array == NULL) {
    // realloc failed, handle the error
    fprintf(stderr, "Error reallocating memory for dynamic array\n");
    return 1;
  }

  // Fill the extra elements in the reallocated dynamic array with some values
  for (int i = 10; i < 15; i++) {
    dynamic_array[i] = i;
  }

  // Print the values in the reallocated dynamic array
  printf("Values in reallocated dynamic array:\n");
  for (int i = 0; i < 15; i++) {
    printf("%d ", dynamic_array[i]);
  }
  printf("\n");

  // Free the memory allocated for the dynamic array using free
  free(dynamic_array);

  return 0;
}
