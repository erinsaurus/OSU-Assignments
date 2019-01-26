/*
 * CS 261 Data Structures
 * Assignment 6
 * Name: Erin Alltop
 * Date: 3/8/17
 */

#include "hashMap.h"
#include "CuTest.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

int hashFunction1(const char* key)
{
    int r = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        r += key[i];
    }
    return r;
}

int hashFunction2(const char* key)
{
    int r = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        r += (i + 1) * key[i];
    }
    return r;
}

/**
 * Creates a new hash table link with a copy of the key string.
 * @param key Key string to copy in the link.
 * @param value Value to set in the link.
 * @param next Pointer to set as the link's next.
 * @return Hash table link allocated on the heap.
 */
HashLink* hashLinkNew(const char* key, int value, HashLink* next)
{
    HashLink* link = malloc(sizeof(HashLink));
    link->key = malloc(sizeof(char) * (strlen(key) + 1));
    strcpy(link->key, key);
    link->value = value;
    link->next = next;
    return link;
}

/**
 * Free the allocated memory for a hash table link created with hashLinkNew.
 * @param link
 */
static void hashLinkDelete(HashLink* link)
{
    free(link->key);
    free(link);
}

/**
 * Initializes a hash table map, allocating memory for a link pointer table with
 * the given number of buckets.
 * @param map
 * @param capacity The number of table buckets.
 */
void hashMapInit(HashMap* map, int capacity)
{
    map->capacity = capacity;
    map->size = 0;
    map->table = malloc(sizeof(HashLink*) * capacity);
    for (int i = 0; i < capacity; i++)
    {
        map->table[i] = NULL;
    }
}

/**
 * Removes all links in the map and frees all allocated memory. You can use
 * hashLinkDelete to free the links.
 * @param map
 */
void hashMapCleanUp(HashMap* map)
{// FIXME: implement
    
    HashLink *current;
    HashLink *next;
    
    //loop through each link in the map
    for (int i = 0; i < hashMapCapacity(map); i++){
        current = map->table[i];
        
        //while link is not null, set it to next, delete link
        while(current != NULL){
            next = current->next;
           hashLinkDelete(current);
           current = next;
        }
    }
    
    //free table and set new sizes to 0
    free(map->table);
    map->size = 0;
    map->capacity = 0;
    
    //for each bucket, delete each key/value pair
    //increment to next bucket
}

/**
 * Creates a hash table map, allocating memory for a link pointer table with
 * the given number of buckets.
 * @param capacity The number of buckets.
 * @return The allocated map.
 */
HashMap* hashMapNew(int capacity)
{
    HashMap* map = malloc(sizeof(HashMap));
    hashMapInit(map, capacity);
    return map;
}

/**
 * Removes all links in the map and frees all allocated memory, including the
 * map itself.
 * @param map
 */
void hashMapDelete(HashMap* map)
{
    hashMapCleanUp(map);
    free(map);
}

/**
 * Returns a pointer to the value of the link with the given key. Returns NULL
 * if no link with that key is in the table.
 * 
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 * 
 * @param map
 * @param key
 * @return Link value or NULL if no matching link.
 */
int* hashMapGet(HashMap* map, const char* key)
{// FIXME: implement

    int hashIndex = HASH_FUNCTION(key) % hashMapCapacity(map);
     if (hashIndex < 0) {hashIndex += hashMapCapacity(map);}

    HashLink* current = map->table[hashIndex];

    while (current != NULL) {
       if (strcmp(current->key, key) == 0) {
          return &(current->value);
       }
       current = current->next;
    }     

    return NULL;
}

/**
 * Resizes the hash table to have a number of buckets equal to the given
 * capacity. After allocating the new table, all of the links need to be
 * rehashed into it because the capacity has changed.
 * 
 * Remember to free the old table and any old links if you use hashMapPut to
 * rehash them.
 * 
 * @param map
 * @param capacity The new number of buckets.
 */
void resizeTable(HashMap* map, int capacity)
{// FIXME: implement

    HashMap* temp = hashMapNew(capacity); //create a temp table

    //copy values into new table
    for (int i = 0; i < hashMapCapacity(map); i++) {
        HashLink* link = map->table[i];

        while (link) {
           hashMapPut(temp, link->key, link->value);
           link = link->next;
        }
    }

    //delete old table and set map to new values and temp table
    hashMapCleanUp(map);
    map->table = temp->table;
    map->size = temp->size;
    map->capacity = temp->capacity;

    //delete temp table
    temp->table = NULL;
    free(temp);
}

/**
 * Updates the given key-value pair in the hash table. If a link with the given
 * key already exists, this will just update the value. Otherwise, it will
 * create a new link with the given key and value and add it to the table
 * bucket's linked list. You can use hashLinkNew to create the link.
 * 
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 * 
 * @param map
 * @param key
 * @param value
 */
