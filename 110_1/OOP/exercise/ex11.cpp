#include<iostream>
#include<math.h>
using namespace std;

int main(){
    double a1,a2;
    while(cin >> a1 >> a2){
        try{
            if(a1 < 0 || a2 < 0){
                throw "Bad Arguments: a1 < 0, a2 < 0 not allowed!";
            }
            cout.precision(3);
            cout << "Geometric mean of " << a1 << " and " << a2 << " is " << sqrt(a1)*sqrt(a2) << endl;
        }
        catch(const char *error){
            cout << error << endl;
        }

        try{
            if(a1 == -a2){
                throw "Bad Arguments: a1 = -a2 not allowed!";
            }
            cout.precision(3);
            cout << "Harmonic mean of " << a1 << " and " << a2 << " is " << (2*a1*a2)/(a1+a2) << endl;
        }
        catch(const char *error){
            cout << error << endl;
        }
    }
    return 0;
}
