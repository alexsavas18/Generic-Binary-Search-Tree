#include "lab10.h"
/**************************************************************************************************
* GENERIC BINARY SEARCH TREE MAIN PROGRAM
*	  - This is the main program to test the Binary Search Tree, and to run the BST operations 
*	  - This program inserts Nodes into the BST and searches for known values and values that aren't 
*   in the tree to test error checking
*   - The program also attempts to delete the tree
*   - Function execution time is displayed in the output
**************************************************************************************************/
int main()
{
  Node newNodes[5];
  for(int i = 0; i < 5; i++)
  {
    newNodes[i] = createNode(rand());
    printf("Node %d: %d\n", (i+1), newNodes[i].data);
  }
  BST *myBST = initBST();
  for(int i = 0; i < 5; i++)
  {
    printf("INSERTING NODE %d: %d\n", (i+1), newNodes[i].data);
    insertBST(myBST, newNodes[i].data);
    printf("Size: %d\n", myBST->size);
  }
  printf("**SEARCHING TREE FOR KNOWN VALUE %d**\n", newNodes[4].data);
  clock_t t = clock();
  BSTContains(myBST, newNodes[4].data);
  t = clock() - t;
  printf("Searching took %f seconds\n", ((float)t)/CLOCKS_PER_SEC);

  printf("**SEARCHING TREE FOR A VALUE NOT IN THE TREE: 5**\n");
  BSTContains(myBST, 5);


  puts("**PRINTING TREE**");
  clock_t t2 = clock();
  printInOrder(myBST);
  t2 = clock() - t2;
  printf("Printing took %f seconds\n", ((float)t2)/CLOCKS_PER_SEC);

  //insertBST(myBST, 1);
  puts("TESTING getMin");
  getMin(myBST);

  puts("**ATTEMPTING TO DELETE THE TREE**");
  freeTree(myBST);
  printf("Size: %d\n", myBST->size);

}