void hashMapPut(HashMap* map, const char* key, int value)
{// FIXME: implement

    //set index - make sure it's positive
    int hashIndex = HASH_FUNCTION(key) % hashMapCapacity(map);
    if (hashIndex < 0) {hashIndex += hashMapCapacity(map);}

    //if map contains key, update value with new value
    if (hashMapContainsKey(map, key)) {
        int* oldValue = hashMapGet(map, key);
        (*oldValue) += value;

    } else {  //if map does not contain key, search to find a new spot

        //if the current index is NULL, insert new link - O(1) complexity
        if (map->table[hashIndex] == NULL) {
           HashLink* new = hashLinkNew(key, value, NULL);
           map->table[hashIndex] = new;
         
        } else { //if crrent link is not NULL, set cur pointer to index
           HashLink* current = map->table[hashIndex];
          
           while(current->next) { //search until you find an index that is NULL
              current = current->next;
           }
           //create a new link and set new link to the first empty link - O(n) complexity
            HashLink* new = hashLinkNew(key, value, NULL);
            current->next = new;
        }
          //increment size of map  
          map->size++;
    }
    //resize if load ratio is greater than max load
    if (hashMapTableLoad(map) >= MAX_TABLE_LOAD) {
        resizeTable(map, 2 * hashMapCapacity(map));
    }
}

/**
 * Removes and frees the link with the given key from the table. If no such link
 * exists, this does nothing. Remember to search the entire linked list at the
 * bucket. You can use hashLinkDelete to free the link.
 * @param map
 * @param key
 */
void hashMapRemove(HashMap* map, const char* key)
{// FIXME: implement

    assert(map != 0);
    assert(key != 0);


    int hashIndex = HASH_FUNCTION(key) % hashMapCapacity(map);
    if (hashIndex < 0) {hashIndex += hashMapCapacity(map);}

    HashLink* current = map->table[hashIndex];
    HashLink* prev = NULL;

    if(!hashMapContainsKey(map,key)){
        //do nothing
        return;

    } else if(hashMapContainsKey(map, key)){

        if (current != NULL) {

            if (strcmp(current->key, key) == 0) {
                map->table[hashIndex] = current->next;

        } else {

            while (strcmp(current->key, key) != 0) {
                prev = current;
                current = current->next;
            }

            if (prev != NULL) {
                prev->next = current->next;
            }
        }
        hashLinkDelete(current);
        map->size--;
    }
}

}

/**
 * Returns 1 if a link with the given key is in the table and 0 otherwise.
 * 
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 * 
 * @param map
 * @param key
 * @return 1 if the key is found, 0 otherwise.
 */
int hashMapContainsKey(HashMap* map, const char* key)
{// FIXME: implement
    
    int hashIndex = HASH_FUNCTION(key) % hashMapCapacity(map);
    if (hashIndex < 0) {hashIndex += hashMapCapacity(map);}

    HashLink* current = map->table[hashIndex];

    while(current != NULL) {
       if (strcmp(current->key, key) == 0) {
          return 1;
       }
       current = current->next;
    }    

    return 0;
}

/**
 * Returns the number of links in the table.
 * @param map
 * @return Number of links in the table.
 */
int hashMapSize(HashMap* map)
{// FIXME: implement

    return map->size;
}

/**
 * Returns the number of buckets in the table.
 * @param map
 * @return Number of buckets in the table.
 */
int hashMapCapacity(HashMap* map)
{// FIXME: implement

    return map->capacity;
}

/**
 * Returns the number of table buckets without any links.
 * @param map
 * @return Number of empty buckets.
 */
int hashMapEmptyBuckets(HashMap* map)
{ // FIXME: implement

    //can check for NULL because pointers are stored, not direct values
    int empty = 0; 
    for (int i = 0; i < hashMapCapacity(map); i++) {
       if (map->table[i] == NULL) {
          empty++;
       }
    }

    return empty;
}

/**
 * Returns the ratio of (number of links) / (number of buckets) in the table.
 * Remember that the buckets are linked lists, so this ratio tells you nothing
 * about the number of empty buckets. Remember also that the load is a floating
 * point number, so don't do integer division.
 * @param map
 * @return Table load.
 */
float hashMapTableLoad(HashMap* map)
{// FIXME: implement

    float cap = (float) hashMapCapacity(map);
    float size = (float) hashMapSize(map);

    return size / cap;
}

/**
 * Prints all the links in each of the buckets in the table.
 * @param map
 */
void hashMapPrint(HashMap* map)
{
    for (int i = 0; i < map->capacity; i++)
    {
        HashLink* link = map->table[i];
        if (link != NULL)
        {
            printf("\nBucket %i ->", i);
            while (link != NULL)
            {
                printf("(%s: %d) ->", link->key, link->value);
                link = link->next;
            }
        }
    }
    printf("\n");
}