
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

vector<city> notVisited;
vector<city> visited;
int totalDistance;


//equation to find the distance between coordinates of two cities
int findDistance(city a, city b)
{
	int distance = (sqrt( pow((float)a.x - b.x, 2) + pow((float)a.y - b.y, 2 ) ) );
	return distance;
}

//function to find the shortest edge between current vertex and remaining unvisited vertices
//returns the vertex with the shortest edge
city shortestEdge(city currVer)
{
	city closestCity;
	int testEdge;
	int shortestEdge = 10000000; //arbitrary large inital value
	int closestCityIndex;

	for(int i = 0; i < notVisited.size(); i++) //loop through vector of cities not yet visited
	{
		testEdge = findDistance(currVer, notVisited[i]); //check the distance between current vertex and test vertex
		//	cout << "Distance between " << currVer.id  << " and " << notVisited[i].id << " is: " << testEdge << endl;

		//if the distance from current vertex to test vertex is shorter than the current shortest edge, set it to be the shortest edge
		if (testEdge < shortestEdge) 
		{
			shortestEdge = testEdge;
			closestCity = notVisited[i]; //set to be current closest city
			closestCityIndex = i; //find the index so it can be removed from notVisited vector
		}
	}

//	cout << closestCity.id << " selected!" << endl;
	totalDistance += testEdge;
//	cout << "Distance between " << currVer.id  << " and " << notVisited[closestCityIndex].id << " is: " << testEdge << endl;
	notVisited.erase(notVisited.begin() + closestCityIndex); //remove closest city from notVisited vector
	visited.push_back(closestCity); //add new vertex to visited vector

	return closestCity;
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
					notVisited.push_back(newCity);
				}

				ofstream outFile(outName.c_str());
				if(outFile.is_open())
				{
					city startCity = notVisited.front(); //set first city in input to start city
					visited.push_back(startCity);		//add to visited vector
					notVisited.erase(notVisited.begin());	//erase from notVisited vector

					city nextCity = shortestEdge(startCity); //get closest edge to start city

					/* while cities remain in notVisited vector, find the nearest neighbor and add
					 * the nearest neighbor to the visited vector
					 */ 
					while(!notVisited.empty())
					{
						nextCity = shortestEdge(nextCity); //get closest city to current city and set it to nextCity

					}

					cout << "Total Distance: " << totalDistance << endl;
					outFile << totalDistance << endl;
					cout << "Cities in order: " << endl;
					for(int i = 0; i < visited.size(); i++)
					{
						outFile << visited[i].id << endl;
						cout << visited[i].id << endl;
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
		notVisited.clear();
		visited.clear();
				
		}
}

}