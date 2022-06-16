#ifndef _WORLD_H
#define _WORLD_H
#include"Creature.h"
#include"Goat.h"
#include"Grass.h"

class World{

	public:
		World(int in_numPasses,int in_seed);
        ~World();
		
        void mainLoop(int displayIntervsl); //建構子
		void worldBorn();
		void display();
        void dailyLife();

	private:
		int seed;
		int numPasses;
		Creature *magic_map[20][35];
        bool doneWork;
};

#endif
