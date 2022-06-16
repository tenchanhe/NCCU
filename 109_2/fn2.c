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
    int xa1,xa2,ya1,ya2,xb1,xb2,yb1,yb2,xc1,xc2,yc1,yc2,max=0;
    scanf("(%d, %d, %d, %d)\n",&xa1,&ya1,&xa2,&ya2);
    scanf("(%d, %d, %d, %d)\n",&xb1,&yb1,&xb2,&yb2);
    scanf("(%d, %d, %d, %d)\n",&xc1,&yc1,&xc2,&yc2);
    max=Max(max,xa1);max=Max(max,xa2);max=Max(max,ya1);max=Max(max,ya2);
    max=Max(max,xb1);max=Max(max,xb2);max=Max(max,yb1);max=Max(max,yb2);
    max=Max(max,xc1);max=Max(max,xb2);max=Max(max,yc1);max=Max(max,yc2);
    //printf("%d\n",max);
    long long int array[max+1][max+1];
    for(int i=0;i<max+1;++i){
        for(int j=0;j<max+1;++j){
            array[i][j]=0;
        }
    }
    for(int i=xa1;i<xa2;++i){
        for(int j=ya1;j<ya2;++j){
            array[i][j]=1;
        }
    }
    for(int i=xb1;i<xb2;++i){
        for(int j=yb1;j<yb2;++j){
            array[i][j]=1;
        }
    }
    for(int i=xc1;i<xc2;++i){
        for(int j=yc1;j<yc2;++j){
            array[i][j]=1;
        }
    }
    
    /*for(int i=0;i<max;++i){
        for(int j=0;j<max;++j){
            printf("%lld ",array[i][j]);
        }
        printf("\n");
    }*/
    long long int count=0;
    for(int i=0;i<max;++i){
        for(int j=0;j<max;++j){
            if(array[i][j]==1){
                ++count;
            }
        }
    }
    printf("%lld\n",count);

    return 0;
}
