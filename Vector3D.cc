#include <iostream>
#include <array>
#include <cmath>
#include "Vector3D.h"

static double EPSILON = 1;


using namespace std;

Vector3D :: Vector3D(const Vector3D& other) : vector(other.vector) {}	

void Vector3D:: set_coord(size_t position, double value){ 
	vector[position] = value;} 

void Vector3D:: display(std::ostream& sortie) const {
	Coordinates v = getVector();
    cout << "( " << v[0] << " , " << v[1] << " , " << v[2] << " )" << endl;
}
bool Vector3D:: compare(Vector3D v_compared, double precision)  { 
	for (int i = 0; i <= 2; ++i) {
		if (abs(v_compared.getVector()[i] - getVector()[i]) >= precision) {
           return false;
		}
	}

	return true;
}


Vector3D Vector3D:: addition(Vector3D other) const {
	Vector3D result;
    for (size_t i = 0; i < 3; ++i) {
        result.set_coord(i, getVector()[i] + other.getVector()[i]);
    }
    return result;
}

Vector3D Vector3D :: opposite() const {
	Vector3D _return;
	for(size_t i(0); i <= 2; ++i){
		_return.set_coord(i, - getVector()[i]);
	}
	return _return;
}

Vector3D Vector3D:: substraction(Vector3D other) const {
	Vector3D _return;
	for(size_t i(0); i <= 2; ++i){
		_return.set_coord(i, getVector()[i]- other.getVector()[i]);
	}
	return _return;
}

Vector3D Vector3D:: mult(double scal) const{
	Vector3D _return;
	for(size_t i(0); i <= 2; ++i){
		_return.set_coord(i, scal * getVector()[i]);
	}
	return _return;
}

double Vector3D::scal_prod(Vector3D other) const{
	double scalar_product = 0.0;
    for (size_t i = 0; i <= 2; ++i) {
        scalar_product += (vector[i] * other.getVector()[i]);
    }
    return scalar_product;
}

Vector3D Vector3D :: vect_prod(Vector3D other) const {
    Vector3D result;
    result.set_coord(0, getVector()[1] * other.getVector()[2] - getVector()[2] * other.getVector()[1]);
    result.set_coord(1, getVector()[2] * other.getVector()[0] - getVector()[0] * other.getVector()[2]);
    result.set_coord(2, getVector()[0] * other.getVector()[1] - getVector()[1] * other.getVector()[0]);
    return result;
}

double Vector3D:: norm2() const{
	return (scal_prod(*this)); //the norm of a vector is by definition the definition the square root of the scalar product 
							  // of a scalar product of this vector with itself
}

double Vector3D:: norm() const {
	return sqrt(norm2());
}

Vector3D Vector3D::unit() const {
    double norm_vector = norm();
    Vector3D unit_vector;
    for (size_t i = 0; i < 3; ++i) {
        unit_vector.set_coord(i, vector[i] / norm_vector);
    }
    return unit_vector;
}

bool Vector3D :: operator==(Vector3D const& v){
	return compare(v, EPSILON);
}


Vector3D& Vector3D::operator+=(const Vector3D& v)
{
	*this = this->addition(v);
    return *this;
}
Vector3D Vector3D::operator+(const Vector3D& v) const
{
	return Vector3D(*this) += v;
}

Vector3D& Vector3D::operator-=(const Vector3D& v)
{
    *this = this->substraction(v);
    return *this;
}
Vector3D Vector3D::operator-(const Vector3D& v) const
{
	return Vector3D(*this) -= v;
}

Vector3D Vector3D::operator-(){
	return this->opposite();
}

Vector3D Vector3D::operator*=(const double& scal){

	for(size_t i(0); i <= 2; ++i)
	{
		set_coord(i, scal * getVector()[i]);
	}
	return *this;
}


Vector3D Vector3D::operator*(double scal) const
{
	Vector3D _return; 
	for(size_t i(0); i <= 2; ++i)
	{
		_return.set_coord(i, scal * getVector()[i]);
	}
	return _return;
}

Vector3D Vector3D :: operator^=(const Vector3D& other) 
{
	vect_prod(other);
    return *this;
}
Vector3D Vector3D :: operator^(const Vector3D& v) const
{
	return Vector3D(*this) ^= v;
}

Vector3D Vector3D :: operator~() 
{
	double vector_norm = norm();
    for (size_t i = 0; i < 3; ++i) {
        set_coord(i, vector[i] / vector_norm);
    }
    return *this;
}



ostream& operator<<(ostream& output, Vector3D v)
{
	v.display(output);
	return output;
}

bool operator<(const Vector3D& lhs, const Vector3D& rhs) {
    // Compare each component of the vectors
    for (size_t i = 0; i < 3; ++i) {
        if (lhs.getVector()[i] < rhs.getVector()[i]) return true;
        if (lhs.getVector()[i] > rhs.getVector()[i]) return false;
    }
    // All components are equal, so they are not less than each other
    return false;
}
