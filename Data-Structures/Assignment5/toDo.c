/*
 * CS 261 Assignment 5
 * Name: Erin Alltop
 * Date: 3/1/17
 */

#include "dynamicArray.h"
#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Loads into heap a list from a file with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listLoad(DynamicArray* heap, FILE* file)
{
    const int FORMAT_LENGTH = 256;
    char format[FORMAT_LENGTH];
    snprintf(format, FORMAT_LENGTH, "%%d, %%%d[^\n]", TASK_NAME_SIZE);
    
    Task temp;
    while (fscanf(file, format, &temp.priority, &temp.name) == 2)
    {
        dyHeapAdd(heap, taskNew(temp.priority, temp.name), taskCompare);
    }
}

/**
 * Writes to a file all tasks in heap with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listSave(DynamicArray* heap, FILE* file)
{
    for (int i = 0; i < dySize(heap); i++)
    {
        Task* task = dyGet(heap, i);
        fprintf(file, "%d, %s\n", task->priority, task->name);
    }
}

/**
 * Prints every task in heap.
 * @param heap
 */
void listPrint(DynamicArray* heap)
{
    DynamicArray* temp = dyNew(1);
    dyCopy(heap, temp);
     while (dySize(temp) > 0)
    {
        Task* task = dyHeapGetMin(temp);
        printf("\n");
        taskPrint(task);
        printf("\n");
        dyHeapRemoveMin(temp, taskCompare);
    }
    dyDelete(temp);
}

/**
 * Handles the given command.
 * @param list
 * @param command
 */
void handleCommand(DynamicArray* list, char command)
{ // FIXME: Implement
    
    /* l = load list from a file
     * s = save the list to a file
     * a = add a new task to the list
     * g = get the first task from the list
     * r = remove the first task from the list
     * p = print the list
     * e = exit the program
     */

    Task* newTask;
    Task* ftask;
    FILE* output_file;
    FILE* save_file;
   
    
    switch(command){
        case 'l':{
         //load list from a file  
            char filename[256];
            printf("\nPlease enter the filename: ");
            scanf("%[^\t\n]s", filename);
            getchar(); //eat the last char
            output_file = fopen(filename, "r"); //open file
            if (output_file == NULL) {
                fprintf(stderr, "\nCannot open %s\n\n", filename);
            }
            else{ //load the file
                listLoad(list, output_file);}
            
              break;
        }
        case 's':{
        //save the list to a file
            char sfile[256];
            printf("\nPlease enter the filename: ");
            scanf("%[^\t\n]s", sfile);
            getchar(); //eat the last char
            save_file = fopen(sfile, "w"); //overwrite the file/or make new
            listSave(list, save_file); //save file
              break;
        }
        case 'a':{
        //add a new task to the list
            int priority = 0;
            char name[256];
         
            printf("\nPlease enter the task description: ");
            scanf("%[^\t\n]s", name);
            
            printf("\nPlease enter the task priority (0-999): ");
            scanf("%i", &priority);
            getchar(); //eat the last char
            
            newTask = taskNew(priority, name); //create a new task
 
            dyHeapAdd(list, newTask, taskCompare); //add the new task to the heap
            
            printf("\nThe task '%s' has been added to your to-do-list.", newTask->name);
            
            break;
        }
        case 'g':{
        //get the first task from the list
            if(dySize(list) > 0){
            ftask = dyHeapGetMin(list); //first task is the min
            printf("\nYour first task is: %s", ftask->name);
            }
            else{
                printf("\nYour to-do list is empty!");
            }
              break;
        }
        case 'r':{
        //remove the first task from the list
            if(dySize(list) > 0){
                ftask = dyHeapGetMin(list); //first task is the min
                //print statement first and then remove
            printf("\nYour first task '%s' has been removed from the list.", ftask->name);
            dyHeapRemoveMin(list, taskCompare); //remove the min
            }
            else
                printf("\nYour to-do list is empty!");
              break;
        }
        case 'p':{
        //print the list
            if(dySize(list) <= 0){
                printf("\nYour to-do list is empty!");
            }
            else{
            listPrint(list);} //print list
              break;
        }
    }
}

int main()
{
    // Implement
    printf("\n\n** TO-DO LIST APPLICATION **\n\n");
    DynamicArray* list = dyNew(8);
    char command = ' ';
    do
    {
        printf("\n\nPress:\n"
               "'l' to load to-do list from a file\n"
               "'s' to save to-do list to a file\n"
               "'a' to add a new task\n"
               "'g' to get the first task\n"
               "'r' to remove the first task\n"
               "'p' to print the list\n"
               "'e' to exit the program\n"
        );
        command = getchar();
        // Eat newlines
        while (getchar() != '\n');
        handleCommand(list, command);
    }
    while (command != 'e');
 /* free dynamically allocated List pointers in array to avoid memory leaks */
         /* Fix it */
    
    while(dySize(list) > 0){
        Task* temp = dyHeapGetMin(list);
        dyHeapRemoveMin(list, taskCompare);
        free(temp);
    }

    dyDelete(list);
    return 0;
}