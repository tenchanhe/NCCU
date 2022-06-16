#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int main(void){
    int array[40],z=1,a,b,a1,b1;
    scanf("%d %d\n",&a,&b);
    for(int i=0;i<=30;++i){
        array[i]=z;
        if(a>=array[i]){
            a1=i;
        }
        if(b>=array[i]){
            b1=i;
        }
        z = z*2;
    }
    if(a1==b1){
        if(a%2 == 0){
            printf("%d\n",a);
        }
        else{
            printf("%d\n",a-1);
        }
    }
    else{
        printf("0\n");
    }
    return 0;
}
