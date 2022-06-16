#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int main(void){
    int n;
    scanf("%d\n",&n);
    int array[n][5];
    for(int i=0;i<n;++i){
        for(int j=0;j<4;++j){
            scanf("%d ",&array[i][j]);
        }
        scanf("\n");
    }
    for(int i=0;i<n;++i){
        if(array[i][1]-array[i][0] == array[i][2]-array[i][1]){
            array[i][4]=array[i][3]+array[i][1]-array[i][0];
        }
        else{
            array[i][4]=array[i][3]*(array[i][3]/array[i][2]);
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<5;++j){
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
    return 0;
}
