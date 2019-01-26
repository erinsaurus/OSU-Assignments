/********************************************************************
 ** Name: Erin Alltop
 ** Date: 2/18/17
 ** File: bst.c
 ** Description: Implementation of the binary search tree data structure
 *********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "bst.h"
#include "structs.h"

#define MEM_FIX

struct Node {
	TYPE val;
	struct Node *left;
	struct Node *right;
};

struct BSTree {
	struct Node *root;
	int          cnt;
};

/*----------------------------------------------------------------------------*/

/*********************************************************************
** Function: void initBSTree(struct BSTree *tree)
** Description: Initializes the tree structure
** Parameters: Pointer to tree struct
** Pre-Conditions: Tree is not null
** Post-Conditions: tree size is 0. Root is null.
*********************************************************************/ 
void initBSTree(struct BSTree *tree)
{
	tree->cnt  = 0;
	tree->root = 0;
}

/*********************************************************************
** Function: struct BSTree* newBSTree*()
** Description: creates and allocates a new tree
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: tree->count = 0. tree->root = 0;
*********************************************************************/ 
struct BSTree*  newBSTree()
{
	struct BSTree *tree = (struct BSTree *)malloc(sizeof(struct BSTree));
	assert(tree != 0);

	initBSTree(tree);
	return tree;
}

/*----------------------------------------------------------------------------*/
/*********************************************************************
** Function: void _freeBST(struct Node *node)
** Description: Function to free the nodes of a binary search tree
** Parameters: The root node of the tree to be freed
** Pre-Conditions: none
** Post-Conditions: Node and all descendants are deallocated
*********************************************************************/ 
void _freeBST(struct Node *node)
{
	if (node != 0) {
		_freeBST(node->left);
		_freeBST(node->right);
#ifdef MEM_FIX
		assert(node->val);
		free(node->val);
#endif		
		free(node);
	}
}

/*********************************************************************
** Function: void clearBSTree(struct BSTree *tree)
** Description: Clears the nodes of a binary search tree
** Parameters: a binary search tree
** Pre-Conditions: tree != null
** Post-Conditions: the nodes of the tree are deallocated
** tree->root = 0; tree->cnt = 0
*********************************************************************/ 
void clearBSTree(struct BSTree *tree)
{
	_freeBST(tree->root);
	tree->root = 0;
	tree->cnt  = 0;
}

/*********************************************************************
** Function: void deleteBSTree(struct BSTree *tree)
** Description: Function to deallocate a dynamically allocated
** binary search tree
** Parameters: the binary search tree
** Pre-Conditions: tree != null
** Post-Conditions: all nodes and the tree structure itself are deallocated
*********************************************************************/ 
void deleteBSTree(struct BSTree *tree)
{
	clearBSTree(tree);
	free(tree);
}

/*----------------------------------------------------------------------------*/
/*********************************************************************
** Function: int isEmptyBSTree()
** Description: Function to determine if a binary search tree is empty
** Parameters: the binary search tree
** Pre-Conditions: tree is not null
** Post-Conditions: none
*********************************************************************/ 
int isEmptyBSTree(struct BSTree *tree) { return (tree->cnt == 0); }

/*********************************************************************
** Function: int sizeBSTree(struct BSTree *tree)
** Description: Function to determine the size of a binary search tree
** Parameters: the binary search tree
** Pre-Conditions: tree is not null
** Post-Conditions: none
*********************************************************************/ 
int sizeBSTree(struct BSTree *tree) { return tree->cnt; }

/*----------------------------------------------------------------------------*/
/*********************************************************************
** Function: struct Node *_addNode(struct Node *cur, TYPE val)
** Description: Recursive helper function to add a node to the binary
** search tree.
** HINT: You have to use the compare() function to compare values.
** Parameters: the current root node. The value to be added to the 
** binary search tree.
** Pre-Conditions: val is not null
** Post-Conditions: none
*********************************************************************/ 
struct Node *_addNode(struct Node *cur, TYPE val)
{ /*write this*/
    
        //create the new node to be added
	struct Node *newNode;
        
        //base case test
	if(cur == 0)
	{ 
            /* If the current node is 0, then allocate the new
             * node and check that it worked. Initialize the value
             * of the new node with the given value and set its
             * left and right values to 0. Then return the new node
             */
            newNode = (struct Node *)malloc(sizeof(struct Node));
            assert(newNode != 0);

            newNode->val = val;
            newNode->left = newNode->right = 0;

            return newNode;
	}
        
