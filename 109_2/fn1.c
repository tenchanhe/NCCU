#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int main(void){
    int n;
    long long int ans=1;
    scanf("%d\n",&n);
    for(int i=1;i<=n;++i){
        ans=ans*i;
    }
    printf("%lld\n",ans);
    return 0;
}
