#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int main(void){
    int n;
    scanf("%d\n",&n);
    int array[n];
    for(int i=0;i<n;++i){
        scanf("%d ",&array[i]);
    }
    int step=array[0],step2=0;
    for(int i=0;i<step;++i){
        if(step>=n-1){
            printf("%d\n",i+1);
            return 0;
        }
        step2=step;
        for(int j=i+1;j<=step;++j){
            if(step2+array[j]>=n-1){
                printf("%d\n",i+2);
                return 0;
            }
        }
        step = step+array[i+1];
    }
    printf("-1\n");
    return 0;
}
