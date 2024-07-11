#include "Argon.h"
#include <string>
#include <iostream>
using namespace std;

void Argon:: display() const 
		{
			cout << "Argon :"; 
			Particle::display(); 
			
		}
Argon ::~Argon() {
	cout << "The Argon particle has perished :( " <<endl;
}
