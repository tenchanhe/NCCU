#include<iostream>
#include"hashtable.h"
using namespace std;

int modPool[21]={1031,2053,4099,8209,16411,32783,65633,131101,262147,524309,1048583,2097169,4194319,8388617,16777259,33554467,67108879,134217757,268435459,536870923,1073741827};

HashTable::HashTable(int n){
    capacity = n;
    
    for(int i=0;i<21;++i){
        if(modPool[i] > capacity){
            modNum = modPool[i];
            break;
        }
    }
    
    table = new Node*[modNum];
    for(int i=0;i<modNum;++i){
        table[i] = NULL;
    }

}

HashTable::~HashTable(){
}

int HashTable::hashfunction(int data){
    int x1=0,x2=0,x3=0,x4=0;
    while(data != 0){
        if(data >= 16777216){
            x1 += data % 16777216;
            data /= 16777216;
        }
        else if(data >= 65536){
            x2 += data % 65536;
            data /= 65536;
        }
        else if(data >= 256){
            x3 += data % 256;
            data /= 256;
        }
        else{
            x4 = data ;
            data = 0;
        }
    }

    int x = (x1*7+x2*13+x3*41+x4*101) % modNum;
    return x;
}

void HashTable::insert(int data){
    int key = hashfunction(data);
    Node *newNode = new Node;
    newNode->value = data;

    if(table[key] == NULL){
        table[key] = newNode;
    }
    else{
        Node *next = table[key]->next;
        table[key]->next = newNode;
        newNode->next = next;
    }

}

bool HashTable::search(int data){
    int key = hashfunction(data);
    Node *current = table[key];      

    while (current != NULL) {           
        if ( current->value == data) {
            return true;
        }
        current = current->next;
    }
    return false;

}

/*void HashTable::rehash(){
    int oldSize = modNum;
    capacity *= 2;

    for(int i=0;i<9592;++i){
        if(modPool[i] > capacity){
            modNum = modPool[i];
            break;
        }
    }

    Node **newtable = new Node *[modNum];    
    for (int i=0;i<modNum;i++) {        
        newtable[i] = NULL;                   
    }

    for (int i=0;i<oldSize;i++) {  
        Node *currentOld = table[i];
        Node *prevOld = NULL;             

        while (currentOld != NULL) {      
    cout << "rehash " << currentOld->value << endl;

            prevOld = currentOld->next; 

            int key = hashfunction(currentOld->value);
    cout << key << ' ' << modNum << endl;
            
            if (newtable[key] == NULL) {
                newtable[key] = currentOld;
                newtable[key]->next = NULL;
            }
            else {                                  
                Node *next = newtable[key]->next;  
                newtable[key]->next = currentOld;
                currentOld->next = next;
            }
            currentOld = prevOld;
        }
    }
    delete [] table;
    this->table = newtable;       
}*/
