#include <iostream>
using namespace std;

class superman {
	public:
		superman();
		superman(string in_category,string in_name,int in_hp,float in_atk,float in_def);
		~superman();

		int doAtk();
		int beAtked(int be_atk_value);
		int showHP();

	private:
		string category;
		string name;
		int hp;
		float atk;
		float def;

};

// Initialization function
superman::superman() {
	category = "";
	name = "";
	hp = -1;
	atk = -1;
	def = -1;
}

superman::superman(string in_category,string in_name,int in_hp,float in_atk,float in_def){
	category = in_category;
	name = in_name;
	hp = in_hp;
	atk = in_atk;
	def = in_def;
}

// Finalization function
superman::~superman() {

}

int superman::doAtk() {
	return (atk+hp)/2;
}

int superman::beAtked(int be_atk_value) {
	return (2*be_atk_value)/def;
}

int superman::showHP(){
	return hp;
}

int main(){
	string Cat,Name;
	int Hp;
	float Atk,Def,enemy_damage;
	char event;
	while(cin >> Cat){
		cin >> Name >> Hp >> Atk >> Def >> event;
		if(Hp < 0) Hp = 0;
		if(Atk < 0) Atk = 0;
		if(Def < 0) Def = 0;;
		if(event == 'B'){
			cin >> enemy_damage;
		}
		if(enemy_damage < 0) enemy_damage = 0;
		//cout << Name << Hp << Atk << Def << event;
		superman Hero(Cat,Name,Hp,Atk,Def);

		if(event == 'A'){
			Atk = Hero.doAtk() ;
			cout << Cat << ' ' << Name << " caused " << Atk << " points damage" << endl;
		}
		else if(event == 'B'){
			if(Def <= 0){
				Atk = 0;
			}
			else{
				Atk = Hero.beAtked(enemy_damage);
			}
			cout << Cat << ' ' << Name << " is damaged by " << Atk << " points" << endl;
		}
		else if(event == 'C'){
			Hp = Hero.showHP();
			cout << Cat << ' ' << Name << " currently has " << Hp << " points of HP" << endl;
		}
	}
	return 0;
}
