#include <iostream>
using namespace std;

class App {

	public:
		App(int d) { download = d; }
		~App() {};

		int getDownload() { return download; }
		void increaseDownload() { ++download; }

	private:
		int download;

};

class JJBox:public App{
	public:
		JJBox(int dload):App(dload){};
		void renewsongs(){ songs = getDownload() * 5; }
		int showsongs(){ return songs; }
	private:
		int songs;
};

class NoseBook:public App{
	public:
		NoseBook(int dload):App(dload){};
		void renewfriends(){ friends = (getDownload() * 3)+5; }
		int showfriends(){return friends; }
	private:
		int friends;
};

int main(){
	int dload,comand;
	
	cin >> dload;
	JJBox jjbox(dload);
	jjbox.renewsongs();

	cin >> dload;
	NoseBook nosebook(dload);
	nosebook.renewfriends();

	cin >> comand;
	while(comand != -1){
		switch(comand){
			case 1:
				jjbox.increaseDownload();
				cout << "JJBox now has " << jjbox.showsongs() << " songs." << endl;
				cout << "NoseBook now has " << nosebook.showfriends() << " friends." << endl;
				cout << "==========" << endl;
				break;
			
			case 2:
				nosebook.increaseDownload();
				cout << "JJBox now has " << jjbox.showsongs() << " songs." << endl;
				cout << "NoseBook now has " << nosebook.showfriends() << " friends." << endl;
				cout << "==========" << endl;
				break;
			
			case 3:
				jjbox.increaseDownload();
				nosebook.increaseDownload();
				cout << "JJBox now has " << jjbox.showsongs() << " songs." << endl;
				cout << "NoseBook now has " << nosebook.showfriends() << " friends." << endl;
				cout << "==========" << endl;
				break;
			
			case 4:
				jjbox.renewsongs();
				cout << "JJBox now has " << jjbox.showsongs() << " songs." << endl;
				cout << "NoseBook now has " << nosebook.showfriends() << " friends." << endl;
				cout << "==========" << endl;
				break;
			
			case 5:
				nosebook.renewfriends();
				cout << "JJBox now has " << jjbox.showsongs() << " songs." << endl;
				cout << "NoseBook now has " << nosebook.showfriends() << " friends." << endl;
				cout << "==========" << endl;
				break;
			
			default:
				break;
		}
		cin >> comand;
	}
	return 0;
}
