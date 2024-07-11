#include <iostream>
#include <vector>
#include <cmath>
#include "Particle.h"
#include "Enclosure.h"
#include "RandomGenerator.h"

using namespace std;



void Particle:: display() const {
	Vector3D pos = getpos();
	Vector3D v = getv();
	double m = getm();
    cout << "pos : " << pos << " ; v : " << v << " ; m : " << m << endl;
}
    
std::ostream& operator<<(std::ostream& output, const Particle& p)
{
	p.display();
	return output;
}

Particle::~Particle () 
{
}

Particle::Particle (const Particle& other)
: pos(other.getpos()), v(other.getv()), m(other.getm())
{}	

void Particle::set_position (size_t index, double value)
{
	pos.set_coord(index, value);
}

void Particle::set_velocity (size_t index, double value)
{
	v.set_coord(index,value);
}

void Particle :: evolve(double dt)
	{
		Particle p;
		
		p.set_position(0, dt* v.get_x());
		p.set_position(1, dt* v.get_y());
		p.set_position(2, dt* v.get_z());
		
		pos+= p.getpos();
		
		
	}

Return Particle :: wall_collision(const Enclosure& enclosure) 
{
	Return _return({false, 0});
	
	
	if(((pos.get_x()) >= enclosure.getlength()/2) and ((getv().get_x()) > 0)) //We will check for each face of the box if the direction of the speed of the
																			//coming particle so that there is not a second collision when it has just left
	{
		set_position(0, (enclosure.getlength()/2));
		set_velocity(0, -(getv().get_x()));
		_return = {true, 3};
	}	
	if(((pos.get_x()) <= -enclosure.getlength()/2) and ((getv().get_x()) < 0))
	{
		set_position(0, -(enclosure.getlength()/2));
		set_velocity(0, -(getv().get_x()));
		_return = {true, 4};
	}
	
	if(((pos.get_y()) >= enclosure.getwidth()/2) and ((getv().get_y()) > 0))
	{
		set_position(1, (enclosure.getwidth())/2);
		set_velocity(1, -(getv().get_y()));
		_return = {true, 2};
	}
	
	if(((pos.get_y()) <= -enclosure.getwidth()/2) and ((getv().get_y()) < 0))
	{
		set_position(1, -(enclosure.getwidth()/2));
		set_velocity(1, -(getv().get_y()));
		_return = {true, 1};
	}
		
	if(((pos.get_z()) >= enclosure.getdepth()/2) and ((getv().get_z()) > 0))
	{
		set_position(2, (enclosure.getdepth())/2);
		set_velocity(2, -(getv().get_z()));
		_return = {true, 5};
	}
	
	if(((pos.get_z()) <= -enclosure.getdepth()/2) and ((getv().get_z()) < 0))
	{
		set_position(2, -(enclosure.getdepth()/2));
		set_velocity(2, -(getv().get_z()));
		_return = {true, 6};
	}

return _return; //Why only return at the end? In fact, we test all collisions because if we were to have a
			   //time interval too large, a particle could leave the box according to several coordinates. Doing 
			  //the return at the end and not in the ifs we could therefore in this case rectify the situation according to all the coordinates
}			 //of course the best would to allow multiple collisions but if would have really made the system more complex

bool Particle :: test_collision_particle(Particle& P)  //used in our fist version of System::evolve (evolve_v1=
{
	if (pos==P.pos)
	{
		Vector3D Vg = v*(m/(m+P.m)) + P.v*(P.m/(m+P.m));
		
		RandomGenerator generator;
		
		double L = (v-Vg).Vector3D::norm();
		double z = generator.uniform(-L,L);
		double phi;
		do 
		{
			phi = generator.uniform(0,2*M_PI);
		} while (phi == 2*M_PI);
		double r = sqrt(L*L - z*z);
		
		Vector3D Vo ((r*cos(phi)),(r*sin(phi)),z);
		v = Vg + Vo;
		P.v = Vg - Vo*(m/P.m);
		return true;
	}
	return false;
}

void Particle :: collision_particle(Particle& P) 
{
	Vector3D Vg = v*(m/(m+P.m)) + P.v*(P.m/(m+P.m));
		
	RandomGenerator generator;
		
	double L = (v-Vg).Vector3D::norm();
	double z = generator.uniform(-L,L);
	double phi;
	do {
		phi = generator.uniform(0,2*M_PI);
	} while (phi == 2*M_PI);
	double r = sqrt(L*L - z*z);
		
	Vector3D Vo ((r*cos(phi)),(r*sin(phi)),z);
	v = Vg + Vo;
	P.v = Vg - Vo*(m/P.m);
}
