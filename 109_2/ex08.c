#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int cifang(int a,int b,int c){
    int t;
    if(b==0){
        return 1%c;
    }
    if(b==1){
        return a%c;
    }
    t=cifang(a,b/2,c);
    t=t*t%c;
    if((b&1)==1){
        t=t*a%c;
    }
    return t;
}
int main(void){
    int n,a,b,c;
    scanf("%d\n",&n);
    for(int i=0;i<n;++i){
        scanf("%d %d %d\n",&a,&b,&c);
        printf("%d\n",cifang(a,b,c));
    }

    return 0;
}
