#include<iostream>
#include"Customer.h"
#include"Node.h"
#include"queue.h"
using namespace std;
int main()
{
	queue queues[4];
	char choice;
	int items, age;
	int min;
	while (true)
	{
		cout << "Do you want to pay bills (Y/N): ";
		cin >> choice;
		if (choice == 'Y' || choice == 'y')
		{
			cout << "Please enter how many items do you want to purchase = ";
			cin >> items;
			while (items <= 0)
			{
				cout << "Please enter valid number of items : ";
				cin >> items;
			}
			cout << "Please enter your age = ";
			cin >> age;
			while (age <= 0)
			{
				cout << "Please enter valid age : ";
				cin >> age;
			}
			bool inserted = false;
			for (int i = 0; i < 4; i++)
			{
				if (queues[i].isEmpty())
				{
					queues[i].insert(items, age);
					inserted = true;
					break;
				}
			}
			if (!inserted)
			{
				min = queues[0].gettotalitems();
				int index = 0;
				for (int i = 0; i < 4; i++)
				{
					if (queues[i].gettotalitems() < min)
					{
						min = queues[i].gettotalitems();
						index = i;
					}
				}
				queues[index].insert(items, age);
			}
		}
		else if (choice == 'N' || choice == 'n')
		{
			break;
		}
		else
		{
			cout << "Invalid choice" << endl;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		cout << "Queue " << i + 1 << endl;
		while (!queues[i].isEmpty())
		{
			Customer* customer = queues[i].Front();
			customer->print();
			queues[i].dequeue();
		}
		cout << endl;
	}

}