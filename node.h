// file node.h
#ifndef NODE_H
#define NODE_H

typedef struct node{
  struct node *left;
  struct node *right;
  char nodeID[2];
  char string[300];
  int level;
} node_t;

#endif 
