#include "Helium.h"
#include <string>
#include <iostream>
using namespace std;

void Helium:: display() const 
		{
			
			cout << "Helium : ";
			Particle::display();
		}
Helium ::~Helium() {
	cout << "The Helium particle has perished :( " <<endl;
}

