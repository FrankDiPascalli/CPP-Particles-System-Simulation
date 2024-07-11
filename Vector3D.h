#pragma once
#include <array>
#include <iostream>

typedef std::array<double, 3> Coordinates;

class Vector3D {
	public :
	Vector3D(double x = 0.0, double y = 0.0, double z = 0.0) : vector({x,y,z}) {}
	Vector3D (Vector3D const& other); 
	Coordinates getVector () const { return vector;  }
	double get_x() const { return vector[0];}
	double get_y() const { return vector[1];}
	double get_z() const { return vector[2];}
	void set_coord (size_t index, double value);
	void display (std::ostream& output) const ; 	
	bool compare(Vector3D v_compare, double precision) ;	
	Vector3D addition(Vector3D other) const; 	
	Vector3D substraction(Vector3D other) const;	
	Vector3D opposite() const;	
	Vector3D mult(double scal) const;	
	double scal_prod(Vector3D other) const;//standard scalar product of RJ	Vector3D vect_prod(Vector3D other) const;	
	double norm() const;	
	double norm2() const; //the norm to the power of 2	
	Vector3D unit() const; //gives the unit vector	
	Vector3D& operator+=(const Vector3D&);	
	Vector3D operator+(const Vector3D&) const;	
	Vector3D& operator-=(const Vector3D&);	
	Vector3D operator-(const Vector3D&) const; 	
	Vector3D operator-(); //returns the opposite
	Vector3D operator *=(const double& scal);	
	Vector3D operator*(double scal) const; //scalar multiplication	
	Vector3D operator^=(const Vector3D&); //vector product	
	Vector3D operator^(const Vector3D&) const; //vector product	
	Vector3D operator~(); //return the normalized vector	
	bool operator==(Vector3D const& v); // test weather two vectors are equals or not	
	private : 	
	Coordinates vector;	
};

std::ostream& operator<<(std::ostream& output, Vector3D v);

bool operator<(const Vector3D& lhs, const Vector3D& rhs); //to be able to use maps without defining any hash functions
														 //we need to define an ordrer within vectors. (that definition
														//is arbitrary and doesn't matter)
