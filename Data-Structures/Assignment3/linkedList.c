/********************************************************************
 ** Name: Erin Alltop
 ** Date: 2/3/17
 ** File: linkedList.c
 ** Description: This program is an implementation of a linked list. 
 ** It demonstrates the creation and initialization of a
 ** linked list. It also demonstrates creating a new link,
 ** adding a link before and after a given link, adding a link to the 
 ** front and back of the structure, removing a link from the front
 ** and back, and in a particular position. It also has a function
 ** to print the entire linked list and destroy it at the completion
 ** of the program.
 *********************************************************************/
#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Double link
struct Link
{
	TYPE value;
	struct Link* next;
	struct Link* prev;
};

// Double linked list with front and back sentinels
struct LinkedList
{
	int size;
	struct Link* frontSentinel;
	struct Link* backSentinel;
};

/*********************************************************************
** Function: static void init(struct LinkedList* list)
** Description: Allocates the list's sentinel and sets the size to 0.
** The sentinel's next and prev should point to each other or NULL
** as appropriate.
** Parameters: list
** Pre-Conditions: None
** Post-Conditions: Above
*********************************************************************/ 
static void init(struct LinkedList* list) 
{ // FIXME: you must write this
  
    //initialize front Sentinel
    list->frontSentinel = malloc(sizeof(struct Link));
    assert(list->frontSentinel != 0);
    
    //initialize back Sentinel
    list->backSentinel = malloc(sizeof(struct Link));
    assert(list->backSentinel);
    
    //set front and bacl Sentinel to point to each other
    list->frontSentinel->next = list->backSentinel;
    list->backSentinel->prev = list->frontSentinel;
    
    //set list size to 0
    list->size = 0;
}

/*********************************************************************
** Function: static void (addLinkBefore(struct LinkedList* list, 
** struct Link* link, TYPE value)
** Description: Adds a new link with the given value before the given
** link and increments the list's size.
** Parameters: list, link, and TYPE value
** Pre-Conditions: link is initialized
** Post-Conditions: link with given value is added before given link
*********************************************************************/ 
static void addLinkBefore(struct LinkedList* list, struct Link* link, TYPE value)
{ // FIXME: you must write this
    
    //create a new link and allocate memory for it
    struct Link *newLink = (struct Link *)malloc(sizeof(struct Link));
    assert(newLink != 0);
    
    //set given value for new link
    newLink->value = value;
    
    //change link pointers to point to the correct positions
    link->prev->next = newLink;
    newLink->prev = link->prev;
    newLink->next = link;
    link->prev = newLink;
    
    //increment size of list by 1
    list->size++;
}

/*********************************************************************
** Function: static void removeLink(struct LinkedList* list, struct
** Link *link)
** Description: Removes the given link from the list and decrements
** the list's size.
** Parameters: list and link
** Pre-Conditions: list and link are initialized
** Post-Conditions: given link is removed and list's size is decremented
*********************************************************************/ 
static void removeLink(struct LinkedList* list, struct Link* link)
{// FIXME: you must write this
    
    //set given link's links on either side to point to its neighbors
    link->prev->next = link->next;
    link->next->prev = link->prev;
    
    //free memory for link
    free(link);
    
    //decrement list size by 1
    list->size--;   
}

/*********************************************************************
** Function: struct LinkedList* linkedListCreate()
** Description: Allocates and initializes a list
** Parameters: None
** Pre-Conditions:None
** Post-Conditions: new list is allocated and initialized
*********************************************************************/ 
struct LinkedList* linkedListCreate()
{    
    struct LinkedList* newDeque = malloc(sizeof(struct LinkedList));
    init(newDeque);
    return newDeque;
}

/*********************************************************************
** Function: void linkedListDestroy(struct LinkedList* list)
** Description: Deallocates every link in the list including
** the sentinels, and frees the list itself
** Parameters: list
** Pre-Conditions: None
** Post-Conditions: list is deallocated and freed
*********************************************************************/ 
void linkedListDestroy(struct LinkedList* list)
{
	while (!linkedListIsEmpty(list))
	{
		linkedListRemoveFront(list);
	}
	free(list->frontSentinel);
	free(list->backSentinel);
	free(list);
}

/*********************************************************************
** Function: void linkedListAddFront(struct LinkedList* list, TYPE value)
** Description: Adds a new link with the given value to the front
** of the deque
** Parameters: list, TYPE value
** Pre-Conditions: none
** Post-Conditions: link with the given value is added to the front
** of the deque.
*********************************************************************/ 
void linkedListAddFront(struct LinkedList* list, TYPE value)
{ // FIXME: you must write this
    
    addLinkBefore(list, list->frontSentinel->next, value);
}

/*********************************************************************
** Function: void linkedListAddBack(struct LinkedList* list, TYPE value)
** Description: Adds a new link with the given value to the back
** of the deque
** Parameters: list
** Pre-Conditions: none
** Post-Conditions: link with the given value added to the back of the deque
*********************************************************************/ 
void linkedListAddBack(struct LinkedList* list, TYPE value)
{ // FIXME: you must write this
    
    assert(!linkedListIsEmpty(list));
    addLinkBefore(list, list->backSentinel, value);
}

