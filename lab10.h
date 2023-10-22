#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**************************************************************************************************
*	
*	- This is the header file for the Generic Binary Search Tree
*	- Includes headers for the functions used in the program
*	- Also includes the definitions for the Node and BST (Binary Search Tree) structs
*
**************************************************************************************************/
typedef struct Node Node;

struct Node {
	int data;
	Node *left;
	Node *right;
};

typedef struct BST{
	Node *root;
	int size;
} BST;

//HELPER FUNCTIONS:
Node createNode(int data);
Node *insertNode(Node *node, int data);
int searchTree(Node *node, int data);
void printTree(Node *node);
int findMin(Node *node, int min);
void deleteTree(Node *node);
///////////////////////////

// O(1)
BST * initBST();
// O(log(n))
int insertBST(BST *tree, int data);
// O(log(n))
int BSTContains(BST *tree, int data);
// O(n)
void freeTree(BST *tree);
// O(n)
void printInOrder(BST *tree);

// O(log(n))
int getMin(BST *tree);
