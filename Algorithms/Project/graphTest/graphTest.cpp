#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>
using namespace std;

class AdjList
{
private:

    typedef pair<int, char> edge;
    unordered_map<char , list <edge> > adjList;

public:
    void createGraph();
    void printGraph();
    void test();
};

void createGraph()
{
    list<edge> A;
    A.push_back(make_pair(3, 'B'));
    A.push_back(make_pair(2, 'E'));

    list<edge> B; //B points nowhere

    list<edge> C;
    C.push_back(make_pair(1, 'A'));

    list<edge> D;
    D.push_back(make_pair(4, 'C'));

    list<edge> E;
    E.push_back(make_pair(4, 'D'));

    adjList['A'] = A;
    adjList['B'] = B;
    adjList['C'] = C;
    adjList['D'] = D;
    adjList['E'] = E;

}

void printGraph()
{
    for each (auto elem in adjList)
    {
        cout << elem.first << " -> ";

        for_each(elem.second.begin(), elem.second.end(), [](auto val) {

            cout << val.second << "(" << val.first << "), ";

        });

        cout << endl;
    }
}

void test()
{
    createGraph();
    printGraph();
}

int main()
{
	test();
}