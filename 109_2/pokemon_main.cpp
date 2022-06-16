#include<iostream>
#include"pokemon.h"
using namespace std;

int main(void){
    string n;
    double a,d;
    int count=1;
    pokemon* A;
    pokemon* B;
    cin >> n >> a >> d;
    A = new pokemon(n,a,d);
    cin >> n >> a >> d;
    B = new pokemon(n,a,d);

    while(1){
        if(count%2 == 1){
            A->Attack(B);//A attack;
            if(B->isDead() == true){
                cout<<A->getName()<<" win!!!"<<endl;
                //cout<<count<<endl;
                break;
            }
        }
        else{
            B->Attack(A);//B attack;
            if(A->isDead() == true){
                cout<<B->getName()<<" win!!!"<<endl;
                //cout<<count<<endl;
                break;
            }
        }
        ++count;
    }
    return 0;
}
