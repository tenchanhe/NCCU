#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int Max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int main(void){
    int n;
    scanf("%d\n",&n);
    int num[n],book[n][n];
    
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            book[i][j]=0;
        }
    }
    
    for(int i=0;i<n;++i){
        scanf("%d ",&num[i]);
        book[i][i]=num[i];
    }
    
    for(int i=n-2;i>=0;--i){
        for(int j=i+1;j<n;++j){
            printf("%d %d\n",i,j);
            book[i][j]=Max(num[i]-book[i+1][j],num[j]-book[i][j-1]);
        }
    }
    
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            printf("%d ",book[i][j]);
        }
        printf("\n");
    }

    if(book[0][n-1]>=0){
        printf("True\n");
    }
    else{
        printf("False\n");
    }
    return 0;
}

