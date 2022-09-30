// Half a Linked List
// Develop an algorithm that prints the first half of a given linked list without knowing how many elements in the array? 
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printFirstHalf(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Print the first half of the list
    while (head != slow) {
        printf("%d ", head->data);
        head = head->next;
    }
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
    head->next->next->next->next = NULL;

    printFirstHalf(head);

    return 0;
}
