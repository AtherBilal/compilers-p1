#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "buildTree.h"
#include "traversals.h"

node_t *tempNode;
node_t *root;

void buildTree(FILE *tempFile){
  root = NULL;
  char inputLine[255];
  // read tempfile input without spaces
  while (fscanf(tempFile, " %s[^ \t\n]", inputLine) == 1){
    tempNode = malloc(sizeof(node_t));
    tempNode->left = tempNode->right = NULL;
    sprintf(tempNode->nodeID, "%.1s",inputLine);
    strcpy(tempNode->string, inputLine);
    tempNode->level = 0;

    if(root == NULL) {
      root = tempNode;
    }
    else {
      search(root);
    }
  }
}

void search(node_t *searchNode){

  int idCompare = strcmp(tempNode->nodeID, searchNode->nodeID);

  if (idCompare == 0){
    strcpy(searchNode->string, concat(searchNode->string, tempNode->string));
  } else if (idCompare > 0){
    if(searchNode->right != NULL) {
      tempNode->level += 1;
      search(searchNode->right);
    } else if (searchNode->right == NULL) {
      tempNode->level += 1;
      searchNode->right = tempNode;
    }
  } else if (idCompare < 0) {
    if (searchNode->left != NULL){
      tempNode->level += 1;
      searchNode->right = tempNode;
    } else if (searchNode->left == NULL) {
      tempNode->level += 1;
      searchNode->left = tempNode;
    }
  }
}