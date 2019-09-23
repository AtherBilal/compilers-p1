//file traversals.c

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "buildTree.h"
#include "traversals.h"

void printGivenLevel(struct node *root,int level, FILE *outputFile);
int height(struct node *root);
char *concat(const char *string1, const char *string2);
void traversePreOrder(node_t *root, char *outputBase);
void traverseInOrder(node_t *root, char *outputBase);
void traverseLevelOrder(node_t *root, char *outputBase);
void printInorder(node_t *n, FILE *outputFile);
void printPreorder(node_t *n, FILE *outputFile);
void printLevelOrder(struct node *root, FILE *outputFile);

node_t *temp;
node_t *root;

// takes in 2 strings and concatenates them
char *concat(const char *string1, const char *string2){
  char *newString = malloc(snprintf(NULL, 0, "%s %s", string2, string1) + 1);
  sprintf(newString, "%s %s", string2, string1);
  return newString;
}

// function used to print the tree using preorder traversals
void printPreorder(node_t *node, FILE *outputFile){
  if (root == NULL){
    return;
  }
  fprintf(outputFile,"%*c%d:%s \n", node->level*2,' ',node->level, concat(node->string, node->nodeID));
  if (node->left != NULL){
    printPreorder(node->left, outputFile);
  }
  if (node->right != NULL) {
    printPreorder(node->right, outputFile);
  }
}

// function used to print the tree using inorder traversals
void printInorder(node_t *node, FILE *outputFile){
  if (root == NULL){
    return;
  }
  if (node->left != NULL)
    printInorder(node->left, outputFile);
    fprintf(outputFile,"%*c%d:%s \n", node->level*2,' ',node->level, concat(node->string, node->nodeID));
  if (node->right != NULL)
    printInorder(node->right, outputFile);
}

// function used to print the tree using levelorder traversals
void printLevelOrder(struct node *root, FILE *outputFile) {
   int h,i;
   h = height(root);
   for ( i = 1; i <= h; i++) {
    printGivenLevel(root, i, outputFile);
   }
}

// prints the level passed in. 
void printGivenLevel(struct node *root,int level, FILE *outputFile) {
   if(root == NULL) {
       return;
   }
   if(level == 1) {
      fprintf(outputFile,"%*c%d:%s \n", root->level*2,' ',root->level, concat(root->string, root->nodeID));
   }
   else if(level > 1) {
      printGivenLevel(root->left, level - 1, outputFile);
      printGivenLevel(root->right, level - 1, outputFile);
   }
}

// finds the height of the binary tree, this is a helper function used for level order or BFS
int height(struct node *root){

   int rightHeight;
   int leftHeight;
   if(root == NULL) {
    return 0;
   }
   leftHeight = height(root->left);
   rightHeight = height(root->right);
   if (leftHeight > rightHeight) {
    return leftHeight + 1;
   } else {
    return rightHeight + 1;
   }
}

// Creates the .preorder file and initiates the traversal and printing process
void traversePreOrder(node_t *root, char *outputBase){
  FILE *outputFile;
  char *outExtension = ".preorder";
  char *outputFileName = malloc(snprintf(NULL, 0, "%s%s", outputBase, outExtension) + 1);
  sprintf(outputFileName, "%s%s", outputBase, outExtension);
  outputFile = fopen(outputFileName, "w");
  if(outputFile == NULL){
    fprintf(stderr, "Error opening file for output %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }
  printPreorder(root, outputFile);
  fclose(outputFile);
}

// Creates the .inorder file and initiates the traversal and printing process
void traverseInOrder(node_t *root, char *outputBase){
  FILE *outputFile;
  char *outExtension = ".inorder";
  char *outputFileName = malloc(snprintf(NULL, 0, "%s%s", outputBase, outExtension) + 1);
  sprintf(outputFileName, "%s%s", outputBase, outExtension);
  outputFile = fopen(outputFileName, "w");
  if(outputFile == NULL){
    fprintf(stderr, "Error opening file for output %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }
  printInorder(root, outputFile);
  fclose(outputFile);
}

// Creates the .levelorder file and initiates the traversal and printing process
void traverseLevelOrder(node_t *root, char *outputBase){
  FILE *outputFile;
  char *outExtension = ".levelorder";
  char *outputFileName = malloc(snprintf(NULL, 0, "%s%s", outputBase, outExtension) + 1);
  sprintf(outputFileName, "%s%s", outputBase, outExtension);
  outputFile = fopen(outputFileName, "w");
  if(outputFile == NULL){
    fprintf(stderr, "Error opening file for output %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }
  printLevelOrder(root, outputFile);
  fclose(outputFile);
}