#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *createNode(int data) {
  struct node newNode = (struct node) malloc(sizeof(struct node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

void preorder(struct node *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(struct node *root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
  }
}

int main() {
 struct node *root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->left = createNode(4);
  root->left->right = createNode(5);
  printf("Inorder traversal of the tree is: ");
  inorder(root);
  printf("\n");
  printf("Preorder traversal of the tree is: ");
  preorder(root);
  printf("\n");
  printf("Postorder traversal of the tree is: ");
  postorder(root);
  printf("\n");
  return 0;
}
