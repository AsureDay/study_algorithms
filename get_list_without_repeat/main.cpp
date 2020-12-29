#include <iostream>
#include <list>
#include <set>
using namespace std;

list<char> getListWithoutRepeat(list<char> s)
{
	set<char> havethat;
	list<char> result;
	int size = s.size();
	for(int i = 0;i < size;i++)
	{
		char c = s.back();
		if(!havethat.count(c))
		{
			havethat.insert(c);
			result.push_front(c);
		}
		s.pop_back();
	}
	havethat.clear();
	return  result;
}
void printList(list<char> l)
{
	for(auto i:l)
	{
		cout << i << "\t";
	}
}
int main(int argc, char* argv[])
{

	list<char> a = {'h','s','a','s','s','s','d' };

	list<char> b  = getListWithoutRepeat(a);
	printList(b);

	a.clear();
	b.clear();
	return 0;
}
