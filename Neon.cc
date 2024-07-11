#include "Neon.h"
#include <string>
#include <iostream>
using namespace std;

void Neon:: display() const 
		{
			cout << "Neon : ";
			Particle::display();
		}
Neon ::~Neon(){
	cout << "The Neon particle has perished :( " <<endl;
}
