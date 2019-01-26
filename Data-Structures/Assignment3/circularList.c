/********************************************************************
 ** Name: Erin Alltop
 ** Date: 2/3/17
 ** File: circularList.c
 ** Description: This program is an implementation of a circular
 ** linked list. It demonstrates the creation and initialization of a
 ** circular linked list. It also demonstrates, creating a new link,
 ** adding a link before and after a given link, adding a link to the 
 ** front and back of the structure, removing a link from the front
 ** and back, and in a particular position. It also has a function
 ** to print the entire linked list and destroy it at the completion
 ** of the program.
 *********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};


/*********************************************************************
** Function: static void init(struct CircularList* list)
** Description: Allocates the list's sentinel and sets the size to 0.
** Parameters: CircularList structure
** Pre-Conditions: none
** Post-Conditions: The sentinel's next and prev should point to
** the sentinel itself.
*********************************************************************/ 
static void init(struct CircularList* list)
{ // FIXME: you must write this
    
    //allocate memory to the sentinel
    list->sentinel = (struct Link*)malloc(sizeof(struct Link));
    
    //assert that the sentinel does not equal zero
    assert(list->sentinel != 0);
    
    //set the sentinel to point to itself
    list->sentinel->next = list->sentinel;
    list->sentinel->prev = list->sentinel;
    
    //set the size to 0
    list->size = 0;
}

/*********************************************************************
** Function: static struct Link* createLink(TYPE value)
** Description: Creates a link with the given value and NULL next
** and prev pointers.
** Parameters: a value of TYPE
** Pre-Conditions: 
** Post-Conditions: a link is created with the given value and NULL
** next and prev pointers.
*********************************************************************/ 
static struct Link* createLink(TYPE value)
{ // FIXME: you must write this
    
	// Create a new link and allocate memory
	struct Link * createLink = (struct Link *)malloc(sizeof(struct Link));

	//Set the new links next and prev pointers to NULL
	createLink->next = NULL;
	createLink->prev = NULL;
	
	//give the new link the given value
	createLink->value = value;
    
        //return the new link
        return createLink;
}

/*********************************************************************
** Function: static void addLinkAfter(struct CircularList * list, struct
** Link* link, TYPE value)
** Description: Adds a new link with the given value after the given 
** link and increments the list's size.
** Parameters: linked list, a link in the list, and a value of TYPE
** Pre-Conditions: the list and link must be created and initialized
** Post-Conditions: a new link is inserted after the given link
*********************************************************************/ 
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{ // FIXME: you must write this
    
        //create a pointer to a link
        //call the createLink function to return the new link
	struct Link * addAfter = createLink(value);
        
        //make sure list is not empty
      // assert(!circularListIsEmpty(list));
        
        //preserve current linkings
        addAfter->prev = link;
        addAfter->next = link->next;
        
        //insert new link into current linkings
        link->next = addAfter;
        addAfter->next->prev = addAfter;
	
	// Increment list size
	list->size++;
}

/*********************************************************************
** Function: static void removeLink(struct CircularList*,
** struct Link* link)
** Description: Removes the given link from the list and decrements
** the list's size.
** Parameters: linked list and a link in the list
** Pre-Conditions: list and link initialized
** Post-Conditions: the given link is removed and the size is 
** decremented. Given link is set to NULL and the memory is freed.
*********************************************************************/ 
static void removeLink(struct CircularList* list, struct Link* link)
{ // FIXME: you must write this
    
        //check to be sure the list is not empty
       assert(!circularListIsEmpty(list));
       
	//link's previous and next should point to each other
       //to allow the link to be removed
	link->prev->next = link->next;
	link->next->prev = link->prev;

	//set link pointers to NULL
        link->prev = NULL;
	link->next = NULL;
        
        //free memory and set link to NULL
	free(link);
	link = NULL;

	// Decrement list size 
	list->size--;
}

