#ifndef _CREATURE_H
#define _CREATURE_H

class Creature{

	public:
		Creature();
		Creature(int x,int y);
        virtual ~Creature();
		
        void setEnergy(int in_energy);
        int getAge();
        void addAge();
        void addEnergy(int food);
        int getEnergy();
        void setDonework(bool in_done);
        bool getDonework();
        
        virtual void reproduction(Creature *map[20][35],int seed);
		virtual void move(Creature *map[20][35],int seed);
		virtual int isWho();

    protected:
        int row;
        int column;
        bool doneWork;

    private:
		int age;
        int energy;
};

#endif
