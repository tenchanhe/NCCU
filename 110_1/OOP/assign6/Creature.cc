#include<iostream>
#include"Creature.h"
#include"RandomNum.h"
using namespace std;

Creature::Creature(){
}

Creature::Creature(int x,int y){
	
	row = y;
	column = x;
	age = -1;
    energy = 21;
    doneWork = true;
}

Creature::~Creature(){
}

void Creature::setEnergy(int in_energy){
    
    energy = in_energy;
}

int Creature::getAge(){
    
    return age;
}

void Creature::addAge(){

    ++age;
}

void Creature::addEnergy(int food){

    energy += food;
}

int Creature::getEnergy(){

    return energy;
}

void Creature::setDonework(bool in_done){

    doneWork = in_done;
}

bool Creature::getDonework(){

    return doneWork;
}

void Creature::reproduction(Creature *map[20][35],int seed){
}

void Creature::move(Creature *map[20][35],int seed){
}

int Creature::isWho(){
	
    return -1;
}

