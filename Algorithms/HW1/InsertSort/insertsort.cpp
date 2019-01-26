
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std; 

vector<int> insertionSort(vector<int> vec)
{
	int key;
	vector<int> sorted;

	//sorting the vector
	for(int i = 1; i < vec.size(); i++)
	{
		key = vec[i];
		int j = i - 1;

		while(j >= 0 && vec[j] > key)
		{
			vec[j + 1] = vec[j];
			j = j - 1;
		}
		vec[j + 1] = key;
	}

	//storing the results into the sorted vector
	for(int i = 0; i < vec.size(); i++)
	{
		sorted.push_back(vec.at(i));

	}	

	return sorted;	//return vector
}

void sortFile(vector<int> data, ofstream &output)
{
	vector<int> unsorted;
	vector<int> sorted;

	//continue through lines of vector until empty
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

		//new sorted vector
		sorted = insertionSort(unsorted);

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
}

int main(){

	vector<int> data;
    int x;
    ifstream dataFile;
    
    //open file
    dataFile.open("data.txt");
    if (!dataFile) 
    {
        cout << "Unable to open file";
    }

    //create new file to write
    ofstream output("insert.out");

    if(!output.is_open())
    {
    	cout << "Unable to open insert.out file";
    }
    
    //add contents of dataFile to the data vector
    while (dataFile >> x) 
    {
       data.push_back(x);
    }
    
    dataFile.close();

    //sort the data
	sortFile(data, output);  

	output.close();
}