        /* If the given value is less than the current value, then
         * set the left node equal to the _addNode function recursively.
         * Otherwise, set the right node equal to _addNode recursively.
         * Return the new cur node.
         * This function works recursively until cur = 0 and the new node
         * is added to the tree.
         */
	if((compare(val, cur->val)) == -1)
            cur->left = _addNode(cur->left, val);
	else
            cur->right = _addNode(cur->right, val);

	return cur;
}

/*********************************************************************
** Function: void addBSTree(struct BSTree *tree, TYPE val)
** Description: Function to add a value to the binary search tree
** Parameters: the binary search tree. The value to be added to the tree.
** Pre-Conditions: tree is not null. val is not null
** Post-Conditions: tree size increased by 1. tree now contains the value
*********************************************************************/ 
void addBSTree(struct BSTree *tree, TYPE val)
{
	tree->root = _addNode(tree->root, val);
	tree->cnt++;
}

/*********************************************************************
** Function: int contains BSTree(struct BSTree *tree, TYPE val)
** Description: Function to determine if the binary search tree contains
** a particular element
** HINT: You have to use the compare() function to compare values.
** Parameters: the binary search tree. The value to search for in the tree.
** Pre-Conditions: tree is not null. val is not null
** Post-Conditions: None
*********************************************************************/ 
/*----------------------------------------------------------------------------*/
int containsBSTree(struct BSTree *tree, TYPE val)
{ /*write this*/
    
        // First check that the tree exists and is not NULL 
	assert(tree != 0);
	assert(val != NULL);
        
        //create a new node and set it equal to the tree root
	struct Node *current = tree->root;

        /* While current does not equal null, compare given value
         * and the current value.
         */
	while(current != 0)
	{
            //If given value = current->value return true
            if(compare(val, current->val) == 0) 
                {return 1;}
            
            //if given value < current->val, set current equal to its left
            if(compare(val, current->val) == -1)
                {current = current->left;}
            
            //if given value > current->val, set current equal to its right
            else if(compare(val, current->val) == 1)
                {current = current->right;}
	}
	return 0; 
}

/*********************************************************************
** Function: TYPE _leftMost(struct Node *cur)
** Description: Helper function to find the left most child of a node
** Parameters: the current node
** Pre-Conditions: cur is not null
** Post-Conditions: None
*********************************************************************/ 
/*----------------------------------------------------------------------------*/
TYPE _leftMost(struct Node *cur)
{ /*write this*/
    
        //make sure cur is not null
	assert(cur != 0);
	
        /* If the node to the left of the current node is 0, return
         * the current value. Otherwise recursively call the _leftMost function
         * and give it the node left of the current node to test it.
         */
        if (cur->left == 0){
            return cur->val;
        }
        else{
            return _leftMost(cur->left);
        }
        return 0;
}

/*********************************************************************
** Function: struct Node *_removeLeftMost(struct Node *cur)
** Description: Recursive helper function to remove the left most child
** of a node.
** HINT: This function returns cur if its left child is NOT NULL.
** Otherwise, it returns the right child of cur and free cur.
** Note: If you do this iteratively, the above hint does not apply.
** Parameters: the current node
** Pre-Conditions: cur is not null
** Post-Conditions: the left most node of cur is not in the tree
*********************************************************************/ 
/*----------------------------------------------------------------------------*/
struct Node *_removeLeftMost(struct Node *cur)
{ /*write this*/
    
    //create temp node
    struct Node *node;

    /* If left of current is not 0, set it equal to the left most node 
     * by using the _removeLeftMost function again and passing it the node.
     * Return the cur node
     */
    if (cur->left != 0) {
    	cur->left = _removeLeftMost(cur->left);
    
        return cur;
    }
    
    //set temp node to the node right of current
    node = cur->right;

 //Code provided by the professors to help with memory leaks
#ifdef MEM_FIX
    assert(cur->val);
    free(cur->val);
#endif
    
    //free current node and return temp node
    free(cur);
    return node;
}

/*********************************************************************
** Function: struct Node *_removeNode(struct Node *cur, TYPE val)
** Description: Recursive helper function to remove a node from the tree.
** Parameters: the current node. The value to be removed from the tree.
** Pre-Conditions: val is in the tree. cur is not null. val is not null.
** Post-Conditions: None
*********************************************************************/ 
/*----------------------------------------------------------------------------*/
struct Node *_removeNode(struct Node *cur, TYPE val)
{ /*write this*/
    
