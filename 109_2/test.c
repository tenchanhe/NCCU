#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define Max(a,b) ((a)>(b)?(a):(b))

typedef struct Node{
    int value;
    struct Node *next;
}node;
int main(void){
    node *first=(node*)malloc(sizeof(node));
    first->value=10;
    first->next=NULL;
    printf("%d\n",first->value);
    return 0;
}
