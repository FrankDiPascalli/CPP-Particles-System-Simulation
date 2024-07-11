#pragma once
#include "Vector3D.h"
#include "Enclosure.h"
#include "Particle.h"
#include "RandomGenerator.h"
#include <vector>
#include <memory> 
#include <map> 
#include <iostream>

typedef std::vector<std::unique_ptr<Particle>> Particles;

class System 
{
	public:
	
	System(const double& length = 20.0,const double& width = 20.0,const double& depth = 20.0) :  enclosure(length, width, depth) {}
	void display_system();
	void add_particle(Particle* to_add); 
	void empty_system();	
	void evolve(double dt);
	void evolve_v1(double dt); //our first version of the evolve method
	void update_map();
	private:
	std::map<Vector3D, std::vector<size_t>> mapParticles; //to each position we associate a vector of size_t representing the positions of the particles in Particle::particles
	Particles particles;
	Enclosure enclosure;
	RandomGenerator draw;
	System(const System&) = delete; 
    System& operator=(const System&) = delete;
    
    
};	

std::ostream& operator<<(std::ostream& output, System system);
