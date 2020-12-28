#include <iostream>

#include "mygraphlib.h"

int main()
{
	MyGraph G;
	G.addVert(1);// index = 0
	G.addVert(1);//1
	G.addVert(1);//2
	G.addVert(1);//3
	G.addVert(1);//4
	G.addVert(1);//5
	G.addVert(1);//6
	G.addVert(1);//7
	G.addVert(1);//8
	G.addVert(1);//8
	//conf 3
	G.addEdge(0, 1);
	G.addEdge(0, 2);
	G.addEdge(1, 4);
	G.addEdge(1, 5);
	
	G.addEdge(6, 7);
	G.addEdge(8, 9);
	G.addEdge(7, 8);
	G.addEdge(9, 7);
	
	cout << G.withoutThisUncicled();
	return 0;
}
