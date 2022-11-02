// Selection Sort II
// "Given head pointer of a linked list, 
// sort the list using Selection Sort"
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

// Function to create a new node with given data
struct Node *newNode(int data) {
  // Allocate memory for new node
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

  // Put in the data
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Function to insert a new node at the beginning of the linked list
void push(struct Node **head_ref, int data) {
  // Allocate memory for new node
  struct Node *new_node = newNode(data);

  // Make the next of new node as head
  new_node->next = (*head_ref);

  // Move the head to point to the new node
  (*head_ref) = new_node;
}

// Function to print the linked list
void printList(struct Node *node) {
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

// Selection sort for linked list
void selectionSort(struct Node **head_ref) {
  // Initialize current node
  struct Node *current = (*head_ref);
  struct Node *min_node;
  int temp;

  while (current->next != NULL) {
    // Find the minimum element in the unsorted list
    min_node = current;
    while (min_node->next != NULL) {
      if (min_node->next->data < min_node->data) {
        min_node = min_node->next;
      }
    }
    // Swap the minimum element with the first element of the unsorted list
    temp = current->data;
    current->data = min_node->data;
    min_node->data = temp;

    // Move to the next node
    current = current->next;
  }
}

// Driver program to test above functions
int main() {
  // Start with an empty list
  struct Node *head = NULL;

  // Insert elements in sorted order
  push(&head, 5);
  push(&head, 3);
  push(&head, 1);
  push(&head, 2);
  push(&head, 4);

  printf("Original linked list: ");
  printList(head);

  selectionSort(&head);

  printf("Sorted linked list: ");
  printList(head);

  return 0;
}
