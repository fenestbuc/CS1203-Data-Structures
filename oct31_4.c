// Insertion Sort II
// Same as above using Insertion Sort
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

void insert_sorted(struct Node** head, struct Node* new_node) {
  struct Node* current = *head;

  if (*head == NULL || (*head)->data >= new_node->data) {
    new_node->next = *head;
    *head = new_node;
  } else {
    while (current->next != NULL && current->next->data < new_node->data) {
      current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
  }
}

void insertion_sort(struct Node** head) {
  struct Node* sorted = NULL;
  struct Node* current = *head;
  struct Node* next;

  while (current != NULL) {
    next = current->next;
    insert_sorted(&sorted, current);
    current = next;
  }

  *head = sorted;
}

int main() {
  // create and populate the linked list
  struct Node* head = NULL;
  insert_sorted(&head, (struct Node*)malloc(sizeof(struct Node)));
  head->data = 5;
  head->next = NULL;
  insert_sorted(&head, (struct Node*)malloc(sizeof(struct Node)));
  head->data = 3;
  head->next = NULL;
  insert_sorted(&head, (struct Node*)malloc(sizeof(struct Node)));
  head->data = 1;
  head->next = NULL;

  // sort the linked list
  insertion_sort(&head);

  // print the sorted linked list
  struct Node* current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");

  return 0;
}
