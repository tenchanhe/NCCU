#ifndef _QUEUE_H
#define _QUEUE_H

template <typename T>
struct Node{
    
    T value;
    Node  *next;
};

template <typename T>
class Queue{
	
    public:
        Queue();
        ~Queue();
        Queue &operator=(const Queue &cpyQueue);
        T *getList();
        bool isEmpty();
        void enqueue(T data);
        void dequeue();

	private:
        Node *myList;
        Node *lastNode;

};
#endif
