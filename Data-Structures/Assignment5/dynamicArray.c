/*
 * CS 261 Assignment 5
 * Name: Erin Alltop
 * Date: 3/1/17
 */

#include "dynamicArray.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define TESTING

#ifndef TESTING
static void adjustHeap(DynamicArray* heap, int last, int position, compareFunction compare);
static void buildHeap(DynamicArray* heap, compareFunction compare);
#endif

struct DynamicArray
{
	TYPE* data;
	int size;
	int capacity;
};

// --- Dynamic array ---

static void setCapacity(DynamicArray* array, int capacity)
{
	TYPE* data = malloc(sizeof(TYPE) * capacity);
	for (int i = 0; i < array->size; i++)
	{
		data[i] = array->data[i];
	}
	free(array->data);
	array->data = data;
	array->capacity = capacity;
}

static void init(DynamicArray* array, int capacity)
{
	assert(capacity > 0);
	array->data = NULL;
	array->size = 0;
	setCapacity(array, capacity);
}

DynamicArray* dyNew(int capacity)
{
	DynamicArray* array = malloc(sizeof(DynamicArray));
	init(array, capacity);
	return array;
}

void dyDelete(DynamicArray* array)
{
	free(array->data);
	free(array);
}

void dyAdd(DynamicArray* array, TYPE value)
{
	if (array->size >= array->capacity)
	{
		setCapacity(array, 2 * array->capacity);
	}
	array->data[array->size] = value;
	array->size++;
}

void dyAddAt(DynamicArray* array, TYPE value, int position)
{
	assert(position <= array->size);
	dyAdd(array, value);
	for (int i = array->size - 1; i > position; i--)
	{
		dySwap(array, i, i - 1);
	}
}

void dyPut(DynamicArray* array, TYPE value, int position)
{
	assert(position < array->size);
	array->data[position] = value;
}

void dyRemoveAt(DynamicArray* array, int position)
{
	assert(position < array->size);
	for (int i = position; i < array->size - 1; i++)
	{
		array->data[position] = array->data[position + 1];
	}
	array->size--;
}

TYPE dyGet(DynamicArray* array, int position)
{
	assert(position < array->size);
	return array->data[position];
}

int dySize(DynamicArray* array)
{
	return array->size;
}

void dySwap(DynamicArray* array, int position1, int position2)
{
	assert(position1 < array->size);
	assert(position2 < array->size);
	TYPE temp = array->data[position1];
	array->data[position1] = array->data[position2];
	array->data[position2] = temp;
}

// --- Stack ---

void dyStackPush(DynamicArray* stack, TYPE value)
{
	dyAdd(stack, value);
}

void dyStackPop(DynamicArray* stack)
{
	dyRemoveAt(stack, stack->size - 1);
}

TYPE dyStackTop(DynamicArray* stack)
{
	return dyGet(stack, stack->size - 1);
}

int dyStackIsEmpty(DynamicArray* stack)
{
	return stack->size == 0;
}

// --- Bag ---

static int findFirst(DynamicArray* array, TYPE value, compareFunction compare)
{
	for (int i = 0; i < array->size; i++)
	{
		if (compare(value, array->data[i]) == 0)
		{
			return i;
		}
	}
	return -1;
}

void dyBagAdd(DynamicArray* bag, TYPE value)
{
	dyAdd(bag, value);
}

void dyBagRemove(DynamicArray* bag, TYPE value, compareFunction compare)
{
	int position = findFirst(bag, value, compare);
	if (position != -1)
	{
		dyRemoveAt(bag, position);
	}
}

int dyBagContains(DynamicArray* bag, TYPE value, compareFunction compare)
{
	return findFirst(bag, value, compare) != -1;
}

// --- Ordered bag ---

static int binarySearch(DynamicArray* array, TYPE value, compareFunction compare)
{
	int low = 0;
	int high = array->size - 1;
	while (low <= high)
	{
		int middle = (low + high) / 2;
		if (compare(value, array->data[middle]) < 0)
		{
			high = middle - 1;
		}
		else if (compare(value, array->data[middle]) > 0)
		{
			low = middle + 1;
		}
		else
		{
			return middle;
		}
	}
	return low;
}

void dyOrderedAdd(DynamicArray* bag, TYPE value, compareFunction compare)
{
	int position = binarySearch(bag, value, compare);
	dyAddAt(bag, value, position);
}

void dyOrderedRemove(DynamicArray* bag, TYPE value, compareFunction compare)
{
	int position = binarySearch(bag, value, compare);
	if (compare(value, bag->data[position]) == 0)
	{
		dyRemoveAt(bag, position);
	}
}

int dyOrderedContains(DynamicArray* bag, TYPE value, compareFunction compare)
{
	int position = binarySearch(bag, value, compare);
	return compare(value, dyGet(bag, position)) == 0;
}

// --- Heap ---