    //check that curr node and val are not null
    assert(cur != 0);
    assert(val != NULL);

    //create a temp node
    struct Node *node;

    /* If they values of given and current are equal, check
     * if node right of current node is 0. If so, set temp node
     * to the node left of current node.
     */
    if(compare(val, cur->val) == 0)
    {
        if(cur->right == 0)
        {
            node = cur->left;

//Code provided by professor to fix memory issues
#ifdef MEM_FIX
    assert(cur->val);
    free(cur->val);
#endif
        //free cur and return node
        free(cur);
	return node;
	}
	
        //set val and right
        cur->val = _leftMost(cur->right);
	cur->right = _removeLeftMost(cur->right);
    }
    
    //If val < cur-> val, recursively call function with new left and val
    else if(compare( val, cur->val) == -1)
        {cur->left = _removeNode(cur->left, val);}
    
    else //otherwise call function recursively with right and given val
        {cur->right = _removeNode(cur->right, val);}
 
	return cur;
}

/*********************************************************************
** Function: void removeBSTree(struct BSTree *tree, TYPE val)
** Description: Function to remove a value from the binary serach tree
** Parameters: the binary search tree. The value to be removed from tree.
** Pre-Conditions: tree is not null. value is not null. value is in tree.
** Post-Conditions: Tree size is reduced by 1.
*********************************************************************/ 
void removeBSTree(struct BSTree *tree, TYPE val)
{
	if (containsBSTree(tree, val)) {
            tree->root = _removeNode(tree->root, val);
            tree->cnt--;
	}
}

/*----------------------------------------------------------------------------*/

/* The following is used only for debugging, set to "#if 0" when used 
  in other applications */
#if 1
#include <stdio.h>

/*----------------------------------------------------------------------------*/
void printNode(struct Node *cur) {
	 if (cur == 0) return;
	 printf("(");
	 printNode(cur->left);	 
	 /*Call print_type which prints the value of the TYPE*/
	 print_type(cur->val);
	 printNode(cur->right);
	 printf(")");
}

void printTree(struct BSTree *tree) {
	 if (tree == 0) return;	 
	 printNode(tree->root);	 
}
/*----------------------------------------------------------------------------*/

#endif


//#if 1
/************************************************************************************************************************
from here to the end of this file are a set of fucntions for testing the fucntions of the BST - This is also provided in a 
separate file .
***************************************************************************************************************************/
/*
function to built a Binary Search Tree (BST) by adding numbers in this specific order
the graph is empty to start: 50, 13, 110 , 10

*/
struct BSTree *buildBSTTree() {
    /*     50
         13  110
        10 
    */
    struct BSTree *tree	= newBSTree();		
		
	/*Create value of the type of data that you want to store*/
	struct data *myData1 = (struct data *) malloc(sizeof(struct data));
	struct data *myData2 = (struct data *) malloc(sizeof(struct data));
	struct data *myData3 = (struct data *) malloc(sizeof(struct data));
	struct data *myData4 = (struct data *) malloc(sizeof(struct data));
		
	myData1->number = 50;
	myData1->name = "rooty";
	myData2->number = 13;
	myData2->name = "lefty";
	myData3->number = 110;
	myData3->name = "righty";
	myData4->number = 10;
	myData4->name = "lefty of lefty";
	
	/*add the values to BST*/
	addBSTree(tree, myData1);
	addBSTree(tree, myData2);
	addBSTree(tree, myData3);
	addBSTree(tree, myData4);
    
    return tree;
}

/*
function to print the result of a test function
param: predicate:  the result of the test 
       nameTestFunction : the name of the function that has been tested
	   message

*/
void printTestResult(int predicate, char *nameTestFunction, char *message){
	if (predicate)
	   printf("%s(): PASS %s\n",nameTestFunction, message);
    else
	   printf("%s(): FAIL %s\n",nameTestFunction, message);        
}

