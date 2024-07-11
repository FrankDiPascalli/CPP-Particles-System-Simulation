#pragma once 
#include "Particle.h"
#include <string>

class Argon : public Particle
{
	public :
	Argon(Vector3D pos1 = Vector3D {}, Vector3D v1 = Vector3D {}) : Particle(pos1, v1, argon_mass) {} //note : il faudrait d©nir les masses des particules comme des constantes internes 
	void display() const override;
	
	virtual ~Argon();
    Argon(Argon const&)            = default;
    Argon& operator=(Argon const&) = default;
    Argon(Argon&&)                 = default;
    Argon& operator=(Argon&&)      = default;
   
	
	private :
	constexpr static double argon_mass = 39.948;
};