/*********************************************************************
** Function: TYPE linkedListFront(struct LinkedList* list)
** Description: Returns the value of the link at the front of the deque
** Parameters: list
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
TYPE linkedListFront(struct LinkedList* list)
{ // FIXME: you must write this
    
    return list->frontSentinel->value;
}

/*********************************************************************
** Function: TYPE linkedListBack(struct LinkedList* list)
** Description: Returns the value of the link at the back of the deque
** Parameters: list
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
TYPE linkedListBack(struct LinkedList* list)
{ // FIXME: you must write this
    
    return list->backSentinel->value;
}

/*********************************************************************
** Function: void linkedListRemoveFront(struct LinkedList* list)
** Description: Removes the link at the front of the deque
** Parameters: list
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void linkedListRemoveFront(struct LinkedList* list)
{ // FIXME: you must write this
    
    assert(!linkedListIsEmpty(list));
    removeLink(list, list->frontSentinel->next);
}

/*********************************************************************
** Function: void LinkedListRemoveBack(struct LinkedList* list)
** Description: Removes the link at the back of the deque.
** Parameters: list
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void linkedListRemoveBack(struct LinkedList* list)
{ // FIXME: you must write this
    
    assert(!linkedListIsEmpty(list));
    removeLink(list, list->backSentinel->prev);
}

/*********************************************************************
** Function: int linkedListIsEmpty(struct LinkedList* list)
** Description: Returns 1 if the deque is empty and 0 otherwise
** Parameters: list
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
int linkedListIsEmpty(struct LinkedList* list)
{ // FIXME: you must write this
    
    return list->size == 0;
}

/*********************************************************************
** Function: void linkedListPrint(struct LinkedList* list)
** Description: Prints the values of the linkes in the deque fron
 * front to back.
** Parameters: list
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/ 
void linkedListPrint(struct LinkedList* list)
{ // FIXME: you must write this
    
    //make sure the list is not empty
    assert(!linkedListIsEmpty(list));
    
    //create a temp link and allocate memory for it
    struct Link *curr = (struct Link *)malloc(sizeof(struct Link));
    
    //set current/temp link to the frontSentinel->prev node
    curr = list->frontSentinel->prev;
    
    /* While the curr->prev node does not equal 0
     * print the current value and set the current/temp node
     * to equal the next node.
     */
    while(curr->prev != 0){
        printf(" % d", curr->value);
        curr = curr->prev;
    }
}

/*********************************************************************
** Function:  void linkedListAdd(struct LinkedList* list, TYPE value)
** Description: Adds a link with the given value to the bag.
** Parameters: list, TYPE value
** Pre-Conditions: list is initialized
** Post-Conditions: link with the given value is added.
*********************************************************************/ 
void linkedListAdd(struct LinkedList* list, TYPE value)
{// FIXME: you must write this
    
    //using add to front function because order does not matter
    linkedListAddFront(list, value);
}

/*********************************************************************
** Function: int linkedListContains(struct LinkedList* list,
** TYPE value)
** Description: Returns 1 if a link with the value is in the bag
** and 0 otherwise.
** Parameters: list, TYPE value
** Pre-Conditions: list is initialized
** Post-Conditions: returns 1 if in the bag, 0 otherwise
*********************************************************************/ 
int linkedListContains(struct LinkedList* list, TYPE value)
{ // FIXME: you must write this
    
    //create a temporary link node and set it to the first node with value
    struct Link *curr = list->frontSentinel->next;
    
    /*While the temp/current node does not equal the back sentinel,
     * check to see if the current/temp node equals the given value.
     * If it does, return 1. Otherwise, set the current/temp node to 0.
     * If no values are found that are equal, return 0.
     */
    while(!EQ(curr, list->backSentinel)){
        if(EQ(curr->value, value))
            return 1;
        curr = curr->next;
    }
    return 0;
}

/*********************************************************************
** Function: void linkedListRemove(struct LinkedList* list,
** TYPE value)
** Description: Removes the first occurrence of a link with the 
** given value.
** Parameters: list, TYPE value
** Pre-Conditions: list is initialized, value is not NULL
** Post-Conditions: first occurrence of given value is removed
*********************************************************************/ 
void linkedListRemove(struct LinkedList* list, TYPE value)
{ // FIXME: you must write this
    
    //create a temporary link
    struct Link *curr;
    //set temp link to equal the first node with value
    curr = list->frontSentinel->next;
    
    /*while the temp node does not reach the end of the list
     * check if the value of the current/temp node equals
     * the given value. If it does, remove the link, decrement
     * the size of the list, and exit the loop.
     * If it does not, set the current/temp node to the next node.
     */
    
    while(curr != list->backSentinel){
        if(EQ(curr->value, value)){
            removeLink(list, curr);
            list->size--;
            break;
        }
        curr = curr->next;
    }
}
