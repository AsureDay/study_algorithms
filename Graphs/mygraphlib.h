#pragma once
#include <vector>
#include <list>
#include <map>
#include <algorithm>
using namespace std;
class Vert
{
public:
	const int index;
	int color;
	Vert(int index,int data):index(index)
	{
		this->color = data;
	}	
};

struct MyGraph
{
	int num_vertexes;
	int num_edges;
	vector<Vert*> vert_list;
	map<Vert*, list<Vert*>> ways_to;
	MyGraph() : num_vertexes(0), num_edges(0),newindex(0) {}
	~MyGraph();//
	
	void addVert(int data);
	Vert* getVert(int index);
	
	void addEdge(int indexFrom, int  indexTo);
	
	void removeVert(Vert* v);
	void removeVert(int index);
	void removeEdge(int indexFrom, int  indexTo);

	
	void showWaysFrom(int index);

	bool haveCicles();

	int withoutThisUncicled_slow();
private:
	void color(char c);
	bool haveCicle(Vert* v);
	bool haveCicle_dontSeeThat(Vert* u, Vert* that);
	bool haveCicles_dontSeeThat(Vert* v);
	int getIndex(Vert* v);
	
	void addEdge(Vert* vertFrom, Vert* vertTo);
	void removeEdge(Vert* vertFrom, Vert* vertTo);

	int newindex;
	list<Vert*> notViseted;
};