//file buildTree.c

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "buildTree.h"
#include "traversals.h"

void buildTree(FILE *tempFile);
void search(node_t *searchNode);

node_t *tempNode;
node_t *root;

void search(node_t *searchNode){

  int idCompare = strcmp(tempNode->nodeID, searchNode->nodeID);

  if (idCompare == 0){
    strcpy(searchNode->string, concat(searchNode->string, tempNode->string));
  } else if ((idCompare > 0) && (searchNode->right != NULL)){
    tempNode->level += 1;
    search(searchNode->right);
  } else if ((idCompare > 0) && (searchNode->right == NULL)){
    tempNode->level += 1;
    searchNode->right = tempNode;
  } else if ((idCompare < 0) && (searchNode->left != NULL)){
    tempNode->level += 1;
    search(searchNode->left);
  } else if ((idCompare < 0) && (searchNode->left == NULL)){
    tempNode->level += 1;
    searchNode->left = tempNode;
  }
}

// buildTree starts the building of the tree, it takes in the temporary file created at input (after validation)
void buildTree(FILE *tempFile){

  root = NULL;
  const int SIZE = 255;
  char inputLine[SIZE];

  // read tempfile input without spaces
  while (fscanf(tempFile, " %s[^ \t\n]", inputLine) == 1){
    tempNode = malloc(sizeof(node_t));
    tempNode->left = tempNode->right = NULL;
    sprintf(tempNode->nodeID, "%.1s",inputLine);
    strcpy(tempNode->string, inputLine);
    tempNode->level = 1;

    if(root == NULL) {
      root = tempNode;
    }
    else {
      search(root);
    }
  }
}

