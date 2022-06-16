#include<iostream>
#include"Creature.h"
#include"World.h"
#include"Goat.h"
#include"Grass.h"
#include"RandomNum.h"
using namespace std;

World::World(int in_numPasses,int in_seed){
	
	seed = in_seed;
	numPasses = in_numPasses;
    doneWork = true;

    for(int i=0;i<20;++i){
        for(int j=0;j<35;++j){
            magic_map[i][j] = NULL;
        }
    }
	worldBorn();
}

World::~World(){
}

void World::mainLoop(int displayIntervsl){
	
	for(int i=0;i<numPasses;++i){
        if(i % displayIntervsl == 0){
		    cout <<endl<< "numPasses= " << i << endl;
			display();
		}
        dailyLife();
        
        if(doneWork == true){
            doneWork = false;
        }
        else{
            doneWork = true;
        }
    }
}

void World::worldBorn(){

	RandomNum birth_place(seed);
	int x,y;
	int flag_x[35] = {0},flag_y[35] = {0};
	
	for(int i=0;i<5;++i){
		
		x = birth_place.getRandomNum(0,34);
		y = birth_place.getRandomNum(0,19);
		
		if(flag_x[x] == 1 && flag_y[y] == 1){
		
			--i;
		}
		else{
		
			flag_x[x] = 1;
		   	flag_y[y] = 1;
            magic_map[y][x] = new Goat(x,y);
            cout << " x=" << x << " y=" << y << endl;
		}
	}
	
	for(int i=0;i<10;++i){
		
		x = birth_place.getRandomNum(0,34);
		y = birth_place.getRandomNum(0,19);
		
		if(flag_x[x] == 1 && flag_y[y] == 1){
		
			--i;
		}
		else{
		
			flag_x[x] = 1;
		   	flag_y[y] = 1;
            magic_map[y][x] = new Grass(x,y);
            cout << " x=" << x << " y=" << y << endl;
		}
	}
    cout << endl;
}

void World::display(){

    int x = 0,y = 0;

    for(int i=0;i<37;++i){
        
        if(i == 0 || i == 1){
            cout << ' ';
        }
        else{
            if(x >= 10){
                x = 0;
            }
            cout << x << ' ';
            ++x;
        }
    }
    cout << endl;
    
    for(int i=0;i<20;++i){
        for(int j=0;j<35;++j){

            if(j == 0){
                if(y >= 10){
                    y = 0;
                }
                cout << y << ' ';
                ++y;
            }

            if(magic_map[i][j] != NULL){

                if(magic_map[i][j]->isWho() == 0){
                    cout << "X ";
                }
                else if(magic_map[i][j]->isWho() == 1){
                    cout << "I ";
                }
            }
            else{
                cout << "  ";
            }
        }
        cout << endl;
    }
	cout << "------------------------------------------------------------------------" << endl;
}

void World::dailyLife(){

    RandomNum randStep(seed);
    ++seed;

    for(int i=0;i<20;++i){
        for(int j=0;j<35;++j){

            if(magic_map[i][j] != NULL && magic_map[i][j]->getDonework() == doneWork){
                magic_map[i][j]->addEnergy(-1);
                magic_map[i][j]->addAge();

                if(doneWork == true){
                    magic_map[i][j]->setDonework(false);
                }
                else{
                    magic_map[i][j]->setDonework(true);
                }
                
                if(magic_map[i][j]->isWho() == 0){

                    if(magic_map[i][j]->getAge() >= 50 && magic_map[i][j]->getAge() <= 55){
                        //cout << "re="<<a++ << endl;
                        magic_map[i][j]->reproduction(magic_map,randStep.getRandomNum(0,3));
                    }
                    else if(magic_map[i][j]->getAge() >= 70 || magic_map[i][j]->getEnergy() <= 0){
                        delete magic_map[i][j];
                        magic_map[i][j] = NULL;
                    }
                    else{
                        //cout << "move="<<a++ << endl;
                        magic_map[i][j]->move(magic_map,randStep.getRandomNum(0,3));
                    }
                }
                else if(magic_map[i][j]->isWho() == 1){

                    if(magic_map[i][j]->getAge() >= 3 && magic_map[i][j]->getAge() <= 5){
                        magic_map[i][j]->reproduction(magic_map,randStep.getRandomNum(0,3));
                    }
                    else if(magic_map[i][j]->getAge() >= 6){
                        delete magic_map[i][j];
                        magic_map[i][j] = NULL;
                    }
                }
            }
        }
    }
}
