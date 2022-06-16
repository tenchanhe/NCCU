#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class person{
    public:
        person(string n);
        ~person();
        void inname(string N);
		string getName();
    private:
        string name;
};

person::person(string n){
    name = n;
}

person::~person(){
}

void person::inname(string N){
	name = N;
}

string person::getName(){
    return name;
}

class person1:public person{
    public:
        person1(string n,string g);
        ~person1();
        void ingender(string G);
		string getGender();
    private:
        string gender;
};

person1::person1(string n,string g):person(n){
    gender = g;
}

person1::~person1(){
}

void person1::ingender(string G){
	gender = G;
}

string person1::getGender(){
    return gender;
}

class person2:public person{
    public:
        person2(string n,string b,string c,string j);
        ~person2();
        void inbirth(string B);
		void incountry(string C);
		void injob(string J);
		string getBirth();
        string getCountry();
        string getJob();
    private:
        string birth;
        string country;
        string job;
};

person2::person2(string n,string b,string c,string j):person(n){
    birth = b;
    country = c;
    job = j;
}

person2::~person2(){
}

void person2::inbirth(string B){
	birth = B;
}
void person2::incountry(string C){
	country = C;
}
void person2::injob(string J){
	job = J;
}
string person2::getBirth(){
    return birth;
}

string person2::getCountry(){
    return country;
}

string person2::getJob(){
    return job;
}

class person3:public person2{
    public:
        person3(string n,string b,string c,string j,string B);
        ~person3();
        void inball(string bb);
		string getBall();
    private:
        string ball;
};

person3::person3(string n,string b,string c,string j,string B):person2(n,b,c,j){
    ball = B;
}

person3::~person3(){
}

void person3::inball(string bb){
	ball = bb;
}
string person3::getBall(){
    return ball;
}

int main(){
    string name,gender,birth,country,job,ball;
    int flag=1;
	char *p;
    char tmp[100];
    const char* d=",";
    ifstream ifs;
    person1* a[25];
    person2* b[25];
    person3* c[25];
	ifs.open("name.txt");
    for(int i=0;i<25;++i){
        ifs.getline(tmp,sizeof(tmp));
        p=strtok(tmp,d);
		while(p!=NULL){
			if(flag==1){
				name=p;
                flag=2;
			}
			else if(flag==2){
				gender=p;
                flag=1;
			}
            p=strtok(NULL,d);
        }
        a[i]=new person1(name,gender);
    }
	//cout<<a[1]->getName()<<" "<<a[1]->getGender()<<endl;
    for(int i=0;i<25;++i){
        ifs.getline(tmp,sizeof(tmp));
        p=strtok(tmp,d);
        while(p!=NULL){
            if(flag==1){
                name=p;
                flag=2;
            }
            else if(flag==2){
                birth=p;
                flag=3;
            }
            else if(flag==3){
                country=p;
                flag=4;
            }
            else if(flag==4){
                job=p;
                flag=5;
            }
            else if(flag==5){
                ball=p;
                flag=1;
            }
            p=strtok(NULL,d);
        }
        c[i]=new person3(name,birth,country,job,ball);
    }
    //cout<<c[0]->getName()<<endl<<c[0]->getBirth()<<endl<<c[0]->getCountry()<<endl<<c[0]->getJob()<<endl<<c[0]->getBall()<<endl;
    for(int i=0;i<25;++i){
        ifs.getline(tmp,sizeof(tmp));
        p=strtok(tmp,d);
        while(p!=NULL){
            if(flag==1){
                name=p;
                flag=2;
            }
            else if(flag==2){
                birth=p;
                flag=3;
            }
            else if(flag==3){
                country=p;
                flag=4;
            }
            else if(flag==4){
                job=p;
                flag=1;
            }
            p=strtok(NULL,d);
        }
        b[i]=new person2(name,birth,country,job);
    }
    //cout<<b[0]->getName()<<endl<<b[0]->getBirth()<<endl<<b[0]->getCountry()<<endl<<b[0]->getJob()<<endl;
    for(int i=0;i<25;++i){
        cout<<a[i]->getName()<<endl<<a[i]->getGender()<<endl<<endl;
    }
    for(int i=0;i<25;++i){
        cout<<c[i]->getName()<<endl<<c[i]->getBirth()<<endl<<c[i]->getCountry()<<endl<<c[i]->getJob()<<endl<<c[i]->getBall()<<endl<<endl;
    }
    for(int i=0;i<25;++i){
        cout<<b[i]->getName()<<endl<<b[i]->getBirth()<<endl<<b[i]->getCountry()<<endl<<b[i]->getJob()<<endl<<endl;
    }
    ifs.close();
    return 0;
}