/**
* Adjusts heap to maintain the heap property.
* @param heap
* @param last  index to adjust up to.
* @param position  index where adjustment starts.
* @param compare  pointer to compare function.
*/
void adjustHeap(DynamicArray* heap, int last, int position, compareFunction compare)
{// FIXME: implement

	assert(heap != NULL);
	assert(last <= dySize(heap));

	//calculate left and right children
	int leftChild = 2 * position + 1;
	int rightChild = 2 * position + 2;
	int smallestChild;

	//if right less than max, we have two children
	if (rightChild < last) {
		//get index of smallest child
		if (compare(dyGet(heap, leftChild), dyGet(heap, rightChild)) == -1 || compare(dyGet(heap, leftChild), dyGet(heap, rightChild)) == 0) {
			smallestChild = leftChild;
		}
		else if (compare(dyGet(heap, leftChild), dyGet(heap, rightChild)) == 1) {
			smallestChild = rightChild;
		}

		//compare smallest child to pos
		//if necessary, swap and call adjustHeap starting at max, min index
		if (compare(dyGet(heap, smallestChild), dyGet(heap, position)) == -1) {
			dySwap(heap, smallestChild, position);
		}
		adjustHeap(heap, last, smallestChild, compare);

	}//else if left is less than max, have only one child
	else if (leftChild < last) {
		smallestChild = leftChild; //child must be left

	//compare child to parent
	//if necessary, swap and call adjustHeap starting at max, left index
		if (compare(dyGet(heap, smallestChild), dyGet(heap, position)) == -1) {
			dySwap(heap, smallestChild, position);
		}
		adjustHeap(heap, last, smallestChild, compare);
	}

	//else no children, we are at bottom and done

}

/**
* Builds a valid heap from an arbitrary array.
* @param heap  array with elements in any order.
* @param compare  pointer to compare function.
*/
void buildHeap(DynamicArray* heap, compareFunction compare)
{// FIXME: implement


	assert(heap != NULL);

 //all leaves are proper heaps
 //index of first non-leaf node = size of array/2 - 1
 //use adjust heap of subtree to make it a proper heap

 //find the last non-leaf node going from left to right
	int nodeBuild = dySize(heap) / 2 - 1;

	// int minNode = dyHeapGetMin(heap);
	//adjust heap from it to max
	//decrement i and repeat until you process the root
	for (int i = nodeBuild; i >= 0; i--) {
		adjustHeap(heap, dySize(heap), i, compare);
	}
}

/**
* Adds an element to the heap.
* @param heap
* @param value  value to be added to heap.
* @param compare  pointer to compare function.
*/
void dyHeapAdd(DynamicArray* heap, TYPE value, compareFunction compare)
{// FIXME: implement

	assert(heap != NULL);

 //calculate next open spot
	int pos = dySize(heap);
        

	//add value into new pos
	dyAdd(heap, value);

	/* While not at the first node, calculate parent, compare value of
	* new node with the parent, if it greater than the parent, swap
	* the two nodes. Set the node as the new parents. Iterate until done.
	*/
	while (pos != 0) {
		int parent = (pos - 1) / 2;
		if (compare(dyGet(heap, pos), dyGet(heap, parent)) == -1) {
			dySwap(heap, parent, pos);
			pos = parent;
		}
		else return;
	}
}

/**
* Removes the first element, which has the min priority, form the heap.
* @param heap
* @param compare  pointer to the compare function.
*/
void dyHeapRemoveMin(DynamicArray* heap, compareFunction compare)
{// FIXME: implement


	assert(heap != NULL);
	assert(dySize(heap) > 0);

	//remove the last element (size of dyn array minus 1)
	int last = dySize(heap) - 1;

	//put the last element at the root location
	//also removes min node
	dyPut(heap, heap->data[last], 0);

	dyRemoveAt(heap, last);
	//heap->size--;
	//percolate down from index 0, up to but not including last
	adjustHeap(heap, heap->size, 0, compare);
}

/**
* Returns the first element, which has the min priority, from the heap.
* @param heap
* @return  Element at the top of the heap.
*/
TYPE dyHeapGetMin(DynamicArray* heap)
{// FIXME: implement

	assert(heap != NULL);
	return (dyGet(heap, 0));
}

/**
* Sorts arbitrary array in-place.
* @param heap  array with elements in arbitrary order.
* @param compare  pointer to the compare function.
*/
void dyHeapSort(DynamicArray* heap, compareFunction compare)
{// FIXME: implement

	assert(heap != NULL);

 //build heap - turn arbitrary array into a heap
	buildHeap(heap, compare);

	int last = dySize(heap) - 1;
	//swap first and last elements


	//adjust heap from 0 to the last
	//repeat - decrement last each time through
	for (int i = last; i > 0; --i) {
		dySwap(heap, i, 0);
		adjustHeap(heap, i, 0, compare);
	}

}

// --- Iterator ---

DynamicArrayIterator* dyIteratorNew(DynamicArray* array)
{
	DynamicArrayIterator* iterator = malloc(sizeof(DynamicArrayIterator));
	iterator->array = array;
	iterator->current = 0;
	return iterator;
}

void dyIteratorDelete(DynamicArrayIterator* iterator)
{
	free(iterator);
}

int dyIteratorHasNext(DynamicArrayIterator* iterator)
{
	return iterator->current < iterator->array->size;
}

TYPE dyIteratorNext(DynamicArrayIterator* iterator)
{
	TYPE value = dyGet(iterator->array, iterator->current);
	iterator->current++;
	return value;
}

void dyIteratorRemove(DynamicArrayIterator* iterator)
{
	iterator->current--;
	dyRemoveAt(iterator->array, iterator->current);
}

// --- Utility ---

void dyPrint(DynamicArray* array, printFunction print)
{
	printf("\nsize: %d\ncapacity: %d\n[\n", array->size, array->capacity);
	for (int i = 0; i < array->size; i++)
	{
		printf("%d : ", i);
		print(array->data[i]);
		printf("\n");
	}
	printf("]\n");
}

void dyCopy(DynamicArray* source, DynamicArray* destination)
{
	free(destination->data);
	init(destination, source->capacity);
	for (int i = 0; i < source->size; i++)
	{
		destination->data[i] = source->data[i];
	}
	destination->size = source->size;
}