#ifndef _GOAT_H
#define _GOAT_H
#include"Creature.h"

class Goat:public Creature{

	public:
		Goat(int x,int y);
        ~Goat();

		void reproduction(Creature *map[20][35],int born);
        void move(Creature *map[20][35],int step);
		int isWho();

	private:
};

#endif
