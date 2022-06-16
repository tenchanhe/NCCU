#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int main(void){
    int n,j,k,l;

    while(scanf("%d\n",&n)!=EOF){
        int array[n],station[n];
        j=0,k=0,l=1;

        for(int i=0;i<n;++i){
            scanf("%d ",&array[i]);
        }
        scanf("\n");

        for(int i=0;i<n;++i){
            if(array[j]!=l){
                station[k]=l;
                l++;
                k++;
            }
            else if(array[j]==l){
                i--;
                j++;
                l++;
                while(array[j]==station[k-1]){
                    i--;
                    k--;
                    j++;
                    if(j==n){
                        break;
                    }
                }
            }
            if(j==n){
                break;
            }
        }

        if(j==n){
            printf("TAK\n");
        }
        else{
            printf("NIE\n");
        }
    }
    return 0;
}
