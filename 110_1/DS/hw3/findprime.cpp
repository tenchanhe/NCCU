#include <iostream>
using namespace std;
 
int main () 
{
        for (int i=1073741824;i<1273741824; i++){
            for (int j=2; j<i; j++)
            {
                if (i % j == 0){ 
                    break;
                }
                else if (i == j+1){
                    cout << i << " ";
                    break;
                }
            }   
        }
    return 0;
}
