#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "../include/btree.h"

btree newNode()
{
    return ((btree)malloc(sizeof(struct node)));
}

btree initNode(char *value, btree p1, btree p2)
{
    btree tree;
    tree = newNode();
    tree->value = value;
    tree->left = p1;
    tree->right = p2;
    return tree;
}

btree createTree(char* a[], int i, int size)
{
    if (i >= size)
        return NULL;
    else
        return(initNode(a[i],
    createTree(a, 2*i+1, size),
    createTree(a, 2*i+2, size)));
}


void preorder (btree root)
{
    if (root != NULL) {
        printf("%s \n", root->value);
        preorder(root -> left);
        preorder(root -> right);
    }
}


void inorder (btree root)
{
    if (root != NULL) {
        inorder(root -> left);
        printf("%s \n", root->value);
        inorder(root -> right);
    }
}



void postorder (btree root)
{
    if (root != NULL) {
        postorder(root -> left);
        postorder(root -> right);
        printf("%s \n", root->value);
    }
}

int main()
{
  btree root;
  char* a[10] = {"zach", "nedwich"};

  root = createTree(a, 0, 10) ;
preorder(root);
inorder(root);
postorder(root);
  return 0;

}
