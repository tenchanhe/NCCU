#include<iostream>
#include"Queue.h"
using namespace std;

template <typename T>
Queue<T>::Queue(){
    
    myList = NULL;
    lastNode = NULL;
}

template <typename T>
Queue<T>::~Queue(){
    
    Node *temp;
    while(myList != NULL){
        temp = myList->next;
        delete myList;
        myList = temp;
    }
}

template <typename T>
Queue<T> &Queue::operator=(const Queue &cpyQueue){
    
    Node *curr = cpyQueue;
    while(curr != NULL){
        
        enqueue(curr->value);
        curr = curr->next;
    }
    return *this;
}

template <typename T>
int *Queue<T>::getList(){

    return myList;
}

bool Queue::isEmpty(){

    if(myList == NULL){
        return true;
    }
    return false;
}

template <typename T>
void Queue<T>::enqueue(T data){

    if(isEmpty() == true){
        
        myList = new Node;
        myList->value = data;
        myList->next = NULL;
        lastNode = myList;
    }
    else{
        
        lastNode->next = new Node;
        lastNode = lastNode->next;
        lastNode->value = data;
        lastNode->next = NULL;
    }
}

template <typename T>
void Queue<T>::dequeue(){

    Node *temp;
    while(isEmpty() == false){
        
        temp = myList->next;
        cout << myList->value << endl;
        delete myList;
        myList = temp;
    }
}
