#ifndef POKEMON_H
#define POKEMON_H
#include<iostream>
using namespace std;

class pokemon{
    public:
        pokemon(string n,double atk,double def);
        ~pokemon();
        string getName();
        double getAtk(double decuct);
        double getDef(double decuct);
        bool isDead();
        void Attack(pokemon* D);

    private:
        string name;
        double attack;
        double defense;
};

#endif
