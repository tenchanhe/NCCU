#include<iostream>
using namespace std;
class student{
    public:
        student();
        ~student();
        void inid(int a);
        void inex1(int b);
        void inex2(int c);
        void inex3(int d);
        void inex4(int e);
        void inex5(int f);
        int getid();
        int getex1();
        int getex2();
        int getex3();
        int getex4();
        int getex5();
        int getaverage();
    private:
        int id;
        int ex1;
        int ex2;
        int ex3;
        int ex4;
        int ex5;
};
student::student(){
}
student::~student(){
}
void student::inid(int a){
    id = a;
}
void student::inex1(int b){
    ex1 = b;
}
void student::inex2(int c){
    ex2 = c;
}
void student::inex3(int d){
    ex3 = d;
}
void student::inex4(int e){
    ex4 = e;
}
void student::inex5(int f){
    ex5 = f;
}
int student::getid(){
    return id;
}
int student::getex1(){
    return ex1;
}
int student::getex2(){
    return ex2;
}
int student::getex3(){
    return ex3;
}
int student::getex4(){
    return ex4;
}
int student::getex5(){
    return ex5;
}
int student::getaverage(){
    return (ex1+ex2+ex3+ex4+ex5)/5;
}

int main(){
    student Student[70];
    int studentid,ex1,ex2,ex3,ex4,ex5;
    for(int i=0;i<65;++i){
        cin >> studentid >> ex1 >> ex2 >> ex3 >> ex4 >> ex5;
        Student[i].inid(studentid);
        Student[i].inex1(ex1);
        Student[i].inex2(ex2);
        Student[i].inex3(ex3);
        Student[i].inex4(ex4);
        Student[i].inex5(ex5);
    }
    for(int i=0;i<65;++i){
        cout << Student[i].getid() <<" "<< Student[i].getex1() <<" "<< Student[i].getex2() <<" "<< Student[i].getex3() <<" "<< Student[i].getex4() <<" "<< Student[i].getex5() <<" average= "<< Student[i].getaverage() << endl;
    }
    return 0;
}
