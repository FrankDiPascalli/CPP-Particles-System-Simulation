#pragma once
#include <random>

class RandomGenerator {
	public:
	  RandomGenerator(unsigned int seed = std::random_device()() )
		: generator(seed)
	  {}

	double uniform(double min, double max) {
		return uniform_distribution(generator, std::uniform_real_distribution<double>::param_type{min, max});
	}

	double gaussian(double average, double standard_deviation){
    return gaussian_distribution(generator, std::normal_distribution<double>::param_type{average, standard_deviation});
  }
	private:
	  std::default_random_engine              generator            ;
	  std::uniform_real_distribution<double>  uniform_distribution ;
	  std::normal_distribution<double> gaussian_distribution;
	};
