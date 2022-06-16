#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int n;
typedef struct Node{
    int value;
    struct Node *next;
}node;

void clear(node array[n],node *pos){
    node *ptr1=pos,*ptr2;
    while(ptr1->next != NULL){
        ptr2 = ptr1->next;
        ptr1->next = NULL;
        (array[ptr2->value]).next = ptr2;
        ptr1 = ptr2;
    }
}

node* find(int target,node array[n]){
    //printf("%d\n",target);
    for(int i=0;i<n;++i){
        node* ptr = array[i].next;
        while(ptr != NULL){
            if(ptr->value == target){
                //printf("%d\n",ptr->value);
                return ptr;
            }
            ptr = ptr->next;
        }
    }
    return NULL;
}

int find_array(int target,node array[n]){
    //printf("%d\n",target);
    for(int i=0;i<n;++i){
        node* ptr = array[i].next;
        while(ptr != NULL){
            if(ptr->value == target){
                //printf("%d\n",ptr->value);
                return i;
            }
            ptr = ptr->next;
        }
    }
    return 0;
}
void cut(int target,node array[n]){
    //printf("haah%d\n",target);
    for(int i=0;i<n;++i){
        node* ptr = &array[i];
        //printf("%dAA\n",ptr->value);
        while(ptr->next != NULL){
            if((ptr->next)->value == target){
                ptr->next = NULL;
                break;
            }
            else{
                ptr = ptr->next;
            }
        }
    }
}
int main(void){
    int a,b;
    char move[10],to[10];
    while(scanf("%d\n",&n)!=EOF){
        node array[n];
        for(int i=0;i<n;++i){
            array[i].next = (node*)malloc(sizeof(node));
            (array[i].next)->value = i;
            (array[i].next)->next = NULL;
        }

        while(scanf("%s ",move)!=EOF){
            if(strcmp(move,"quit")==0){
                break;
            }
            scanf("%d %s %d\n",&a,to,&b);
            int x = find_array(a,array);
            int y = find_array(b,array);

            //printf("%d %d\n",x,y);
            if(a==b || x==y){
                continue;
            }

            else if(strcmp(move,"move")==0 && strcmp(to,"onto")==0){
                node *pos;
                pos = find(a,array);
                cut(a,array);
                clear(array,pos);
                node *pos2;
                pos2 = find(b,array);
                clear(array,pos2);
                //printf("%d %d\n",pos->value,pos2->value);
                pos2->next = pos;
            }

            else if(strcmp(move,"move")==0 && strcmp(to,"over")==0){
                node *pos;
                pos = find(a,array);
                cut(a,array);
                clear(array,pos);
                node *ptr;
                ptr = find(b,array);
                while(ptr->next!=NULL){ 
                    ptr = (ptr->next);
                }
                ptr->next = pos;
            }

            else if(strcmp(move,"pile")==0 && strcmp(to,"onto")==0){
                node *pos;
                pos = find(b,array);
                clear(array,pos);
                node *ptr;
                ptr= find(a,array);
                cut(a,array);
                pos->next = ptr;
            }

            else if(strcmp(move,"pile")==0 && strcmp(to,"over")==0){
                //printf("%d %d\n",a,b);
                node *pos;
                pos = find(b,array);
                while(pos->next!=NULL){
                    pos = pos->next;
                }
                node *ptr;
                ptr = find(a,array);
                cut(a,array);
                pos->next = ptr;
            }
        }
        for(int i=0;i<n;++i){
            printf("%d: ",i);
            while(array[i].next !=NULL){
                printf("%d ",(array[i].next)->value);
                array[i].next = (array[i].next)->next;
            }
            printf("\n");
        }
    }
    return 0;
}


