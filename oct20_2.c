// Binary Tree Delete Operation
// Professor has covered the insert and build operations, how do you go about deleting nodes?
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node* createNode(int data) {
  struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

struct Node* insert(struct Node* root, int data) {
  if (root == NULL) {
    return createNode(data);
  } else if (data < root->data) {
    root->left = insert(root->left, data);
  } else if (data > root->data) {
    root->right = insert(root->right, data);
  }
  return root;
}

struct Node* findMinNode(struct Node* root) {
  while (root->left != NULL) {
    root = root->left;
  }
  return root;
}

struct Node* deleteNode(struct Node* root, int data) {
  if (root == NULL) {
    return root;
  } else if (data < root->data) {
    root->left = deleteNode(root->left, data);
  } else if (data > root->data) {
    root->right = deleteNode(root->right, data);
  } else {
    // Case 1: No children
    if (root->left == NULL && root->right == NULL) {
      free(root);
      root = NULL;
    }
    // Case 2: One child
    else if (root->left == NULL) {
      struct Node *temp = root;
      root = root->right;
      free(temp);
    } else if (root->right == NULL) {
      struct Node *temp = root;
      root = root->left;
      free(temp);
    }
    // Case 3: Two children
    else {
      struct Node *temp = findMinNode(root->right);
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
    }
  }
  return root;
}

void inorder(struct Node* root) {
  if (root == NULL) {
    return;
  }
  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

int main() {
  struct Node* root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);

  printf("Inorder traversal before deletion: ");
  inorder(root);
  printf("\n");

  int data = 7;
  root = deleteNode(root, data);

  printf("Inorder traversal after deletion of %d: ", data);
  inorder(root);
  printf("\n");