/*
fucntion to test each node of the BST and their children

*/
void testAddNode() {
    struct BSTree *tree	= newBSTree();
 
#ifndef MEM_FIX
	struct data myData1,  myData2,  myData3,  myData4;
#else
	struct data *myData1 = (struct data *) malloc(sizeof(struct data));
	struct data *myData2 = (struct data *) malloc(sizeof(struct data));
	struct data *myData3 = (struct data *) malloc(sizeof(struct data));
	struct data *myData4 = (struct data *) malloc(sizeof(struct data));
#endif	

	//check the root node
#ifndef MEM_FIX
	myData1.number = 50;
	myData1.name = "rooty";
    addBSTree(tree, &myData1);	
	if (compare(tree->root->val, (TYPE *)&myData1) != 0) {
		printf("addNode() test: FAIL to insert 50 as root\n");
		return;
	}
#else
	myData1->number = 50;
	myData1->name = "rooty";
	addBSTree(tree, myData1);
	if (compare(tree->root->val, (TYPE *)myData1) != 0) {
		printf("addNode() test: FAIL to insert 50 as root\n");
		return;
	}
#endif
	//check the tree->cnt value after adding a node to the tree
    else if (tree->cnt != 1) {
        printf("addNode() test: FAIL to increase count when inserting 50 as root\n");
        return;
    }
    else printf("addNode() test: PASS when adding 50 as root\n");
    
#ifndef MEM_FIX    
	myData2.number = 13;
	myData2.name = "lefty";
    addBSTree(tree, &myData2);
    
    //check the position of the second element that is added to the BST tree
    if (compare(tree->root->left->val, (TYPE *)&myData2) != 0) {
        printf("addNode() test: FAIL to insert 13 as left child of root\n");
        return;
    }
#else
	myData2->number = 13;
	myData2->name = "lefty";
	addBSTree(tree, myData2);

	//check the position of the second element that is added to the BST tree
	if (compare(tree->root->left->val, (TYPE *)myData2) != 0) {
		printf("addNode() test: FAIL to insert 13 as left child of root\n");
		return;
	}
#endif
    else if (tree->cnt != 2) {
        printf("addNode() test: FAIL to increase count when inserting 13 as left of root\n");
        return;
    }
    else printf("addNode() test: PASS when adding 13 as left of root\n");
    
#ifndef MEM_FIX      
	myData3.number = 110;
	myData3.name = "righty";
    addBSTree(tree, &myData3);
        
    //check the position of the third element that is added to the BST tree    
    if (compare(tree->root->right->val, (TYPE *) &myData3) != 0) {
        printf("addNode() test: FAIL to insert 110 as right child of root\n");
        return;
    }
#else
	myData3->number = 110;
	myData3->name = "righty";
	addBSTree(tree, myData3);

	//check the position of the third element that is added to the BST tree    
	if (compare(tree->root->right->val, (TYPE *)myData3) != 0) {
		printf("addNode() test: FAIL to insert 110 as right child of root\n");
		return;
	}
#endif
	else if (tree->cnt != 3) {
        printf("addNode() test: FAIL to increase count when inserting 110 as right of root\n");
        return;
    }
    else printf("addNode() test: PASS when adding 110 as right of root\n");
    
#ifndef MEM_FIX
	myData4.number = 10;
	myData4.name = "righty of lefty";
	addBSTree(tree, &myData4);
    
	//check the position of the fourth element that is added to the BST tree
    if (compare(tree->root->left->left->val, (TYPE *) &myData4) != 0) {
        printf("addNode() test: FAIL to insert 10 as left child of left of root\n");
        return;
    }
#else
	myData4->number = 10;
	myData4->name = "righty of lefty";
	addBSTree(tree, myData4);

	//check the position of the fourth element that is added to the BST tree
	if (compare(tree->root->left->left->val, (TYPE *)myData4) != 0) {
		printf("addNode() test: FAIL to insert 10 as left child of left of root\n");
		return;
	}
#endif
    else if (tree->cnt != 4) {
        printf("addNode() test: FAIL to increase count when inserting 10 as left of left of root\n");
        return;
    }
    else printf("addNode() test: PASS when adding 10 as left of left of root\n");
	
#ifdef MEM_FIX
	deleteBSTree(tree);
#endif
}

