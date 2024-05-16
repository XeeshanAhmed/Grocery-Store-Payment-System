#pragma once
using namespace std;
class Node {
private:
	Customer* c;
	Node* next;
public:
	Node(int items, int age)
	{
		c = new Customer(items, age);
		this->next = nullptr;
	}
	Customer* getcustomer()
	{
		return this->c;
	}
	int getAge()
	{
		return c->getAge();
	}
	int getItems()
	{
		return c->getItems();
	}
	void setNext(Node* next)
	{
		this->next = next;
	}
	Node* getNext()
	{
		return this->next;
	}
	~Node()
	{
		delete c;
	}
};