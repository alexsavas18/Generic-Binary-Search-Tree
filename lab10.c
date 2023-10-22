#include "lab10.h"
/**************************************************************************************************
* GENERIC BINARY SEARCH TREE: This is a gneric binary search tree for a lab assignment for my 
* algorithm design course
*	- These are the functions to insert, print, and find the minimum and maximum of
*	 the Binary Search Tree
*	- This program includes helper functions as well to create a node, insert a node, 
*	for a specified element and returns its index
**************************************************************************************************/

//____________________Helper Functions____________________//
//Helper function to create a new Node by allocating memory for the left and right pointers
Node createNode(int data)
{
	Node newNode;
	newNode.data = data;
	newNode.left = malloc(sizeof(Node));
	newNode.right = malloc(sizeof(Node));
	return newNode;
}
//this is a recursive, O(log(N)) helper function used in the insertBST function to add specified data into a BST
Node *insertNode(Node *node, int data)
{
	//puts("Trying to insert new node");
	//If there's nothing in the node, immediately add the new node to the BST
	if(node == NULL)
	{
		node = malloc(sizeof(Node)); //allocating memory for the new node
		node->data = data;
		return node;
	}
	else if(data < node->data) //if the current data is less than what's in the BST, insert on the left
	{
		//puts("Inserting data on the left side");
		node->left = insertNode(node->left, data);
	}
	else if(data > node->data) //if the current data is greater than what's in the BST, insert on the right
	{
		//puts("Inserting on the right side");
		node->right = insertNode(node->right, data);
	}
	return node;
}
//this is a recursive, O(log(n)) helper function used in BSTContains that searches for a specified item in the BST
int searchTree(Node *node, int data)
{
	//if the node passed in doesn't point to anything, then the specified item is nowhere to be found in the tree
	if(node == NULL)
	{
		puts("Node is empty");
		return 0;
	}
	if(data == node->data) //if the data is equal to what's in the current node, we've found the data
	{
		printf("Data %d found!\n", data);
		return data; //returns the data item
	}
	else if(data < node->data) //if the data is less than what's in the current node, search the left side
	{
		puts("searching on the left side");
		return searchTree(node->left, data);
	}
	else if(data > node->data) //if the data is greater than what's in the current node, search the right side
	{
		//puts("searching on the right side");
		return searchTree(node->right, data);
	}
	else
	{
		puts("Couldn't find the data");
		return 0;
	}
}
//recursive O(n) helper function used in printInOrder. This function prints all the members in the BST
void printTree(Node *node)
{
	if(node == NULL)
	{
		return;
	}
	printTree(node->left);
	printf("%d\n", node->data);
	printTree(node->right);
}
//recursive helper function used in getMin to find the minimum value in the BST
//this function takes in a predetermined min value (the data of the root) and tries to find something smaller
int findMin(Node *node, int min)
{
	puts("finding the min");
	if(node == NULL)
	{
		return min;
	}
	else if(min >= node->data)
	{
		puts("setting new min value");
		min = node->data;
	}
	return findMin(node->left, min); //always call this function on the left side because all values on the left are less than the root
}
//recursive helper function used in freeBST that deletes the entire tree by freeing every node
void deleteTree(Node *node)
{
	if(node == NULL)
	{
		//puts("Empty");
		return;
	}
	//puts("Deleting left side");
	deleteTree(node->left);
	//puts("Deleting right side");
	deleteTree(node->right);
	//puts("Freeing the node");
	free(node);
}

//____________________Required Functions____________________//
//initializes an empty BST
BST * initBST()
{
	BST *newBST = malloc(sizeof(BST)); //allocatig memory for a new BST struct
	if(newBST)
	{
	newBST->size = 0;
	return newBST;
	}
	else
	{
		puts("fail");
		return NULL;
	}
}
//this function calls the insertNode helper function and returns 0 if the node was inserted or 1 if it failed
int insertBST(BST *tree, int data)
{
	tree->root = insertNode(tree->root, data);
	if(tree->root)
	{
		tree->size++;
		return 0;
	}
	else
	{
		return 1;
	}
}

//this function calls the searchTree function to search for a specific value in the tree
//returns 0 if the data wasn't found or 1 if it's in the tree
int BSTContains(BST *tree, int data)
{
	if(tree == NULL)
	{
		puts("Tree is empty");
		return 0;
	}
	else
	{
		puts("Attempting to search tree");
		if(searchTree(tree->root, data))
		{
			puts("Data was found!");
			return 1;
		}
		else
		{
			puts("Data was not found");
			return 0;
		}
	}
}
//this function simply calls the printTree function in order to recursively print all the values in order in the BST
void printInOrder(BST *tree)
{
	printTree(tree->root);
}
//this function calls the findMin function by setting the minimum value equal to what's in the root node to start, and returns the minimum value of the entire BST
int getMin(BST *tree)
{
	int min = tree->root->data;
	min = findMin(tree->root, min);
	printf("The min value is %d\n", min);
	return min;
}
//simply calls deleteTree, sets size to 0, and frees the BST struct
void freeTree(BST *tree)
{
	deleteTree(tree->root);
	tree->size = 0;
	free(tree);
}
