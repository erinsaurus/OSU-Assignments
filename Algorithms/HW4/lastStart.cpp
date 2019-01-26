#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

//class of Activitiy objects
class Activity
{
	
public:
	int name;
	int start;
	int finish;
	
	void setValues(int Name, int Start, int Finish)
	{
		name = Name;
		start = Start;
		finish = Finish;
	}

	//member functions
	int getStart() { return start; }
	int getFinish() { return finish; }
	int getName() { return name; }
	
};

//struct for sorting
struct sortActivities
{
	bool operator() (const Activity& a, const Activity& b)
	{
		return a.start > b.start;
	}
};

void lastStart(vector<Activity> activities)
{

	vector<int> temp; //temp vector for printing
	int i = 0;
	int total = 1;
	temp.push_back(activities[i].name); //the first activitiy is selected

	/* For the last to start algorithm, we are comparing the finish time of the
	 * next activitiy to see if it interferes with the start time of the activity
	 * we are examining. If it is greater then it is not compatible. If not, add to 
	 * selected activities list.
	 */
	for (int j = 1; j < activities.size(); j++)
	{
		if(activities[j].finish <= activities[i].start)
		{
			i = j;
			total++;
			temp.push_back(activities[j].name);
		}
	}
	cout << endl;
	cout << "Number of activities selected = " << total << endl;
	cout << "Activities: ";

	reverse(temp.begin(), temp.end()); //reversing elements of vector because they are inserted from the back
	
	for(int y = 0; y < temp.size(); y++)
	{
		cout << temp.at(y) << " ";
	}
	cout << endl;
}
	

int main()
{
 
	vector<int> data;
	vector<Activity> activities;
	int x;
    ifstream dataFile;
    
    //open file
    dataFile.open("act.txt");
    if (!dataFile) 
    {
        cout << "Unable to open file";
    }

   //adding elements to our data vector
   while(dataFile >> x)
   {
   		data.push_back(x);
   }

	dataFile.close(); //close file

	int set = 1;

	while(data.size() > 0)
	{
		int numActivities = data.front(); //assign first value to number of activities
		data.erase(data.begin()); //erase first value as it is no longer needed
		cout << endl;
		cout << "Set " << set;
		set++;

		for(int i = 0; i < numActivities; i++) //for the next number of activities
		{
			Activity activity;	//create a new Activitiy object and assign its elements
			activity.setValues(data[0], data[1], data[2]);
			activities.push_back(activity);

			for(int j = 0; j < 3; j++)
			{
				data.erase(data.begin());
			}

		}

		//sort vector by start time
		sort(activities.begin(), activities.end(), sortActivities());
		lastStart(activities);
		activities.clear();
	}
	}
