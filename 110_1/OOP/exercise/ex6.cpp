#include <iostream>
using namespace std;

class Complex {
public:
    friend ostream& operator<<(ostream&, const Complex&);
    friend istream& operator>>(istream&, Complex&);
    Complex(){};
    Complex(double _Real, double _imaginary){Real = _Real; Imaginary = _imaginary;};

    Complex operator+=(Complex c);
    Complex operator+(Complex c);
    Complex operator-(Complex c);
    Complex operator*(Complex c);

    Complex operator++();
    Complex operator++(int);
    Complex operator--();
    Complex operator--(int);

    bool operator>(Complex c);
    bool operator<(Complex c);
    bool operator==(Complex c);
private:
    double Real;
    double Imaginary;
};

istream& operator>>( istream& in, Complex& c)
{
    in >> c.Real >> c.Imaginary;
    return in;
}
ostream& operator<<(ostream& out, const Complex& c)
{
    if(c.Imaginary<0){
        out << c.Real << c.Imaginary << "i";
        return out;
    }else{
        out << c.Real << "+" << c.Imaginary << "i";
        return out;
    }

}
Complex Complex::operator+=(Complex c) {
	this->Real += c.Real;
	this->Imaginary += c.Imaginary;
	return *this;
}
Complex Complex::operator+(Complex c) {
	return Complex(this->Real+c.Real,this->Imaginary+c.Imaginary);
}
Complex Complex::operator-(Complex c) {
	return Complex(this->Real-c.Real,this->Imaginary-c.Imaginary);
}
Complex Complex::operator*(Complex c) {
	return Complex(this->Real*c.Real-this->Imaginary*c.Imaginary,this->Imaginary*c.Real+this->Real*c.Imaginary);
}

Complex Complex::operator++() { //++i
	this->Real += 1;
	this->Imaginary +=1;
	return *this;
}
Complex Complex::operator++(int) { //i++
	Complex temp;
	temp.Real = this->Real;
	temp.Imaginary = this->Imaginary;
	this->Real += 1;
	this->Imaginary +=1;
	return temp;
}
Complex Complex::operator--() {
	this->Real -= 1;
	this->Imaginary -=1;
	return *this;
}
Complex Complex::operator--(int) {
	Complex temp;
	temp.Real = this->Real;
	temp.Imaginary = this->Imaginary;
	this->Real -= 1;
	this->Imaginary -=1;
	return temp;
}
bool Complex::operator>(Complex c){
	if(this->Real > c.Real){
		return true;
	}
	else if(this->Real == c.Real){
		if(this->Imaginary > c.Imaginary){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}

bool Complex::operator<(Complex c){
	if(this->Real < c.Real){
		return true;
	}
	else if(this->Real == c.Real){
		if(this->Imaginary < c.Imaginary){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}
bool Complex::operator==(Complex c){
	if(this->Real == c.Real && this->Imaginary == c.Imaginary){
		return true;
	}
	else{
		return false;
	}
}
int main() {
    Complex C1, C2;
    while( cin >> C1 >> C2 ) {
        cout << "C1 = " << C1 << endl;
        cout << "C2 = " << C2 << endl;

        cout << "C1==C2? " << ((C1==C2)?"true":"false") << endl;
        cout << "C1<C2?  " << ((C1<C2)?"true":"false") << endl;
        cout << "C1>C2?  " << ((C1>C2)?"true":"false") << endl;

        cout << "C1+C2 = " << C1+C2 << endl;
        cout << "C1-C2 = " << C1-C2 << endl;
        cout << "C1*C2 = " << C1*C2 << endl;
        cout << "C1++  = " << C1++ << endl;
        cout << "C1++  = " << C1++ << endl;
        cout << "++C1  = " << ++C1 << endl;
        cout << "++C1  = " << ++C1 << endl;
        cout << "C2--  = " << C2-- << endl;
        cout << "C2--  = " << C2-- << endl;
        cout << "--C2  = " << --C2 << endl;
        cout << "--C2  = " << --C2 << endl;

        C1+=C2;
        cout << "C1+=C2  " << C1 << endl;
        cout << "==============" << endl;
    }
    return 0;
}