/*********************************************************************
** Function: struct CircularList* circularListCreate()
** Description: Allocates and initializes a list
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: circular list is initialized and returned
*********************************************************************/ 
struct CircularList* circularListCreate()
{
	struct CircularList* list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/*********************************************************************
** Function: void circularListDestroy(struct CircularList* list)
** Description: Deallocates every link in the list and frees the
** list pointers
** Parameters: circularList list
** Pre-Conditions: None
** Post-Conditions: every link in the list is deallocated and the
** pointer is freed.
*********************************************************************/ 
void circularListDestroy(struct CircularList* list)
{ // FIXME: you must write this
    
    //while the list is not empty, create a pointer to the
    //next node and remove the link
    while (!circularListIsEmpty(list)) {
        struct Link * tempPtr = list->sentinel->next;
	removeLink(list, tempPtr);
	}

        //free the pointer to the sentinel
	free(list->sentinel);
        
        //free the memory for the list
	free(list);
}

/*********************************************************************
** Function: void circularListAddFront(struct CircularList* list,
** TYPE value)
** Description: Adds a new link with the given value to the front
** of the deque.
** Parameters: list and value
** Pre-Conditions: None
** Post-Conditions: new link is added at the front
*********************************************************************/ 
void circularListAddFront(struct CircularList* list, TYPE value)
{ // FIXME: you must write this
    
    //use addLinkAfter function to add link after the sentinel
    addLinkAfter(list, list->sentinel, value);
}

/*********************************************************************
** Function: void circularListAddBack(struct CircularList* list,
** TYPE value)
** Description: Adds a new link with the given value to the back
** of the deque.
** Parameters: list and value
** Pre-Conditions: None
** Post-Conditions: new link is added at the back
*********************************************************************/ 
void circularListAddBack(struct CircularList* list, TYPE value)
{// FIXME: you must write this
    
    //use addLinkAfter function to add link to the prev node
    //of the sentinel
   addLinkAfter(list, list->sentinel->prev, value);
}

/*********************************************************************
** Function: circularListFront(struct CircularList* list
** Description: Returns the value of the link at the front of the deque
** Parameters: list 
** Pre-Conditions: None
** Post-Conditions: returns the value at the front
*********************************************************************/ 
TYPE circularListFront(struct CircularList* list)
{// FIXME: you must write this

   return ((list->sentinel)->next)->value;
}

/*********************************************************************
** Function: circularListBack(struct CircularList* list
** Description: Returns the value of the link at the back of the deque
** Parameters: list 
** Pre-Conditions: None
** Post-Conditions: returns the value at the back
*********************************************************************/ 
TYPE circularListBack(struct CircularList* list)
{ // FIXME: you must write this
    
    return ((list->sentinel)->prev)->value;
}

/*********************************************************************
** Function: void circularListRemoveFront(struct CircularList* list)
** Description: Removes the link at the front of the deque
** Parameters: list 
** Pre-Conditions: None
** Post-Conditions: link at the front of the deque is removed
*********************************************************************/ 
void circularListRemoveFront(struct CircularList* list)
{ // FIXME: you must write this
    
    //make sure node is not NULL
    assert(list->sentinel->next != NULL);
    
    //use removeLink function to remove the sentinel's next node
    removeLink(list, (list->sentinel)->next);
}

/*********************************************************************
** Function: void circularListRemoveBack(struct CircularList* list)
** Description: Removes the link at the back of the deque
** Parameters: list 
** Pre-Conditions: None
** Post-Conditions: link at the back of the deque is removed
*********************************************************************/ 
void circularListRemoveBack(struct CircularList* list)
{ // FIXME: you must write this
    
    //make sure node is not NULL
    assert(list->sentinel->prev != NULL);
    
    //use removeLink function to remove the sentinel's prev node
    removeLink(list, (list->sentinel)->prev);
}

/*********************************************************************
** Function: int circulareListIsEmpty(struct CircularList* list)
** Description: Returns 1 if the deque is empty an 0 otherwise
** Parameters:list
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/ 
int circularListIsEmpty(struct CircularList* list)
{ // FIXME: you must write this
    
    //if the sentinel's next node is NULL, the list is empty
   // if((list->sentinel->next == NULL)){
    return (list->size == 0);
}

/*********************************************************************
** Function: void circularListPrint(struct CircularList* list)
** Description: Prints the values of the links in the deque from
** front to back.
** Parameters: list
** Pre-Conditions: None
** Post-Conditions: prints list from front to back
*********************************************************************/ 
void circularListPrint(struct CircularList* list)
{ // FIXME: you must write this
	
    if(!circularListIsEmpty(list)){
    	int size = list->size;
	struct Link * currLink = list->sentinel->next;
	printf("CircularList from front to back:\n"); 
        
        do{
        printf("Value: %g\n", currLink->value);
	currLink = currLink->next;
        size--;
        }while(size);
        
    printf("\n");
    }
}

/*********************************************************************
** Function: circularListReverse(struct CircularList*list)
** Description: Reverses the deque
** Parameters: list
** Pre-Conditions: None
** Post-Conditions: The deque is reversed
*********************************************************************/ 
void circularListReverse(struct CircularList* list)
{ // FIXME: you must write this
    
    //create a temporary link and set it to the sentinel
    struct Link * currLink = list->sentinel;
    
    //set a variable to equal size of the list
    int size = list->size;
    
    /*while the size of the list does not equal 0, 
     *create a temp node and set it to equal the current link's
     * next node. Set the current node's prev to next.
     * Set the current link to the next node.
     * decrement size by 1.
     */
    while(size != 0){
        struct Link * temp = currLink->next;
        currLink->next = currLink->prev;
        currLink->prev = temp;
	currLink = currLink->next;
        size--;  
    }
    
   // free(currLink);
}
