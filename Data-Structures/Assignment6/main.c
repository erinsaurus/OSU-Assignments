#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <assert.h>

/**
 * Allocates a string for the next word in the file and returns it. This string
 * is null terminated. Returns NULL after reaching the end of the file.
 * @param file
 * @return Allocated string or NULL.
 */
char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);
    while (1)
    {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')
        {
            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            word[length] = c;
            length++;
        }
        else if (length > 0 || c == EOF)
        {
            break;
        }
    }
    if (length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

/**
 * Prints the concordance of the given file and performance information. Uses
 * the file input1.txt by default or a file name specified as a command line
 * argument.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char** argv)
{
    // FIXME: implement
    const char* fileName = "input1.txt";
    if (argc > 1)
    {
        fileName = argv[1];
    }
    printf("Opening file: %s\n", fileName);
    printf("Before clock time\n");
    
    
    clock_t timer = clock();
    printf("After clock time\n");
    HashMap* map = hashMapNew(10);
    
    // --- Concordance code begins here ---
    // Be sure to free the word after you are done with it here.
    
    //open the file
    FILE* output_file;
    output_file = fopen(fileName, "r");
    
    printf("File has been opened");
	char buff[255];
	fscanf(output_file, "%s", buff);
	printf("File output: %s\n", buff);
    

    if(output_file != NULL){
        char* currKey = nextWord(output_file);
      
        while(currKey != NULL){
            if(hashMapContainsKey(map, currKey)){
                int numOcc = *(hashMapGet(map, currKey));
                numOcc++;
                hashMapPut(map, currKey, numOcc);
            }else{
                hashMapPut(map, currKey, 1);
            }
        }
        free(currKey);
        currKey = nextWord(output_file);
        
    } else {
        printf("\n%s is unable to be opened.\n", fileName);
    }
    
    
    //get the next work with getWord
    //if the word is already in the hash map, then increment its number of occurrences
    //otherwise, put the word in the hash map with a count of 1
    //free the word
    
    //close the file
//    fclose(output_file);
    
    char* word = nextWord(output_file);
    while(word != NULL){
        int numOcc = *(hashMapGet(map, word));
        printf("\n%s: %d", word, numOcc);
        word = nextWord(output_file);
    }
    
    // --- Concordance code ends here ---
    
    hashMapPrint(map);
    
    timer = clock() - timer;
    printf("\nRan in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    printf("Empty buckets: %d\n", hashMapEmptyBuckets(map));
    printf("Number of links: %d\n", hashMapSize(map));
    printf("Number of buckets: %d\n", hashMapCapacity(map));
    printf("Table load: %f\n", hashMapTableLoad(map));
    
    hashMapDelete(map);
    return 0;
}