#include "Replicant.h"
#include <iostream>


Replicant::Replicant()
{
	std::cout << "Created" << std::endl;
}


void Replicant::Talk()
{
	std::cout << "\n Test" << std::endl;
}

Replicant::~Replicant()
{
	std::cout << "Destroyed" << std::endl;
}
