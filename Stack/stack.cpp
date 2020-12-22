#include <iostream>

struct StackElem
{
	int data;
	StackElem* next;
};

struct Stack
{
	
	Stack()
	{
		head = new StackElem;
		head->next = nullptr;
	}
	~Stack()
	{
		while (!isEmpty())
		{
			pop();
		}
		delete head;
	}
	int pop()
	{
		if (head->next == nullptr) throw -1;
		int res = head->next->data;
		StackElem* next = head->next->next;
		delete head->next;
		head->next = next;
		return res;
	}
	void push(int data)
	{
		StackElem* newElem = new StackElem;
		newElem->data = data;
		newElem->next = head->next;
		head->next = newElem;
	}
	bool isEmpty()
	{
		if (head->next == nullptr) return true;
		return false;
	}
private:
	StackElem* head;
};


int main(int argc, char* argv[])
{
	Stack* a = new Stack;
	a->push(1);
	a->push(1);
	a->push(12);
	a->push(3);
	if (!a->isEmpty())
		std::cout << "not empty"<<std::endl;

	std::cout << a->pop()<<std::endl;
	std::cout << a->pop()<<std::endl;
	std::cout << a->pop()<<std::endl;
	std::cout << a->pop()<<std::endl;

	if (a->isEmpty())
		std::cout << "empty";
	
	return 0;
}
