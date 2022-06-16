#include<iostream>
#include<string.h>
#include<cstdlib>
#include<fstream>
using namespace std;

class Person{
	public:
		Person(){};
		Person(long long int in_id,char in_name[20]){ID=in_id;strcpy(name,in_name);};
		~Person(){};
		long long int getID(){return ID;};
		char *getName(){return name;};

	private:
		long long ID;
		char name[20];
};

int main(){
	int n=0;
	long long int in_id;
    char in_name[20];
	Person *book[1000];
    Person *temp;
	
    while(cin >> in_id >> in_name){
		book[n] = new Person(in_id,in_name);
		++n;
	}

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;++j){
            if (book[j]->getID() > book[j+1]->getID()){
                temp = book[j];
                book[j] = book[j+1];
                book[j+1] = temp;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout.width(10);
        cout << left << book[i]->getID();
        cout << ' ';
        cout.width(10);
        cout << left << book[i]->getName();
        cout << '*' << endl;
    }
	
	/*int n=0;
    long long int in_id;
    char in_name[20];
	Person *book[1000],*temp;
    char input[100000];
    fstream myfile;
	
    myfile.open("source.txt",ios::in);
	if(!myfile.is_open()){
		cout << "open failed" << endl;
	}
	
	myfile.getline(input,sizeof(input));

	char *token;
	const char *key = " ";
	int flag = 0;
	
	token = strtok(input,key);
	while(token != NULL){    
        if(flag == 0){
			in_id = atoll(token);
			flag = 1;
		}
		else if(flag == 1){
			strcpy(in_name,token);
			book[n] = new Person(in_id,in_name);
			++n;
			flag = 0;
		}
		token = strtok(NULL,key);
    }
    myfile.close();
    myfile.open("result.txt",ios::out);

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;++j){
            if (book[j]->getID() > book[j+1]->getID()){
                temp = book[j];
                book[j] = book[j+1];
                book[j+1] = temp;
            }
        }
    }
    for(int i=0;i<n;++i){
        myfile.width(10);
        myfile << left << book[i]->getID();
        myfile << ' ';
        myfile.width(10);
        myfile << left << book[i]->getName();
        myfile << '*' << endl;
    }*/

	return 0;
}
