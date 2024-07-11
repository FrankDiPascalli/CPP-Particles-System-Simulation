#pragma once
#include "Particle.h"
#include <string>



class Helium : public Particle
{
	public :
	Helium(Vector3D pos1 = Vector3D {}, Vector3D v1 = Vector3D {}) : Particle(pos1, v1, helium_mass) {}
	void display() const final;
	virtual ~Helium() override;
	Helium(Helium const&)            = default;	
	Helium& operator=(Helium const&) = default;
	Helium(Helium&&)                 = default;
	Helium& operator=(Helium&&)      = default;
	
	private :
	constexpr static double helium_mass = 4.002602;
};

