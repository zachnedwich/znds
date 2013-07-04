#ifndef __ZN_BTREE_H
#define __ZN_BTREE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct node {
  char *value;
  struct node *left;
  struct node *right;
};

struct btree {
  struct node *nodes;
};

typedef struct node *btree;

btree newNode(void);
btree initNode(char *value, btree p1, btree p2);
btree createTree(char* a[], int i, int size);

void preorder(btree root);
void inorder(btree root);
void postorder(btree root);


#endif
