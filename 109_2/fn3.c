#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int main(void){
    char array[30],array2[30];
    int n;
    gets(array);
    n=strlen(array);
    int a=n-1;
    for(int i=0;i<n;++i){
        array2[a]=array[i];
        --a;
    }
    int count=0;
    for(int i=0;i<n;++i){
        if(array[i]!=array2[i]){
            array[i]=' ';
        }
        else{
            ++count;
        }
    }
    printf("%d\n",count);
    if(count==0){
        printf("%c\n",array2[0]);
        return 0;
    }
    for(int i=0;i<n;++i){
        if(array[i]!=' '){
            printf("%c",array[i]);
        }
    }
    printf("\n");
    return 0;
}
