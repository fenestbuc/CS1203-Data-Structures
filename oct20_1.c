// Binary Tree
// "Given an array (assume int), construct a Binary Search Tree from it."
#include <stdio.h>
#include <stdlib.h>

/* Define the structure of a node in the binary search tree */
typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node_t;

/* Create a new node with the given data */
node_t* create_node(int data) {
  node_t *new_node = (node_t*)malloc(sizeof(node_t));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

/* Insert a new node with the given data into the binary search tree */
void insert(node_t **root, int data) {
  if (*root == NULL) {
    *root = create_node(data);
  } else {
    if (data < (*root)->data) {
      insert(&(*root)->left, data);
    } else {
      insert(&(*root)->right, data);
    }
  }
}

/* Construct a binary search tree from the given integer array */
node_t* construct_bst(int *arr, int n) {
  node_t *root = NULL;
  for (int i = 0; i < n; i++) {
    insert(&root, arr[i]);
  }
  return root;
}

int main() {
  int arr[] = {4, 2, 1, 3, 6, 5, 7};
  int n = sizeof(arr) / sizeof(arr[0]);
  node_t *root = construct_bst(arr, n);
  return 0;
}
