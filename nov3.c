// Heaps and Heapsort!
// Given an array, build a heap and sort it!

#include<stdio.h> 

/* Function for building the heap from given array */
void buildHeap(int arr[], int n) 
{ 
    // Index of last non-leaf node 
    int startIdx = (n / 2) - 1; 
  
    // Perform reverse level order traversal 
    // from last non-leaf node and heapify 
    // each node 
    for (int i = startIdx; i >= 0; i--) { 
        heapify(arr, n, i); 
    } 
} 

/* Function to heapify the node at given index */
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) { 
        swap(&arr[i], &arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 

/* Function to swap two numbers in an array */ 
void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 

/* Function for selection sort on heap */ 
void selectionSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    buildHeap(arr, n); 
  
    // One by one extract an element from heap 
    for (int i = n - 1; i >= 0; i--) { 
        // Move current root to end 
        swap(&arr[0], &arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    selectionSort(arr, n); 
  
    printf("Sorted array is \n"); 
    printArray(arr, n); 
}