#ifndef _TREAP_H                                                                                                                           
#define _TREAP_H
 
struct TreapNode
{
    int key, priority;
    TreapNode *left, *right;
};

TreapNode *rightRotate(TreapNode *y);
TreapNode *leftRotate(TreapNode *x);
TreapNode* newNode(int key);
TreapNode* search(TreapNode* root, int key);
TreapNode* insert(TreapNode* root, int key);
TreapNode* deleteNode(TreapNode* root, int key);
void inorder(TreapNode* root);

#endif       
