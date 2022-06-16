#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int main(void){
    char array[30];
    int n=0;
    while(scanf("%c",&array[n])!=EOF){
        ++n;
    }
    //printf("%d\n",n);
    int right=0,left=0;
    for(int i=0;i<n;++i){
        if(array[i]=='('){
            left++;
        }
        else if(array[i]==')'){
            right++;
        }
        else{
            continue;
        }
        if(right>left){
            array[i]='*';
            right--;
        }
    }
    left=0,right=0;
    for(int i=n-1;i>=0;--i){
        if(array[i]=='('){
            left++;
        }
        else if(array[i]==')'){
            right++;
        }
        else{
            continue;
        }
        if(right<left){
            array[i]='*';
            left--;
        }
    }
    for(int i=0;i<n;++i){
        if(array[i]!='*'){
            printf("%c",array[i]);
        }
    }
    return 0;
}
