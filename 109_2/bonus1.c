#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int main(){
    //printf("abcdefg");
    int n;
    scanf("%d\n",&n);
    int array[n];
    for(int i=0;i<n;++i){
        scanf("%d ",&array[i]);
        //printf("%d ",array[i]);
    }
    int i=0,j=n-1;
    int sum1=array[i],sum2=array[j],ans=0;
    
    while(i<n-1 || j>0){
        if(sum1>sum2){
            j--;
            sum2 += array[j];
        }
        else if(sum1<sum2){
            i++;
            sum1 += array[i];
        }
        else{
            ans++;
            if(i!=n-2){
                i++;
                sum1+=array[i];
            }
            else{
                j--;
                sum2+=array[j];
            }
        }
    
    }
    printf("%d\n",ans);

    return 0;
}
