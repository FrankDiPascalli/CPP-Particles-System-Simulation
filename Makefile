CXX = g++
CC = $(CXX)

CXXFLAGS = -std=c++14 
#14 for the unique_ptr

CXXFLAGS += -pedantic -Wall # pour les purs et durs

# CXXFLAGS += -g # to debugg
# CXXFLAGS += -O2 # to optimize speed

all:: FinalSimulationTest

Vector3D.o: Vector3D.cc Vector3D.h

Particle.o: Particle.cc Particle.h Vector3D.h RandomGenerator.h

Neon.o: Neon.cc Neon.h Particle.h Vector3D.h

Argon.o: Argon.cc Argon.h Particle.h Vector3D.h

Helium.o: Helium.h Helium.cc Particle.h Vector3D.h
 
System.o: System.cc System.h RandomGenerator.h Particle.h Vector3D.h

RandomGenerator.o : RandomGenerator.h

FinalSimulationTest.o : FinalSimulationTest.cc System.h Particle.h Vector3D.h Neon.h Argon.h Helium.h

FinalSimulationTest: FinalSimulationTest.o System.o Particle.o Vector3D.o Neon.o Argon.o Helium.o
