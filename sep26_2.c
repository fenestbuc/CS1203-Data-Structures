// Implement Linked List
// "Given a set of values (assume int),
// create a linked list from them"
#include <stdio.h>
#include <stdlib.h>

// Define a node in the linked list
struct node {
  int data; // The data stored in the node
  struct node* next; // Pointer to the next node in the list
};

// Function to create a new node and return a pointer to it
struct node* create_node(int data) {
  struct node* new_node = malloc(sizeof(struct node)); // Allocate memory for the new node
  new_node->data = data; // Store the data in the node
  new_node->next = NULL; // Set the next pointer to NULL, since this will be the last node in the list for now
  return new_node; // Return a pointer to the new node
}

// Function to create a linked list from a given set of integer values
struct node* create_linked_list(int* values, int num_values) {
  struct node* head = NULL; // Head of the linked list
  struct node* tail = NULL; // Tail of the linked list
  int i;

  // Iterate through the array of values
  for (i = 0; i < num_values; i++) {
    // Create a new node for the current value
    struct node* new_node = create_node(values[i]);

    // If this is the first node in the list, set it as the head
    if (head == NULL) {
      head = new_node;
    }

    // Otherwise, add the new node to the end of the list
    else {
      tail->next = new_node;
    }

    // Set the new node as the tail of the list
    tail = new_node;
  }

  // Return a pointer to the head of the linked list
  return head;
}

int main() {
  int values[] = {1, 2, 3, 4, 5}; // Array of integer values to use as the data for the linked list
  int num_values = 5; // Number of values in the array

  // Create the linked list
  struct node* head = create_linked_list(values, num_values);

  // Print the linked list
  printf("Linked list: ");
  struct node* current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");

  return 0;
}
