#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int main(void){
    char store[9]={'1','2','3','4','5','6','7','8','9'};
    int n,k,find=1,point;
    scanf("%d %d\n",&n,&k);
    int array[n];
    char ans[n];
    for(int i=0;i<n;++i){
        array[i] = store[i];
    }
    for(int i=2;i<=n-1;++i){
        find = find*i;
    }
    
    //printf("%d\n",find);
    int a,b=0,c=n-1;
    for(int i=0;i<n;++i){
        a=0;
        point = ((k-1)/find)+1;
        //printf("%d %d %d\n",find,k,point);
        while(point!=0){
            if(array[a]!=' '){
                ans[b] = array[a];
                --point;
            }
            ++a;
        }
        array[a-1]=' ';
        ++b;
        if(k%find==0){
            k = find;
        }
        else{
            k = k%find;
        }
        //printf("%d\n",c);
        if(c<1){
            c=1;
        }
        find = find/c;
        if(c>1){
            --c;
        }
    }
    for(int i=0;i<n;++i){
        printf("%c",ans[i]);
    }
    printf("\n");
    return 0;
}
