# CPP-Particles-System-Simulation
This simulation project was developed as part of the Object-Oriented Programming course in the Physics section at EPFL

## Table of Contents

- [Project Description](#project-description)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [File Structure](#file-structure)
- [Conception](#conception)
- [Credits](#credits)
- [License](#license)

## Project Description

The Particle System Simulation models the behavior of particles within a rectangular enclosure. The particles have defined positions, velocities, and masses, and the simulation tracks their movements and collisions over time. Please note that we take 0.1 nm as a basic unit.

Two collision detection methods are implemented:

1. **Continuous Checking:** Continuous checking of particle positions and triggering collisions if particles are within a certain distance.
2. **Cell-based Checking:** Dividing the enclosure into cells and checking for collisions within each cell.

## Features

- Simulates particle motion and collisions within a 3D enclosure.
- Supports two different collision detection methods. (our first one is in $O(n^2)$ and the second one $O(n)$
- Uses object-oriented programming principles with classes for particles, the system, and the enclosure.

## File Structure

- **Particle.h:** Defines the `Particle` class with properties and methods for particles.
- **Particle.cc:** Implementation of the `Particle` class.
- **System.h:** Defines the `System` class that manages a collection of particles.
- **System.cc:** Implementation of the `System` class.
- **finalTestSimulation.cc:** Main file to run the simulation with sample particles.
- **Vector3D.h:** Utility class for 3D vector operations.
- **Enclosure.h:** Defines the `Enclosure` class representing the simulation space.
- **RandomGenerator.h:** Utility class for generating random numbers.

## Conception


### Particle
Particles are modeled as material points with specific positions and velocities. We suppose that we both know their velocity and position at each moment (which is actually impossible due to [Heisenberg's uncertainty principle](https://en.wikipedia.org/wiki/Uncertainty_principle)).

### Enclosure
The enclosure is a rectangular parallelepiped, centered at the origin. Particles are constrained within the enclosure boundaries. 
We gave a number for each side of this box so that we know which side is touched when there is a collision with the box.### Enclosure

The enclosure is a rectangular parallelepiped, centered at the origin. Particles are constrained within the enclosure boundaries.

As we put the origin in the middle of the parallelepiped, the conditions that we check to make sure that a particle is within the boundaries are:

- $\(\lvert x \rvert \leq \frac{\text{length}}{2}\)$
- $\(\lvert y \rvert \leq \frac{\text{width}}{2}\)$
- $\(\lvert z \rvert \leq \frac{\text{height}}{2}\)$

![Capture d'écran 2024-07-11 183934](https://github.com/FrankDiPascalli/CPP-Particles-System-Simulation/assets/163467572/d9954782-d397-4b53-a772-923499b13981)


### Collisions

#### Wall Collisions

For collisions with the walls, we check at each moment whether any of the particles touch a wall (with a margin of epsilon) or if they have passed through it. This situation might occur if we use time intervals that are too large or if particles have excessively high velocities. Our goal is to avoid such cases through careful design and parameter selection.

#### Particle Collisions

Two different models for detecting collisions between particles were proposed during the project, and we have implemented both:

1. **Continuous Position Checking:** This method continuously monitors the positions of all particles and detects a collision if two particles come within a certain distance epsilon of each other.

2. **Cell-Based Checking:** This method divides the enclosure into a grid of cells. For each cell, it checks whether multiple particles are present, which would trigger a collision. This method is more efficient than the continuous checking approach and is suitable for larger systems or higher particle densities.

For more detailed information on these collision detection methods, please refer to the relevant sections in the documentation.

### System
Uses a vector of `unique_ptr` to manage particles, ensuring no duplicate particles and simplifying memory management.

## Credits

This project was developed by @FrankDiPascalli for the Object-Oriented Programming course at EPFL.
