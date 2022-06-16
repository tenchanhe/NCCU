#include<iostream>
#include"Goat.h"
#include"Creature.h"
#include"RandomNum.h"
using namespace std;

Goat::Goat(int x,int y):Creature(x,y){

    setEnergy(20);
}

Goat::~Goat(){
}

void Goat::reproduction(Creature *map[20][35],int born){

    switch(born){
        
        case 0: //up
            
            if(row-1 >= 0){

                if(map[row-1][column] == NULL){
                    map[row-1][column] = new Goat(column,row-1);
                    map[row-1][column]->setDonework(doneWork);
                }
                else if(map[row-1][column]->isWho() == 1){
                    addEnergy(5);
                    delete map[row-1][column];
                    map[row-1][column] = new Goat(column,row-1);
                    map[row-1][column]->setDonework(doneWork);
                }
                else{
                }
            }
            break;
        
        case 1: //down
            
            if(row+1 < 20){

                if(map[row+1][column] == NULL){
                    map[row+1][column] = new Goat(column,row+1);
                    map[row+1][column]->setDonework(doneWork);
                }
                else if(map[row+1][column]->isWho() == 1){
                    addEnergy(5);
                    delete map[row+1][column];
                    map[row+1][column] = new Goat(column,row+1);
                    map[row+1][column]->setDonework(doneWork);
                }
                else{
                }
            }
            break;
        
        case 2: //left
            
            if(column-1 >= 0){

                if(map[row][column-1] == NULL){
                    map[row][column-1] = new Goat(column-1,row);
                    map[row][column-1]->setDonework(doneWork);
                }
                else if(map[row][column-1]->isWho() == 1){
                    addEnergy(5);
                    delete map[row][column-1];
                    map[row][column-1] = new Goat(column-1,row);
                    map[row][column-1]->setDonework(doneWork);
                }
                else{
                }
            }
            break;
        
        case 3: //right
            
            if(column+1 < 35){

                if(map[row][column+1] == NULL){
                    map[row][column+1] = new Goat(column+1,row);
                    map[row][column+1]->setDonework(doneWork);
                }
                else if(map[row][column+1]->isWho() == 1){
                    addEnergy(5);
                    delete map[row][column+1];
                    map[row][column+1] = new Goat(column+1,row);
                    map[row][column+1]->setDonework(doneWork);
                }
                else{
                }
            }
            break;
        
	    default:
            break;
    }
}

void Goat::move(Creature *map[20][35],int step){
    
    //cout <<"row="<<row<<" clm="<<column<<" step="<<step<<endl;
    switch(step){
        
        case 0: //up
            
            if(row-1 >= 0){
            
                if(map[row-1][column] == NULL){
                    map[row-1][column] = map[row][column];
                    map[row][column] = NULL;
                    --row;
                }
                else if(map[row-1][column]->isWho() == 1){
                    addEnergy(5);
                    delete map[row-1][column];
                    map[row-1][column] = map[row][column];
                    map[row][column] = NULL;
                    --row;
                }
                else{
                }
            }
            break;
        
        case 1: //down
            
            if(row+1 < 20){
            
                if(map[row+1][column] == NULL){
                    map[row+1][column] = map[row][column];
                    map[row][column] = NULL;
                    ++row;
                }
                else if(map[row+1][column]->isWho() == 1){
                    addEnergy(5);
                    delete map[row+1][column];
                    map[row+1][column] = map[row][column];
                    map[row][column] = NULL;
                    ++row;
                }
                else{
                }
            }
            break;
        
        case 2: //left
            
            if(column-1 >= 0){

                if(map[row][column-1] == NULL){
                    map[row][column-1] = map[row][column];
                    map[row][column] = NULL;
                    --column;
                }
                else if(map[row][column-1]->isWho() == 1){
                    addEnergy(5);
                    delete map[row][column-1];
                    map[row][column-1] = map[row][column];
                    map[row][column] = NULL;
                    --column;
                }
                else{
                }
            }
            break;
        
        case 3: //right
            
            if(column+1 < 35){

                if(map[row][column+1] == NULL){
                    map[row][column+1] = map[row][column];
                    map[row][column] = NULL;
                    ++column;
                }
                else if(map[row][column+1]->isWho() == 1){
                    addEnergy(5);
                    delete map[row][column+1];
                    map[row][column+1] = map[row][column];
                    map[row][column] = NULL;
                    ++column;
                }
                else{
                }
            }
            break;
        
        default:
            break;
    }
}

int Goat::isWho(){

	return 0;
}
