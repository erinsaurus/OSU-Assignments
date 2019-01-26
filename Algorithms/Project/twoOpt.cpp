#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
using namespace std; 

struct city
{
	int id;
	int x; //x-coordinate
	int y; //y-coordinate
};

vector<city> origRoute;
vector<city> newRoute;
int totalDistance;


//equation to find the distance between coordinates of two cities
int findDistance(city a, city b)
{
	int distance = (sqrt( pow((float)a.x - b.x, 2) + pow((float)a.y - b.y, 2 ) ) );
	return distance;
}

int findTotalDistance(vector<city> route)
{
	int routeTotalDistance;
	int currDist;

	for(int i = 0; i < route.size() - 1; i++)
	{
		currDist = findDistance(route[i], route[i+1]);
		routeTotalDistance += currDist;
	}

	//cout << "Total Distance from findTotalDistance function: " << routeTotalDistance << endl;
	return routeTotalDistance;
}

vector<city> optSwap(vector<city> existingRoute, int front, int back)
{
	int size = existingRoute.size();
	vector<city> newRoute = existingRoute;

	for(int i = 0; i < front - 1; i++) // 1. take route[1] to route[i-1] and add them in order to new_route
	{
		newRoute[i] = existingRoute[i];
	}

	int dec = 0;

	for(int i = front; i <= back; i++) //  2. take route[i] to route[k] and add them in reverse order to new_route
	{
		newRoute[i] = existingRoute[back - dec];
		dec++;
	}

	for(int i = back + 1; i < size; i++) //  3. take route[k+1] to end and add them in order to new_route
	{
		newRoute[i] = existingRoute[i];
	}

	return newRoute; // return new_route;
}


vector<city> twoSwap(vector<city> existingRoute)
{
	int size = existingRoute.size();
	bool improve = false;

	vector<city> solution = existingRoute;

	while(!improve) //while true, keep going
	{
		int bestDistance = findTotalDistance(solution); //first best distance
		int newDistance;

		for(int i = 0; i < size - 1; i++) 
		{
			for(int j = i + 1; j < size; j++)
			{
				vector<city> newTour = optSwap(solution, i, j);
				newDistance = findTotalDistance(newTour);

				if(newDistance < bestDistance)
				{
					improve = false;
					solution = newTour;
					bestDistance = newDistance;
				}

				//cout << "Found an improvement! " << endl;
			
			}
		}

		improve = true;
	}

/*	cout << "Solution within twoSwap function: " << endl;
	for(int i = 0; i < solution.size(); i++)
	{
		cout << solution[i].id << endl;
	}*/

	return solution;
}





int main(int argc, char* argv[])
{
	int id, x, y;

	//open input and output files
	if(argc > 1)
	{	
		for(int i = 1; i < argc; i++) //loop through as many input files as given on command line
		{
			//open file
			ifstream inFile(argv[i]);
			if(inFile.is_open())
			{
				string outName = string(argv[i]) + string(".tour"); //find output file name
				while(inFile >> id >> x >> y) //add data to notVisited vector
				{
					city newCity = {id, x, y};
					origRoute.push_back(newCity);
				}

				ofstream outFile(outName.c_str());
				if(outFile.is_open())
				{
					
					cout << "Distance of original route: " << findTotalDistance(origRoute) << endl;
					newRoute = twoSwap(origRoute);
					
					totalDistance = findTotalDistance(newRoute);
					cout << "Total Distance: " << totalDistance << endl;
					outFile << totalDistance << endl;
					cout << "Cities in order: " << endl;
					for(int i = 0; i < newRoute.size(); i++)
					{
						outFile << newRoute[i].id << endl;
						cout << newRoute[i].id << endl;
					}

				}
				else 
				{
					cout << "Unable to open output file." << endl;
				}
			}
			else
			{
				cout << "Unable to open input file." << endl; 
			}

		//clear vectors for use with next file given
		origRoute.clear();
		newRoute.clear();
				
		}
}

}