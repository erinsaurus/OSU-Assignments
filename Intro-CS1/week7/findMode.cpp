/****************************************************************************************************
 ** Author: Erin Alltop
 ** Date: 2/14/16
 ** Description: This program contains a function that takes an array as a parameter. The function
 ** first finds the number(s) in the array that have the highest frequency, and then returns the
 ** mode(s) of the array as a vector.
 ***************************************************************************************************/


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// This is the function protoype. It takes an array and the size of the array as parameters and
// returns the result of the function as a vector.

vector<int> findMode(int array[], int size);

// Main function for testing purposes. This is commented out of the final submission as instructed.
int main()
{
    
    
    int array[] = {1, 4, 6, 6, 6, 3, 5, 5, 5, 2};
    int size = 10;
    

    vector <int> result;
    
    // Call function and set 'result' to equal the output of the function.
    result = findMode(array, size);
    
    
    cout << "The mode of the array is\n";
    for (int i = 0; i< result.size(); i++)  // The vector must be looped through to display all of the results.
    {
        cout << result[i] << endl;          // Print out the results. result[i] is the vector for result.
        
    }
    
}

// findMode function. This takes an array and the size of an array as parameters and returns the results as a vector.
vector<int> findMode(int array[], int size)
{
    int currentFrequency = 0;       // This variable represents the frequency of the current number in array that is being evaluated in the loop.
    int maxFrequency = 0;           // This variable represents the highest frequency of a number discovered thus far in the loop.
    int currentNumber = 0;          // This variable represents the number from the array that is currently being evaluated in the loop.
                                    // All variables are initialized to 0.
    
    
    vector <int> result;               // Create vector that will contain the results of the function.
    
    
    sort(array, array + size);        // Sort the array in ascending order.
    
    
    for(int i = 0; i < size; i++)     // First iteration of the loop of the array that finds the number(s) with the highest frequency.
    {
        if(currentNumber != array[i])  // If the current number does not equal array[i] move on to next step.
            
        {
            currentNumber = array[i];  // Set current number to equal array[i]
            currentFrequency = 0;      // Reset frequency count to 0 for the next number to be tested.
            
        }
        
        else
        {
            currentFrequency++;       // Otherwise, advance count of frequency by 1.
        }
        
        if(currentFrequency > maxFrequency)  // If the frequency counter exceeds the max frequency, set the max frequency to equal the current frequency count.
            
        {
            maxFrequency = currentFrequency; // The max frequency is now the new highest frequency that we have found.
            
        }
    }
    
    for(int i = 0; i < size; i++)       // Loop through the array a second time to compare the frequencies against each other.
    {
        if(currentNumber != array[i])
            
        {
            currentNumber = array[i];
            currentFrequency = 0;
            
        }
        
        else
        {
            currentFrequency++;
        }
        
        
        if(currentFrequency == maxFrequency)  // If the current frequency of the number is equal to the max frequency (that we have already found in the first
                                              // loop, then push each number with that frequency to the vector.
        {
            
            result.push_back(currentNumber); // Push the results of the fuction to the vector. The currentNumber now represents the mode(s).
            
        }
        
    }

    
    sort(result.begin(), result.end()); // Sort the vector in ascending order.
    return result;                      // Return the results of the vector to the Main function.
    
}
