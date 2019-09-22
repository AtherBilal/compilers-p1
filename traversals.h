//buildTree.h

#ifndef BUILDTREE_H
#define BUILDTREE_H

extern node_t *root;

//helper
void printGivenLevel(struct node *root,int level, FILE *outputFile);
int height(struct node *root);
char *concat(const char *string1, const char *string2);

//traversals
void traversePreOrder(node_t *root, char *outputBase);
void traverseInOrder(node_t *root, char *outputBase);
void traverseLevelOrder(node_t *root, char *outputBase);

//printing traversals
void printInorder(node_t *n, FILE *outputFile);
void printPreorder(node_t *n, FILE *outputFile);
void printLevelOrder(struct node *root, FILE *outputFile);
#endif