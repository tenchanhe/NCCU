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
    int a,b,A[2000],B[2000];
    scanf("%d\n",&a);
    for(int i=0;i<a;++i){
        scanf("%d ",&A[i]);
    }
    scanf("\n%d\n",&b);
    for(int i=0;i<b;++i){
        scanf("%d ",&B[i]);
    }
    int array[a+1][b+1],ans=0;
    for(int i=0;i<=a;++i){
        for(int j=0;j<=b;++j){
            array[i][j]=0;
        }
    }

    for(int i=0;i<=a;++i){
        for(int j=0;j<=b;++j){
            if(i==0 || j==0){
                array[i][j]=0;
            }
            else if(A[i-1]==B[j-1]){
                array[i][j] = array[i-1][j-1]+1;
                ans=Max(ans,array[i][j]);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
