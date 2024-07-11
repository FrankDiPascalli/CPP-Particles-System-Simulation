#include <iostream>
#include <memory>
#include "System.h"
#include "Particle.h"
#include "Vector3D.h"
#include "Neon.h"
#include "Argon.h"
#include "Helium.h"
using namespace std;		

int main(){
	System system(20.0,20.0,20.0);
	
	system.add_particle(new Neon({1,10.5,1}, {0.9,2,1}));
	system.add_particle(new Argon({1,1,3.1}, {0,1,-0.5}));
	system.add_particle(new Helium({1,1,1}, {3,1.2,0.4}));
	system.add_particle(new Neon({0,0,1}, {0,0,-1}));
	system.add_particle(new Argon({0,0,-1}, {0,0,1}));
	system.add_particle(new Neon({-2.5, 7.8, -3.6}, {4.2, -5.1, 3.3}));
	system.add_particle(new Argon({-7.4, -1.2, 5.9}, {6.1, -3.8, 2.5}));
	system.add_particle(new Helium({3.0, -9.1, 2.7}, {-1.3, 4.5, -7.6}));
	system.add_particle(new Neon({4.6, -3.3, 8.2}, {-5.4, 2.9, -0.8}));
	system.add_particle(new Argon({-8.7, 6.0, -4.4}, {2.1, -7.8, 9.3}));
	system.add_particle(new Neon({-4.8, 3.3, -7.1}, {1.2, -9.4, 5.6}));
	system.add_particle(new Argon({2.5, -6.3, 4.4}, {-8.7, 3.8, 0.1}));
	system.add_particle(new Helium({7.6, -5.5, 2.2}, {4.0, -3.9, -6.8}));
	system.add_particle(new Neon({-9.0, 4.7, -2.6}, {6.3, -1.1, 7.4}));
	system.add_particle(new Argon({3.8, -8.2, 0.5}, {-2.4, 5.9, -7.7}));
	system.add_particle(new Neon({6.2, -4.1, 8.9}, {-3.4, 2.1, -7.8}));
	system.add_particle(new Argon({-1.5, 7.4, -3.7}, {4.3, -6.2, 5.1}));
	system.add_particle(new Helium({9.0, -8.8, 2.0}, {-5.6, 4.4, -1.9}));
	system.add_particle(new Neon({-7.2, 1.0, -4.9}, {3.8, -2.7, 6.3}));
	system.add_particle(new Argon({5.4, -3.3, 6.1}, {-8.5, 1.9, 2.4}));
	system.add_particle(new Helium({-2.1, 6.5, -9.2}, {7.0, -5.4, 3.6}));
	system.add_particle(new Neon({4.3, -7.9, 1.5}, {-1.8, 8.6, -2.5}));
	system.add_particle(new Argon({-6.7, 3.2, -8.0}, {2.6, -4.8, 9.1}));
	system.add_particle(new Helium({8.4, -5.6, 2.9}, {-7.7, 4.0, -3.5}));
	system.add_particle(new Neon({-3.9, 6.8, -1.2}, {5.2, -9.3, 0.7}));
	system.add_particle(new Argon({2.7, -8.1, 4.5}, {-6.0, 7.2, -4.3}));
	system.add_particle(new Helium({7.1, -3.4, 9.7}, {-2.8, 5.5, -7.6}));
	system.add_particle(new Neon({-4.2, 1.6, -5.3}, {3.9, -6.1, 8.8}));
	system.add_particle(new Argon({5.6, -2.7, 7.4}, {-8.9, 2.3, -1.1}));
	system.add_particle(new Helium({-1.8, 4.9, -6.6}, {6.4, -7.0, 3.0}));
	system.add_particle(new Neon({3.5, -9.4, 0.8}, {-2.5, 6.7, -3.8}));
	system.add_particle(new Argon({-7.1, 5.0, -2.3}, {4.6, -3.6, 7.9}));
	system.add_particle(new Helium({8.3, -6.5, 1.2}, {-5.0, 7.1, -2.4}));
	system.add_particle(new Neon({-2.9, 7.6, -4.7}, {1.4, -8.2, 5.3}));
	system.add_particle(new Argon({4.1, -3.1, 6.9}, {-7.4, 2.9, 0.6}));
	system.add_particle(new Helium({-5.5, 1.8, -8.3}, {6.1, -4.2, 9.0}));
	system.add_particle(new Neon({6.8, -2.2, 5.7}, {-9.1, 3.4, -3.0}));
	system.add_particle(new Argon({-3.4, 8.5, -1.0}, {2.7, -6.9, 7.6}));
	system.add_particle(new Helium({7.9, -4.3, 2.6}, {-1.6, 5.9, -8.8}));
	system.add_particle(new Neon({-6.0, 3.6, -7.4}, {4.4, -2.0, 6.5}));
	system.add_particle(new Argon({5.1, -8.7, 1.9}, {-3.7, 7.5, -2.6}));
	system.add_particle(new Helium({-4.5, 9.2, -3.8}, {2.2, -5.8, 8.1}));
	system.add_particle(new Neon({7.7, -1.3, 4.0}, {-8.6, 6.2, -1.7}));
	system.add_particle(new Argon({-2.6, 5.8, -6.2}, {3.1, -9.0, 2.8}));
	system.add_particle(new Helium({4.8, -7.1, 0.3}, {-6.3, 8.0, -4.1}));
	system.add_particle(new Neon({-8.4, 2.4, -5.1}, {1.9, -7.6, 6.9}));
	system.add_particle(new Argon({3.3, -6.8, 7.2}, {-4.9, 5.3, -0.4}));
	system.add_particle(new Helium({-1.2, 7.3, -4.6}, {6.8, -3.5, 9.5}));
	system.add_particle(new Neon({8.1, -4.0, 2.1}, {-2.9, 6.6, -5.7}));
	system.add_particle(new Argon({-5.3, 1.4, -7.8}, {4.5, -9.1, 0.2}));
	system.add_particle(new Helium({6.9, -3.7, 8.3}, {-1.4, 5.2, -7.2}));
	system.add_particle(new Neon({-2.0, 6.1, -9.5}, {3.7, -5.0, 2.3}));
	system.add_particle(new Argon({4.7, -2.9, 6.4}, {-7.5, 3.3, -1.8}));
	system.add_particle(new Helium({-8.6, 3.5, -4.2}, {5.0, -7.9, 8.4}));
	system.add_particle(new Neon({5.9, -7.4, 0.7}, {-6.8, 2.6, -5.3}));
	system.add_particle(new Argon({-3.0, 8.2, -1.7}, {2.0, -6.5, 7.3}));
	system.add_particle(new Helium({7.5, -4.5, 3.9}, {-5.7, 6.0, -2.8}));
	system.add_particle(new Neon({-1.7, 4.8, -6.9}, {6.3, -8.1, 1.6}));
	system.add_particle(new Argon({5.8, -9.6, 2.5}, {-4.0, 7.4, -3.2}));
	system.add_particle(new Helium({-4.3, 1.2, -7.7}, {3.5, -6.7, 8.6}));
	system.add_particle(new Neon({8.7, -2.8, 4.6}, {-1.5, 5.1, -9.2}));
	system.add_particle(new Argon({-6.4, 7.0, -3.1}, {2.8, -9.3, 5.4}));
	system.add_particle(new Helium({3.2, -5.6, 9.4}, {-7.1, 4.7, -6.0}));
	system.add_particle(new Neon({-5.2, 2.9, -8.5}, {1.7, -7.8, 4.1}));
	// idea : use random generator to create those particles
	system.display_system();	
	cout << "Launch of the simulation... "<<endl;
	cout << "=============================" <<endl;
	double dt = 0.01; //ATTENTION : If you take a dt that is too small some collision could happen outside of the enclosure (if between to dt the particles
					 // have time to get out of the enclosure and hit each other, feel free to try different configurations
	 
	for(int i(1); i<= 10000; ++ i){
		system.evolve(dt); 
		system.display_system();
		cout << "============================="<<endl;
	}
	return 0;
	
}
