#include<iostream>
#include<string.h>
#include<math.h>
#include"Vector.h"
using namespace std;

//overloading for cout Vector
ostream& operator<<(ostream& out, const Vector& c){
	double *temp = c.get_array();
	out << "(";
	for(int i=0;i<c.getDimension();++i){
		if(i == 0){
			out << temp[i]; //first number in array
		}
		else{
			out << ", " << temp[i];
		}
	}
	out << ")";
	return out;
}

//default constructor
Vector::Vector(){
	dimension = 2; //set dimension to 2 if there is no parameter
	array = new double[dimension];
	memset(array,0,sizeof(array)*dimension);
}

//constructor only with dimension
Vector::Vector(int in_dimension){
	dimension = in_dimension;
	array = new double[dimension];
	memset(array,0,sizeof(array)*dimension);
}

//constructor with dimension and initialized array
Vector::Vector(int in_dimension,const double *in_array){
	dimension = in_dimension;
	array = new double[dimension];
	for(int i=0;i<dimension;++i){ //initialized array
		array[i] = in_array[i];
	}
}

//destuctor
Vector::~Vector(){
}

double*  Vector::get_array()const{
	return array;
}

double Vector::length(){
	double ans = 0;
	for(int i=0;i<dimension;++i){ //sum of square
		ans += (array[i]*array[i]);
	}
	return sqrt(ans);
}

void Vector::setDimension(int d){
	double *temp = new double[d];
	for(int i=0;i<d;++i){
		if(i > dimension-1){  //when new-dimension larger than old-dimension
			temp[i] = 0;
		}
		else{
			temp[i] = array[i];
		}
	}
	dimension = d;
	delete []array; //delete the old-array and create a new one with new-dimension
	array = new double[dimension];
	for(int i=0;i<dimension;i++){
		array[i] = temp[i]; //set array
	}
}

int Vector::getDimension()const{
	return dimension;
}

//copy constuctor
Vector &Vector::operator=(const Vector &cpyVector){
	const double *temp = cpyVector.get_array();
	dimension = cpyVector.dimension;
	for(int i=0;i<dimension;++i){
		array[i] = temp[i];
	}
	return *this;
}

//overloading - for negetive of Vector
Vector Vector::operator-(){
	double *temp = get_array();
	for(int i=0;i<getDimension();++i){
		temp[i] *= -1;
	}
	Vector negative(getDimension(),temp);
	return negative;
}

//overloading + for sum of Vector
Vector Vector::operator+(Vector scdVector){
	if(dimension != scdVector.getDimension()){
		cout << "Dimensions of these two Vectors are not the same." << endl;
		return *this;
	}
	const double *temp = scdVector.get_array();
	double *tmp = new double[dimension];
	for(int i=0;i<dimension;++i){
		tmp[i] = temp[i] + array[i];
	}
	Vector ans(dimension,tmp);
	return ans;
}

//overloading - for subtraction of Vector
Vector Vector::operator-(Vector scdVector){
	if(dimension != scdVector.getDimension()){
		cout << "Dimensions of these two Vectors are not the same." << endl;
		return *this;
	}
	const double *temp = scdVector.get_array();
	double *tmp = new double[dimension];
	for(int i=0;i<dimension;++i){
		tmp[i] = array[i] - temp[i];
	}
	Vector ans(dimension,tmp);
	return ans;
}

//overloading * for Vector muliply float
Vector Vector::operator*(double m){
	double *temp = new double[dimension];
	for(int i=0;i<dimension;++i){
		temp[i] = array[i] * m;
	}
	Vector ans(dimension,temp);
	return ans;
}

//overloading * for float mutiply Vector
Vector operator*(double m,Vector vector){
	const double *temp = vector.get_array();
	double *tmp = new double[vector.getDimension()];
	for(int i=0;i<vector.getDimension();++i){
		tmp[i] = temp[i] * m;
	}
	Vector ans(vector.getDimension(),tmp);
	return ans;
}

//overloading += for Vectors
Vector &Vector::operator+=(Vector scdVector){
	if(dimension != scdVector.getDimension()){
		cout << "Dimensions of these two Vectors are not the same." << endl;
		return *this;
	}
	const double *tmp = scdVector.get_array();
	for(int i=0;i<dimension;++i){
		array[i] += tmp[i];
	}
	return *this;
}

//overloading -= for Vectors
Vector &Vector::operator-=(Vector scdVector){
	if(dimension != scdVector.getDimension()){
		cout << "Dimensions of these two Vectors are not the same." << endl;
		return *this;
	}
	const double *tmp = scdVector.get_array();
	for(int i=0;i<dimension;++i){
		array[i] -= tmp[i];
	}
	return *this;
}

//overloading *= for Vector and float
Vector &Vector::operator*=(double m){
	for(int i=0;i<dimension;++i){
		array[i] *= m;
	}
	return *this;
}

//overloading == for judge whether the vectors are same
bool Vector::operator==(Vector scdVector){
	const double *tmp = scdVector.get_array();
	for(int i=0;i<dimension;++i){
		if(array[i] != tmp[i]){
			return false;
		}
	}
	return true;
}

//overloading != for judge whether the vectors are not same
bool Vector::operator!=(Vector scdVector){
	const double *tmp = scdVector.get_array();
	for(int i=0;i<dimension;++i){
		if(array[i] == tmp[i]){
			return false;
		}
	}
	return true;
}

//overloading [] for return the n's number in Vector
double Vector::operator[](int n){
	if(n >= dimension){
		cout << "It is out of bound." << endl;
		return 0;
	}
	return array[n];
}
