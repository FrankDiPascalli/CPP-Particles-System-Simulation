#pragma once

class Enclosure
{
	private : 
	double length;
	double width;
	double depth;
	
	public :
	Enclosure(double length, double width, double depth) : 
	length(length), width(width), depth(depth) {}
	
	double getlength() const { return length; }
	double getwidth() const { return width; }
	double getdepth() const { return depth; }
	
	virtual ~Enclosure() = default;
    Enclosure(Enclosure const&)            = default;
    Enclosure& operator=(Enclosure const&) = default;
    Enclosure(Enclosure&&)                  = default;
    Enclosure& operator=(Enclosure&&)      = default;
    Enclosure() 							 = default;
};




