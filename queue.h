#pragma once
using namespace std;
class queue {
private:
	Node* front;
	Node* rear;
	int size;
	int totalitems;
public:
	queue()
	{
		this->front = nullptr;
		this->rear = nullptr;
		this->size = 0;
		this->totalitems = 0;
	}
	void insert(int items, int age)
	{
		Node* newNode = new Node(items, age);
		if (front == nullptr)
		{
			front = newNode;
			rear = newNode;
		}
		else
		{
			if (age > front->getAge())
			{
				newNode->setNext(front);
				front = newNode;
			}
			else
			{
				Node* temp1 = front;
				Node* temp2 = nullptr;
				while (temp1 != nullptr && temp1->getAge() >= age)
				{
					temp2 = temp1;
					temp1 = temp1->getNext();
				}
				temp2->setNext(newNode);
				newNode->setNext(temp1);
				if (temp2 == rear)
				{
					rear = newNode;
				}
			}

			/*else
			{
				rear->setNext(newNode);
				rear = newNode;
			}*/
		}
		totalitems += items;
		size++;
	}
	Customer* dequeue()
	{
		if (front != nullptr && size != 0)
		{
			Node* todelete = front;
			Customer* c = front->getcustomer();
			totalitems = totalitems - front->getItems();
			front = front->getNext();
			delete todelete;
			size--;
			return c;
		}
		else
		{
			cout << "Queue empty " << endl;
		}
	}
	Customer* Front()
	{
		if (front != nullptr)
		{
			return front->getcustomer();
		}
	}
	int getSize()
	{
		return this->size;
	}
	int gettotalitems()
	{
		return this->totalitems;
	}
	bool isEmpty()
	{
		if (size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	~queue()
	{
		Node* temp = front;
		while (temp != nullptr)
		{
			front = front->getNext();
			delete temp;
			temp = front;
		}
	}
};