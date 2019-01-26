#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

vector<int> merge(vector<int> left, vector<int> right)
{
   vector<int> sorted;
   
   //while either side is greater than 0
	while ((int)left.size() > 0 || (int)right.size() > 0)
	{
		if ((int)left.size() > 0 && (int)right.size() > 0) //if neither vector are empty
      	{
         	if ((int)left.front() <= (int)right.front()) 
        	{
         	sorted.push_back((int)left.front()); //push left element to sorted vector
            left.erase(left.begin()); //erase from left vector
        	} 
  		 	else 
  			{
            sorted.push_back((int)right.front()); //push right element to sorted vector
            right.erase(right.begin()); //erase from right vector
        	}
      	}  //if right side is empty, push remaining elements of left vector to sorted vector
      else if ((int)left.size() > 0) 
      {
		for (int i = 0; i < (int)left.size(); i++)
		{
			sorted.push_back(left.at(i));
		}
            break; //done sorting
      }  //if left side is empty, push remaining elements of right vector to sorted vector
      else if ((int)right.size() > 0) 
      {
      	for (int i = 0; i < (int)right.size(); i++)
        {   
        	sorted.push_back(right.at(i));
        }
            break; //done sorting
      }
   }

   return sorted; 
}

vector<int> mergeSort(vector<int> unsorted)
{
	vector<int> left; 
	vector<int> right;
	vector<int> sorted;

	//base case - return if 0 or 1 as it is already sorted
	if(unsorted.size() <= 1)
		return unsorted;

	//find the middle term
	int middle = ((int)unsorted.size()+ 1) / 2;
 
 	//put the first half of the vector into the new left vector
  	for (int i = 0; i < middle; i++) 
  		{
  	    	left.push_back(unsorted.at(i));
   		}

   	//put the second half of the vector into the new right vector
   	for (int i = middle; i < (int)unsorted.size(); i++) 
   		{
      		right.push_back(unsorted.at(i));
   		}

   	//recursive section - divide and conquer!
   	left = mergeSort(left);
   	right = mergeSort(right);

   	//merge left and right vectors
   	sorted = merge(left, right);

   	//return sorted array
 	return sorted;
}

int main()
{
 
	vector<int> data;
    int x;
    ifstream dataFile;
    vector<int> unsorted;
    vector<int> sorted;
    
    //open file
    dataFile.open("data.txt");
    if (!dataFile) 
    {
        cout << "Unable to open file";
    }

    //create new file to write
    ofstream output("merge.out");

    if(!output.is_open())
    {
    	cout << "Unable to open merge.out file";
    }
    
    //add contents of dataFile to the data vector
    while (dataFile >> x) 
    {
       data.push_back(x);
    }
    
    dataFile.close();

    //while the data vector still elements, continue sorting
    while(data.size() > 0)
	{
 		int total = data.front(); //the first number of the vector indicating how many numbers to sort
		data.erase(data.begin()); //first number is not needed during sort

		//put number of values to be sorted in new unsorted vector and erase from original vector
		for(int i = 0; i < total; i++)
		{
			int value = data.front();
			unsorted.push_back(value);
			data.erase(data.begin());
		}

    //sort the data
	sorted = mergeSort(unsorted);  

			//write sorted values to file
		if(output.is_open())
		{
			for(int i = 0; i < sorted.size(); i++)
			{
				output << sorted.at(i) << " ";
			}
			output << endl;
		}

		//clear unneeded values from existing vectors
		unsorted.clear();
		sorted.clear();
	}
	output.close();
}