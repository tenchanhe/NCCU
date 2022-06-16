#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int abc(int a,int b){
    if(b==0){
        return 1;
    }
    else if(b==1){
        return a;
    }
    int left = abc(a,b/2);
    if(b%2){
        return left * left *a;
    }
    else{
        return left *left;
    }
}
int main(void){
    int n;
    scanf("%d\n",&n);
    int a,b,ans;
    for(int i=0;i<n;++i){
        scanf("%d %d\n",&a,&b);
        ans = abc(a,b);
        printf("%d\n",ans%1007);
    }
    return 0;
}
