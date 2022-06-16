#ifndef _VECTOR_H
#define _VECTOR_H
#include<iostream>
using namespace std;

class Vector{
	public:
		friend ostream& operator<<(ostream&,const Vector&);
		
		Vector(); //default constructor
		Vector(int in_size); //constructor only with dimension
		Vector(int in_size,const double *in_array); //constructor with dimension and initialized array
		~Vector(); //destuctor
		
		double* get_array()const; //return array
		double length(); //compute the length of vector
		void setDimension(int d); //set dimension
		int getDimension()const; //return dimension 
		
		Vector &operator=(const Vector &cpyVector);
		Vector operator-();
		Vector operator+(Vector scdVector);
		Vector operator-(Vector scdVector);
		Vector operator*(double m);
		Vector &operator+=(Vector scdVector);
		Vector &operator-=(Vector scdVector);
		Vector &operator*=(double m);
		bool operator==(Vector scdVector);
		bool operator!=(Vector scdVector);
		double operator[](int n);

	private:
		int dimension;
		double *array;
};

Vector operator*(double m,Vector vector);
#endif
