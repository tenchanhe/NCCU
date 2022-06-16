#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int count=0;
int Bsearch(int list[],int left,int right,int target){
    ++count;
    if(left >= right){
        return -1;
    }
    int mid = left + (right - left) / 2;
    if(list[mid]==target){
        return mid;
    }
    if(target < list[mid]){
        return Bsearch(list,left,mid,target);
    }
    return Bsearch(list,mid+1,right,target);
}
int main(void){
    int target,n=0;
    int *array=malloc(sizeof(int)*100000000);
    scanf("%d\n",&target);
    while(scanf("%d ",&array[n])!=EOF){
        ++n;
    }
    int key=Bsearch(array,0,n,target);
    if(key==-1){
        printf("-1\n");
    }
    else{
        printf("%d\n",key);
        printf("%d\n",count);
    }

    free(array);
    return 0;
}
