#include<iostream>
#include<list>
using namespace std;

class student{
	public:
		student();
		student(string name_,list<int> score_):name(name_),score(score_){}
		~student();
        void find_avr(int n);
        float get_avr();
        string get_name();
        void show_score();
	private:
		string name;
		list<int> score;
        float avrscore;
};

student::student(){
}

student::~student(){
}

void student::find_avr(int n){
    float total = 0;
    for(auto it=score.begin();it!=score.end();it++){
        total += *it;
    }
    avrscore = total/n;
}

float student::get_avr(){
    return avrscore;
}

string student::get_name(){
    return name;
}

void student::show_score(){
    for(auto it=score.begin();it!=score.end();it++){
        cout << *it << ' ' ;
    }
}

int main(void){
	int nclass,nstudents,nsubjects,tmp;
	string in_name;
	cin >> nclass;

	for(int i=0;i<nclass;++i){
		cin >> nstudents >> nsubjects;
		list<student> myclass;
		list<int> in_score;

		for(int k=0;k<nstudents;++k){
			cin >> in_name;
			for(int j=0;j<nsubjects;++j){
				cin >> tmp;
				in_score.push_front(tmp);
			}
			in_score.sort([](int a,int b){return a>b;});
			/*for(auto it=in_score.begin();it!=in_score.end();it++){
                cout << *it << ' ';
            }
            cout << endl;*/
            student Std(in_name,in_score);
            Std.find_avr(nsubjects);
            //cout << Std.get_avr() << endl;
			myclass.push_front(Std);
            in_score.clear();
		}
        myclass.sort([](student a,student b){return a.get_avr()>b.get_avr();});
        for(auto it=myclass.begin();it!=myclass.end();it++){
            cout << it->get_name() << ':';
            it->show_score();
            cout << it->get_avr() << endl;
        }
        cout << "==========" << endl;
        myclass.clear();
	}
	return 0;
}
