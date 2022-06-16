#ifndef _HASHTABLE_H                                                                                                                           
#define _HASHTABLE_H
 
struct Node{
    int value;
    Node *next;
};

class HashTable{
    public:
        HashTable(int n);
        ~HashTable();
        int hashfunction(int data);
        void insert(int data);
        bool search(int data);

    private:
        int capacity;
        int modNum;
        Node **table;
};
#endif       
