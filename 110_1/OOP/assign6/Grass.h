#ifndef _GRASS_H
#define _GRASS_H
#include"Creature.h"

class Grass:public Creature{

	public:
		Grass(int x,int y);
        ~Grass();

		void reproduction(Creature *map[20][35],int born);
        void move(Creature *map[20][35],int step);
		int isWho();

	private:
};

#endif