/*
fucntion to test that the BST contains the elements that we added to it

*/
void testContainsBSTree() {
    struct BSTree *tree = buildBSTTree();
    
    struct data myData1,  myData2,  myData3,  myData4, myData5;
	
	myData1.number = 50;
	myData1.name = "rooty";
	myData2.number = 13;
	myData2.name = "lefty";
	myData3.number = 110;
	myData3.name = "righty";
	myData4.number = 10;
	myData4.name = "lefty of lefty";
    myData5.number = 111;
	myData5.name = "not in tree";
    
    printTestResult(containsBSTree(tree, &myData1), "containsBSTree", "when test containing 50 as root");
        
    printTestResult(containsBSTree(tree, &myData2), "containsBSTree", "when test containing 13 as left of root");
    
	printTestResult(containsBSTree(tree, &myData3), "containsBSTree", "when test containing 110 as right of root");
        
    printTestResult(containsBSTree(tree, &myData4), "containsBSTree", "when test containing 10 as left of left of root");

     //check containsBSTree fucntion when the tree does not contain a node    
    printTestResult(!containsBSTree(tree, &myData5), "containsBSTree", "when test containing 111, which is not in the tree");
    
    #ifdef MEM_FIX
	deleteBSTree(tree);
#endif
    
}

/*
fucntion to test the left_Most_element 

*/
void testLeftMost() {
    struct BSTree *tree = buildBSTTree();
    
	struct data myData3, myData4;

	myData3.number = 110;
	myData3.name = "righty";
	myData4.number = 10;
	myData4.name = "lefty of lefty";
    
	printTestResult(compare(_leftMost(tree->root), &myData4) == 0, "_leftMost", "left most of root");
    
	printTestResult(compare(_leftMost(tree->root->left), &myData4) == 0, "_leftMost", "left most of left of root");
    
	printTestResult(compare(_leftMost(tree->root->left->left), &myData4) == 0, "_leftMost", "left most of left of left of root");
    
	printTestResult(compare(_leftMost(tree->root->right), &myData3) == 0, "_leftMost", "left most of right of root");
        
        #ifdef MEM_FIX
	deleteBSTree(tree);
#endif

}

void testRemoveLeftMost() {
    struct BSTree *tree = buildBSTTree();
    struct Node *cur;
    
    cur = _removeLeftMost(tree->root);

	printTestResult(cur == tree->root, "_removeLeftMost", "removing leftmost of root 1st try");
    
    cur = _removeLeftMost(tree->root->right);
    printTestResult(cur == NULL, "_removeLeftMost", "removing leftmost of right of root 1st try");
   
#ifdef MEM_FIX
	tree->root->right = NULL;
#endif

 	cur = _removeLeftMost(tree->root);
    printTestResult(cur == tree->root, "_removeLeftMost", "removing leftmost of root 2st try");

#ifdef MEM_FIX
	deleteBSTree(tree);
#endif

}

void testRemoveNode() {
   struct BSTree *tree = buildBSTTree();
    struct Node *cur;
 
	struct data myData1,  myData2,  myData3,  myData4;
		
	myData1.number = 50;
	myData1.name = "rooty";
	myData2.number = 13;
	myData2.name = "lefty";
	myData3.number = 110;
	myData3.name = "righty";
	myData4.number = 10;
	myData4.name = "lefty of lefty";
    
#ifdef MEM_FIX
    tree->root = _removeNode(tree->root, &myData4);
#else
	_removeNode(tree->root, &myData4);
#endif
    printTestResult(compare(tree->root->val, &myData1) == 0 && tree->root->left->left == NULL, "_removeNode", "remove left of left of root 1st try");

#ifdef MEM_FIX	        
	tree->root = _removeNode(tree->root, &myData3);
#else
	_removeNode(tree->root, &myData3);
#endif
	 printTestResult(compare(tree->root->val, &myData1) == 0 && tree->root->right == NULL, "_removeNode", "remove right of root 2st try");

#ifdef MEM_FIX	   
	tree->root = _removeNode(tree->root, &myData2);
#else
	_removeNode(tree->root, &myData2);
#endif
	printTestResult(compare(tree->root->val, &myData1) == 0 && tree->root->left == 0, "_removeNode", "remove right of root 3st try");
        
    cur = _removeNode(tree->root, &myData1);
#ifdef MEM_FIX
	tree->root = cur;
#endif
    printTestResult(cur == NULL, "_removeNode", "remove right of root 4st try");  

#ifdef MEM_FIX
	deleteBSTree(tree);
#endif
}

/*

Main function for testing different fucntions of the Assignment#4.

*/

int main(int argc, char *argv[]){	

   //After implementing your code, please uncommnet the following calls to the test functions and test your code 

    testAddNode();
	
	printf("\n");
    testContainsBSTree();
	
	printf("\n");
    testLeftMost();
	
	printf("\n");
    testRemoveLeftMost();
	
	printf("\n");
    testRemoveNode();
    
	
	return 0;


}