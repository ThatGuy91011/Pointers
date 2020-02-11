#include <iostream>
#include "Replicant.h"
using namespace std;

int main()
{
	cout << "Entering scope for a unique pointer." << endl;
	{
		unique_ptr<Replicant> replicant = make_unique<Replicant>();
		replicant->Talk();
	}
	cout << "Exiting scope for unique pointer." << endl << endl;
	cout << "Entering outer scope for a shared pointer." << endl;
	{
		//Create shared pointer
		shared_ptr<Replicant> sharedReplicant1;
		
		cout << "Entering inner scope for a shared pointer." << endl;
		{
			//Declaring/assigning shared pointer
			shared_ptr<Replicant> sharedReplicant2 = make_shared<Replicant>();
			//Assigning shared pointers to each other, effectively copying it
			sharedReplicant1 = sharedReplicant2;
			//sharedReplicant1->Print();
		}
		cout << "Exiting inner scope for a shared pointer." << endl;
	}
	//Once sharedReplicant1 dies, replicant dies as well
	cout << "Exited outer scope for a shared pointer." << endl << endl;

	cout << "Entering outer scope for a weak pointer." << endl;
	{
		weak_ptr<Replicant> weakReplicant;
		cout << "Entering inner scope for a weak pointer." << endl;
		{
			weak_ptr<Replicant> SharedReplicant1 = make_shared<Replicant>();
			weakReplicant = SharedReplicant1;
			//weakReplicant->Print();
		}
		cout << "Exiting inner scope for a weak pointer." << endl;
	}
	cout << "Exiting outer scope for a weak pointer." << endl << endl;
}