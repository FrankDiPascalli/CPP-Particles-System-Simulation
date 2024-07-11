#pragma once
#include "Particle.h"
#include <string>

class Neon : public Particle
{
	public :
	Neon(Vector3D pos1 = Vector3D {}, Vector3D v1 = Vector3D {}) : Particle(pos1, v1, neon_mass) {}
	void display() const final;
	
	virtual ~Neon() override;
	Neon(Neon const&)            = default;
	Neon& operator=(Neon const&) = default;
	Neon(Neon&&)                 = default;
	Neon& operator=(Neon&&)      = default;

  
  private :
	constexpr static double neon_mass = 20.1797;
};
