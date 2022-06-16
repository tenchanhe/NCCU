#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define Max(a,b) ((a)>(b)?(a):(b))
int n,count=0;
int test(int land[n][n],int i,int j,int flag){
    ++count;
    if(i>0){//up
        if(land[i-1][j]!=0 && land[i-1][j]!=flag){
            land[i-1][j]=flag;
            test(land,i-1,j,flag);
        }
    }
    if(j>0){//left
        if(land[i][j-1]!=0 && land[i][j-1]!=flag){
            land[i][j-1]=flag;
            test(land,i,j-1,flag);
        }
    }
    if(i<n-1){//down
        if(land[i+1][j]!=0 && land[i+1][j]!=flag){
            land[i+1][j]=flag;
            test(land,i+1,j,flag);
        }
    }
    if(j<n-1){//right
        if(land[i][j+1]!=0 && land[i][j+1]!=flag){
            land[i][j+1]=flag;
            test(land,i,j+1,flag);
        }
    }
    return count;
}
int main(void){
    int flag=2,ans=0;
    scanf("%d\n",&n);
    int land[n][n];
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            scanf("%d ",&land[i][j]);
        }
        scanf("\n");
    }
    
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(land[i][j] == 0){
                test(land,i,j,flag);
                ans=Max(ans,count);
                count=0;
                ++flag;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
