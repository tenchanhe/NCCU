#include<iostream>
#include"pokemon.h"
using namespace std;
pokemon::pokemon(string n,double atk,double def){
    name = n;
    attack = atk;
    defense = def;
}
pokemon::~pokemon(){
}
string pokemon::getName(){
    return name;
}
double pokemon::getAtk(double deduct){;
    attack -= deduct;
    return attack;
}
double pokemon::getDef(double deduct){
    defense -= deduct;
    return defense;
}
bool pokemon::isDead(){
    if(defense < 0)
        return true;
    else
        return false;
}

void pokemon::Attack(pokemon* D){
    D->getAtk(-(D->getAtk(0)*0.1));
    if(this->getAtk(0) >= D->getDef(0)){
        this->getAtk((this->getAtk(0) - D->getDef(0))*0.1);
        D->getDef((this->getAtk(0) - D->getDef(0))*0.5);
    }
    else{
        D->getDef((D->getDef(0) - this->getAtk(0))*0.2);
        this->getAtk(this->getAtk(0)*0.5);
    }
}
