#include "mygraphlib.h"
#include "iostream"

MyGraph::~MyGraph()
{
	this->ways_from.clear();
	this->vert_list.clear();
}


void MyGraph::addVert(int data)
{
	vert_list.push_back(new Vert(newindex, data));
	num_vertexes++;
	newindex++;
}

void MyGraph::addEdge(int indexFrom, int indexTo)
{
	this->addEdge(getVert(indexFrom), getVert(indexTo));
}

void MyGraph::removeVert(Vert* v)
{
	for (vector<Vert*>::iterator i = vert_list.begin(); i != vert_list.end(); ++i)
	{
		for (list<Vert*>::iterator j = ways_from[*i].begin(); j != ways_from[*i].end(); ++j)
		{
			if (*j == v)
			{
				ways_from[*i].erase(j);
				//ways_from[*i].remove(*j);
				break;
			}
		}
	}
	ways_from[v].clear();
}

void MyGraph::removeVert(int index)
{
	this->removeVert(this->getVert(index));
}

void MyGraph::removeEdge(int indexFrom, int indexTo)
{
	this->removeEdge(this->getVert(indexFrom), this->getVert(indexTo));
}

void MyGraph::showWaysFrom(int index)
{
	for (list<Vert*>::iterator i = ways_from[getVert(index)].begin(); i != ways_from[getVert(index)].end(); ++i)
	{
		cout << getIndex(*i) << "\t";
	}
	cout << endl;
}



bool MyGraph::haveCicle_dontSeeThat(Vert* v, Vert* that)
{
	v->color = 'g';
	notViseted.remove(v);
	for (auto item = ways_from[v].begin(); item != ways_from[v].end(); ++item)
	{
		Vert* u = *item;
		if (u == that) continue;
		if (u->color == 'g')
			return true;
		if (u->color == 'b')
			return false;
		if (u->color == 'w')
			if(haveCicle_dontSeeThat(*item, that)) return true;
	}
	v->color = 'b';
	return false;
}
bool MyGraph::haveCicles_dontSeeThat(Vert* v)
{

	copy(vert_list.begin(), vert_list.end(), back_inserter(notViseted));
	bool res = 0;
	Vert* item = v;
	while (1)
	{
		this->color('w');
		res = res || haveCicle_dontSeeThat(item, v);
		if (res) {
			notViseted.clear();
			return true;
		}
		if (notViseted.size() == 0) {
			notViseted.clear();
			return false;
		}
		item = notViseted.back();
	}

}
int MyGraph::withoutThisUncicled_slow()
{
	if (!haveCicles()) return INT32_MIN+1;

	for (auto i = vert_list.begin(); i != vert_list.end(); ++i)
	{
		if (!haveCicles_dontSeeThat(*i)) return (*i)->index;
	}
	return INT32_MIN;
}

void MyGraph::color(char c)
{
	for (vector<Vert*>::iterator i = vert_list.begin(); i != vert_list.end(); ++i)
	{
		Vert* v = *i;
		v->color = c;
	}
}

bool MyGraph::haveCicles()
{
	copy(vert_list.begin(), vert_list.end(), back_inserter(notViseted));

	bool res = 0;
	Vert* item = notViseted.back();
	int i = 0;
	while (1)
	{
		this->color('w');
		res = res || haveCicle(item);
		if (res) {
			notViseted.clear();
			return true;
		}
		if (notViseted.size() == 0) {
			notViseted.clear();
			return false;
		}
		item = notViseted.back();
	}

}

bool MyGraph::haveCicle(Vert* v)
{
	v->color = 'g';
	notViseted.remove(v);
	for (auto item = ways_from[v].begin(); item != ways_from[v].end(); ++item)
	{
		Vert* u = *item;
		if (u->color == 'g')
			return true;
		if (u->color == 'b')
			return false;
		if (u->color == 'w')
			if(haveCicle(*item)) return 1;
	}
	v->color = 'b';
	return false;
}


int MyGraph::getIndex(Vert* v)
{
	for (size_t i = 0; i < vert_list.size(); i++)
	{
		if (vert_list[i] == v) return  i;
	}
}

Vert* MyGraph::getVert(int index)
{
	return vert_list[index];
}

void MyGraph::addEdge(Vert* vertFrom, Vert* vertTo)
{
	num_edges++;
	ways_from[vertFrom].push_back(vertTo);
}

void MyGraph::removeEdge(Vert* vertFrom, Vert* vertTo)
{
	num_edges--;
	ways_from[vertFrom].remove(vertTo);
}
