#pragma once
#include <memory>
#include <iostream>
#include "Vector3D.h"
#include "Enclosure.h"
#include "RandomGenerator.h"
#include <cmath> 

struct Return //to be able to return the side that was touched in addition to the information that one was touched
{ 
	bool collision;
	int hit_face;
};

class Particle  
{

	private :
	Vector3D pos; //position
	Vector3D v; //velocity
	double m; //mass
	
	public :
	Particle(Vector3D pos1 = Vector3D {}, Vector3D v1 = Vector3D {}, double m1 = 0.0) : pos(pos1), v(v1), m(m1) {}
	Particle (const Particle& other);
	Vector3D getpos () const { return pos; } // retourne la position
	Vector3D get_discrete_pos() const {return Vector3D(std::floor(pos.get_x()), std::floor(pos.get_y()), std::floor(pos.get_z()));} //used in System::evolve 
	Vector3D getv () const { return v; }
	double getm () const { return m; }
	void set_position (size_t index, double value); //gives the value "value" to the index "index" of the particle's position					    
	void set_velocity (size_t index, double value); //gives the value "value" to the index "index" of the particle's velocity
	void setm (double mass) { m = mass; }
	virtual void display () const ; 
	void evolve (double dt);
	Return wall_collision(const Enclosure& enclosure);
	void collision_particle(Particle& P);
	bool test_collision_particle(Particle& P); //not a constant reference because the velocity of the particle needs to be modified
	virtual ~Particle () ;
	
};

std::ostream& operator<<(std::ostream& output, const Particle& p);
