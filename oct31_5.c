// Quick Sort II
// Perform Quicksort on an array and a linked list

#include<stdio.h>
#include<stdlib.h>

// Structure for a node of a linked list
struct Node
{
    int data;
    struct Node* next;
};

// Utility function for creating a new node
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to print a linked list
void printList(struct Node* head)
{
    while (head != NULL) 
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to partition the linked list and return the 
// pivot node
struct Node* partition(struct Node* head, struct Node* end, 
                       struct Node** newHead, struct Node** newEnd)
{
    struct Node* pivot = end;
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* tail = pivot;
 
    // During partition, both the head and end of the list might change
    // which is updated in the newHead and newEnd variables
    while (curr != pivot)
    {
        if (curr->data < pivot->data)
        {
            // First node that has a value less than the pivot - becomes
            // the new head
            if ((*newHead) == NULL)
                (*newHead) = curr;
 
            prev = curr;  
            curr = curr->next;
        }
        else // If curr node is greater than pivot
        {
            // Move curr node to next of tail, and change tail
            if (prev)
                prev->next = curr->next;
            struct Node* tmp = curr->next;
            curr->next = NULL;
            tail->next = curr;
            tail = curr;
            curr = tmp;
        }
    }
 
    // If the pivot data is the smallest element in the current list,
    // pivot becomes the head
    if ((*newHead) == NULL)
        (*newHead) = pivot;
 
    // Update newEnd to the current last node
    (*newEnd) = tail;
 
    // Return the pivot node
    return pivot;
}
 
 
//here the quicksort algorithm for sorting the linked list is implemented
struct Node* quickSortRecur(struct Node* head, struct Node* end)
{
    // base condition
    if (!head || head == end)
        return head;
 
    Node* newHead = NULL, *newEnd = NULL;
 
    // Partition the list, newHead and newEnd will be updated
    // by the partition function
    struct Node* pivot = partition(head, end, &newHead, &newEnd);
 
    // If pivot is the smallest element - no need to recur for
    // the left part.
    if (newHead != pivot)
    {
        // Set the node before the pivot node as NULL
        struct Node* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
 
        // Recur for the list before pivot
        newHead = quickSortRecur(newHead, tmp);
 
        // Change next of last node of the left half to pivot
        tmp = getTail(newHead);
        tmp->next =  pivot;
    }
 
    // Recur for the list after the pivot element
    pivot->next = quickSortRecur(pivot->next, newEnd);
 
    return newHead;
}
 
 
// The main function for quick sort. This is a wrapper over recursive
// function quickSortRecur()
void quickSort(struct Node **headRef)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}

// Utility function for getting the last node of the linked list
struct Node* getTail(struct Node* cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

// Utility function for swapping two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
// Function to partition the array on the basis of pivot element
int partition_array(int arr[], int low, int high)
{
    // Select the pivot element
    int pivot = arr[high];
 
    // Index of smaller element
    int i = (low - 1); 
 
    // Traverse the array from low to high
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to sort an array using Quicksort algorithm
void quickSort_array(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now at right place */
        int pi = partition_array(arr, low, high);
 
        // Separately sort elements before partition and after partition
        quickSort_array(arr, low, pi - 1);
        quickSort_array(arr, pi + 1, high);
    }
}

// Test Driver code
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    quickSort_array(arr, 0, n-1);
    printf("Sorted array: \n");
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
    
    struct Node* head = newNode(7);
    head->next = newNode(2);
    head->next->next = newNode(1);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(3);
    
    printf("Linked list before sorting\n");
    printList(head);
 
    quickSort(&head);
 
    printf("Linked list after sorting\n");
    printList(head);
 
    return 0;
}

// Output
// Sorted array: 
// 5 6 7 11 12 13 
// Linked list before sorting
// 7 -> 2 -> 1 -> 4 -> 5 -> 3 -> NULL
// Linked list after sorting
// 1 -> 2 -> 3 -> 4 -> 5 -> 7 -> NULL