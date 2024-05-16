#pragma once
using namespace std;
class Customer {
private:
	int items;
	int age;
public:
	Customer(int items, int age)
	{
		this->items = items;
		this->age = age;
	}

	int getItems()
	{
		return this->items;
	}
	int getAge()
	{
		return this->age;
	}
	void print()
	{
		cout << "Customer(" << this->items << " , " << this->age << ")" << endl;
	}
};