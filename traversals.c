#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "buildTree.h"
#include "traversals.h"

node_t *temp;
node_t *root;

char *concat(const char *string1, const char *string2){
  char *newString = malloc(snprintf(NULL, 0, "%s %s", string2, string1) + 1);
  sprintf(newString, "%s %s", string2, string1);
  return newString;
}


void traversePreOrder(node_t *root, char *outputBase){
  FILE *outputFile;
  char *outExtension = ".preorder";
  char *outputFileName = malloc(snprintf(NULL, 0, "%s%s", outputBase, outExtension) + 1);
  sprintf(outputFileName, "%s%s", outputBase, outExtension);
  outputFile = fopen(outputFileName, "w");
  if(outputFile == NULL){
    fprintf(stderr, "Unable to open output file: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }
  printPreorder(root, outputFile);
  fclose(outputFile);
}

void traverseInOrder(node_t *root, char *outputBase){
  FILE *outputFile;
  char *outExtension = ".inorder";
  char *outputFileName = malloc(snprintf(NULL, 0, "%s%s", outputBase, outExtension) + 1);
  sprintf(outputFileName, "%s%s", outputBase, outExtension);
  outputFile = fopen(outputFileName, "w");
  if(outputFile == NULL){
    fprintf(stderr, "Unable to open output file: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }
  printInorder(root, outputFile);
  fclose(outputFile);
}

void traverseLevelOrder(node_t *root, char *outputBase){
  FILE *outputFile;
  char *outExtension = ".levelorder";
  char *outputFileName = malloc(snprintf(NULL, 0, "%s%s", outputBase, outExtension) + 1);
  sprintf(outputFileName, "%s%s", outputBase, outExtension);
  outputFile = fopen(outputFileName, "w");
  if(outputFile == NULL){
    fprintf(stderr, "Unable to open output file: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }
  printLevelOrder(root, outputFile);
  fclose(outputFile);
}

void printPreorder(node_t *n, FILE *outputFile){
  if (root == NULL){
    return;
  }
  fprintf(outputFile,"%*c%d:%s \n", n->level*2,' ',n->level, concat(n->string, n->nodeID));
  if (n->left != NULL)
    printPreorder(n->left, outputFile);
  if (n->right != NULL)
    printPreorder(n->right, outputFile);
}

void printInorder(node_t *n, FILE *outputFile){
  if (root == NULL){
    return;
  }
  if (n->left != NULL)
    printInorder(n->left, outputFile);
    fprintf(outputFile,"%*c%d:%s \n", n->level*2,' ',n->level, concat(n->string, n->nodeID));
  if (n->right != NULL)
    printInorder(n->right, outputFile);
}

void printPostorder(node_t *n, FILE *outputFile){
  if (root == NULL){
    return;
  }
  if (n->left != NULL)
    printPostorder(n->left, outputFile);
  if (n->right != NULL)
    printPostorder(n->right, outputFile);
    fprintf(outputFile,"%*c%d:%s \n", n->level*2,' ',n->level, concat(n->string, n->nodeID));
}



void printLevelOrder(struct node *root, FILE *outputFile)
{
   int h,i;
   h = height(root);
   for ( i = 1; i <= h; i++)
   {
        printGivenLevel(root, i, outputFile);
   }
}
void printGivenLevel(struct node *root,int level, FILE *outputFile)
{
   if(root == NULL){
       return;
   }
   if(level==1){
      fprintf(outputFile,"%*c%d:%s \n", root->level*2,' ',root->level, concat(root->string, root->nodeID));
   }
   else if(level>1)
   {
          printGivenLevel(root->left,level-1, outputFile);
          printGivenLevel(root->right,level-1, outputFile);
   }
}

int height(struct node *root){

   int right_height,left_height;
   if(root==NULL)
   {
       return 0;
   }
   left_height= height(root->left);
   right_height= height(root->right);
   if (left_height > right_height)
   {
        return left_height + 1;
   }
   else
   {
        return right_height + 1;
   }
}