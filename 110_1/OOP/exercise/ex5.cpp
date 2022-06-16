#include<iostream>
#include<list>
using namespace std;

class student{
	public:
		student();
		student(string name_,list<int> score_):name(name_),score(score_){}
		~student();
	private:
		string name;
		list<int> score;
};

student::student(){
}

student::~student(){
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
			in_score.sort();
			student Std(in_name,in_score);
			myclass.push_front(Std);
		}
	}
	return 0;
}
