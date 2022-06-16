#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int n,m,Max;

typedef struct Step{
    int x;
    int y;
}step;

step tmp[1000],ans[1000],Tmp[1000];
int find(int i,int j,int array[n][m],int count){
    if(i>0 && array[i-1][j]>array[i][j]){//up
        tmp[count].x=i-1;
        tmp[count].y=j;
        find(i-1,j,array,count+1);
    }
    if(j>0 && array[i][j-1]>array[i][j]){//left
        tmp[count].x=i;
        tmp[count].y=j-1;
        find(i,j-1,array,count+1);
    }
    if(i<n-1 && array[i+1][j]>array[i][j]){//down
        tmp[count].x=i+1;
        tmp[count].y=j;
        find(i+1,j,array,count+1);
    }
    if(j<m-1 && array[i][j+1]>array[i][j]){//right
        tmp[count].x=i;
        tmp[count].y=j+1;
        find(i,j+1,array,count+1);
    }
    if(count>Max){
        Max=count;
        for(int k=0;k<Max;++k){
            Tmp[k].x=tmp[k].x;
            Tmp[k].y=tmp[k].y;
        }
    }
    //printf("%d\n",count);
    return Max;

}

int main(void){
    int count,max=0;
    scanf("%d %d\n",&n,&m);
    int array[n][m];
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%d ",&array[i][j]);
        }
        scanf("\n");
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            count=1;
            Max=0;
            tmp[0].x=i,tmp[0].y=j;
            count=find(i,j,array,count);
            //printf("a%d\n",count);
            if(count>max){
                max=count;
                for(int i=0;i<max;++i){
                    ans[i].x=Tmp[i].x;
                    ans[i].y=Tmp[i].y;
                }
            }
        }
    }
    printf("%d\n",max);
    for(int i=0;i<max;++i){
        printf("%d %d\n",ans[i].x,ans[i].y);
    }

    return 0;
}
