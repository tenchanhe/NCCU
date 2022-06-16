#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int Min(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}
int main(void){
    int n,target;
    scanf("%d\n",&n);
    int array[n];
    for(int i=0;i<n;++i){
        scanf("%d ",&array[i]);
    }
    scanf("%d\n",&target);
    
    int l=0,r=0,sum=0,ans=1000000;
    while(r!=n){
        if(sum<target){
            sum += array[r];
            ++r;
        }
        if(sum>=target){
            ans = Min(ans,r-l);
            while(sum>=target){
                sum -= array[l];
                ++l;
                if(sum>=target){
                    ans = Min(ans,r-l);
                }
            }
        }
    }
    if(ans!=1000000){
        printf("%d\n",ans);
    }
    else{
        printf("0\n");
    }
    return 0;
}
