#include "System.h"
#include <vector> 
#include <iostream>
#include <memory>
using namespace std;

void System :: display_system(){
	size_t number_part(particles.size());
	cout << "The system is composed of the "<< number_part;
	cout << " following particles : "<<endl;
			
	for(auto const& particle_ptr : particles){ //the particles in constant reference because the unique_ptrs can't be copied
		particle_ptr-> display();
	}
		
}
ostream& operator<<(ostream& output, System system)
{
	system.display_system();
	return output;
}

void System :: add_particle(Particle* to_add){
	particles.push_back(std::move(std::unique_ptr<Particle>(to_add)));	
}

void System :: empty_system(){
	particles.clear();
}

void System :: evolve(double dt){ //Second Version of Evolve that uses maps and seperate the enclosure into a grid [now in O(n)]
		
	for (auto& particle : particles) {
	particle->evolve(dt);
	}
	update_map();
			
	for (size_t i = 0; i < particles.size(); ++i) { //check if a particle hits a wall
		Return wall_test(particles[i]->wall_collision(enclosure)); //Return is a struct defined in Particle.h 
	    if (wall_test.collision) {
		   cout << "The particle " << i + 1 << " bounces off the wall " << wall_test.hit_face << endl;
		}
	}
		
	for(auto& entry : mapParticles) { //check if two particles collide
		auto& ListParticles = entry.second;
		if (ListParticles.size() >= 2) { // Verify that there are multiple particles in this box of the grid
			particles[ListParticles[0]]->collision_particle(*particles[ListParticles[1]]);
				cout << "Two particles collide in box" << entry.first << endl; //to display which particles hit each other like in our first version of evolve (evolve_v1)
																			   //we could display their index in particle for exemple ...
		}
	}
}


void System::update_map() {
	mapParticles.clear(); // empties the map to update it
	for (size_t i(0); i < particles.size(); ++ i) {
		Vector3D discrete_pos = particles[i]->get_discrete_pos();
		mapParticles[discrete_pos].push_back(i);
	}
}

void System :: evolve_v1(double dt){ //our first version of the evolve method in O(nJ	
	for(size_t i(0); i < particles.size(); ++i)
	{
		particles[i]->evolve(dt);
		Return wall_test(particles[i]->wall_collision(enclosure));
	    if (wall_test.collision) {
		   cout << "The particle " << i + 1 << " bounces off the wall " << wall_test.hit_face << endl;
		}
	
		
		for(size_t j(0); j < particles.size(); ++j)
		{
			if(i !=j){
				if(particles[i]->test_collision_particle(*particles[j])){
					cout << "The particle " << i+1 << " collides with particle " <<j+1 <<endl; //Convention : we add 1 to our index so that there are no particle 0
				}
			}
		}
	}
}
