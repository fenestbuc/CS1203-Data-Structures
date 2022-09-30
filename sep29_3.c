// Chunk Reverse a Linked List
// "Given head pointer of a linked list, and an integer k (1<=k<=n), reverse every k elements of the list"
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* reverseKGroup(struct Node* head, int k) {
    // Create a dummy head node to make the code simpler
    struct Node* dummy = malloc(sizeof(struct Node));
    dummy->next = head;

    // Initialize the pointers
    struct Node* prev = dummy;
    struct Node* current = head;

    int i;
    while (current != NULL) {
        // Reverse the next k elements
        for (i = 0; i < k && current != NULL; i++) {
            struct Node* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        // Connect the reversed portion to the rest of the list
        head->next = current;
        head = prev;
    }

    return dummy->next;
}

int main() {
    // Create a linked list
    struct Node* head = malloc(sizeof(struct Node));
    head->data = 1;
    head->next = malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = malloc(sizeof(struct Node));
    head->next->next->data = 3;
    head->next->next->next = malloc(sizeof(struct Node));
    head->next->next->next->data = 4;
    head->next->next->next->next = malloc(sizeof(struct Node));
    head->next->next->next->next->data = 5;
    head->next->next->next->next->next = NULL;

    // Reverse every 2 elements of the linked list
    head = reverseKGroup(head, 2);

    // Print the reversed linked list
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}
