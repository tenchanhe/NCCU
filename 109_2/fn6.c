#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
}
}
int main(void){
    int n=0;
    scanf("%d\n",&n);
    int array[n],ans[n];
    for(int i=0;i<n;++i){
        scanf("%d ",&array[i]);
    }
    ans[0]=1;
    for(int i=0;i<n-1;++i){
        ans[i+1]=1;
        if(array[i]<array[i+1]){
            ans[i+1]=ans[i]+1;
        }
    }
    for(int i=n-1;i>0;--i){
        if(array[i]<array[i-1]){
            ans[i-1]=max(ans[i-1],ans[i]+1);
        }
    }
    int count=0;
    for(int i=0;i<n;++i){
        count = count+ans[i];
    }
    printf("%d\n",count);

    return 0;
}
