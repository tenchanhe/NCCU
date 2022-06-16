#include<iostream>
#include"Grass.h"
#include"Creature.h"
#include"RandomNum.h"
using namespace std;

Grass::Grass(int x,int y):Creature(x,y){
}

Grass::~Grass(){
}

void Grass::reproduction(Creature *map[20][35],int born){

    switch(born){
        
        case 0: //up
            
            if(row-1 >= 0 && map[row-1][column] == NULL){
                map[row-1][column] = new Grass(column,row-1);
                map[row-1][column]->setDonework(doneWork);
            }
            else{
            }
            break;
        
        case 1: //down
            
            if(row+1 < 20 && map[row+1][column] == NULL){
                map[row+1][column] = new Grass(column,row+1);
                map[row+1][column]->setDonework(doneWork);
            }
            else{
            }
            break;
        
        case 2: //left
            
            if(column-1 >= 0 && map[row][column-1] == NULL){
                map[row][column-1] = new Grass(column-1,row);
                map[row][column-1]->setDonework(doneWork);
            }
            else{
            }
            break;
        
        case 3: //right
            
            if(column+1 < 35 && map[row][column+1] == NULL){
                map[row][column+1] = new Grass(column+1,row);
                map[row][column+1]->setDonework(doneWork);
            }
            else{
            }
            break;
        
        default:
            break;
    }
}

void Grass::move(Creature *map[20][35],int seed){
}

int Grass::isWho(){

	return 1;
}
