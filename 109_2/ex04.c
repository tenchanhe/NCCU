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
    int ans=0,n=0,i=0,j=1,array[100000];
    while(scanf("%d ",&array[n])!=EOF){
        n++;
    }
    while(j<n){
        if(array[j]<array[i]){
            printf("  %d %d\n",i,j);
            i=j;
            ++j;
        }
        else{
            printf("%d %d\n",ans,array[j]-array[i]);    
            printf(" %d %d\n",i,j);
            ++j;
        }
        ans = Max(ans,array[j]-array[i]);
    }

    printf("%d\n",ans);


    return 0;
}

