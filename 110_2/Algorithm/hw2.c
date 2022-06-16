#include<stdio.h>
int main(){
    int n,a,b,flag,tmp_a,tmp_b;
    scanf("%d\n",&n);
    int array[n][2];

    scanf("%d %d\n",&array[0][0],&array[0][1]);
    for(int i=1;i<n;++i){
        scanf("%d %d\n",&a,&b);
        array[i][0] = a;
        array[i][1] = b;
        flag = i;
        if(b < array[flag-1][1]){
            while(b < array[flag-1][1] && flag >= 1){
                array[flag][0] = array[flag-1][0];
                array[flag][1] = array[flag-1][1];
                --flag;
            }
            array[flag][0] = a;
            array[flag][1] = b;
        }
    }

    int work, rest;
    int max = 0, flag_j = 0 , earn;
    scanf("%d %d",&work,&rest);
    int cal[rest+1];
    while(array[flag_j][1] < work){
        ++flag_j;
    }
    
    for(int i=0;i<rest+1;++i){
        cal[i] = 0;
    }

    for(int i=0;i<n;++i){
        if(array[i][0]>=work && array [i][1]<=rest){
            earn = array[i][1] - array[i][0] + cal[array[i][0]];
            if(earn > max){
                max = earn;
            }
            cal[array[i][1]] = max;
        }
        if(i<n-1){
            for(int j=array[i][1];j<array[i+1][1];++j){
                cal[j] = max;
            }
        }
    }

    printf("%d\n",max);
    return 0;
}
