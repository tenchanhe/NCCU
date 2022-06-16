#include<stdio.h>
int main(){
    int n,flag,a,b;
    scanf("%d\n",&n);
    int array[n][3],distance[n],queue[n];
    for(int i=0;i<n;++i){
        distance[i] = 0;
        array[i][2] = 0;
        queue[i] = 0;
    }
    scanf("%d %d\n",&array[0][0],&array[0][1]);
    scanf("%d %d\n",&array[1][0],&array[1][1]);
    for(int i=2;i<n;++i){
        scanf("%d %d\n",&a,&b);
        array[i][0] = a;
        array[i][1] = b;
        flag = i;
        if(a < array[flag-1][0]){
            while(a < array[flag-1][0] && flag >= 1){
                array[flag][0] = array[flag-1][0];
                array[flag][1] = array[flag-1][1];
                --flag;
            }
            array[flag][0] = a;
            array[flag][1] = b;
        }
    }
    /*for(int i=0;i<n;++i){
        printf("%d %d\n",array[i][0],array[i][1]);
    }
    printf("flag = %d\n",flag);*/

    for(int i=0;i<flag+1;++i){
        a = i+1;
        while(array[a][2] == 1 && a < n){
            ++a;
        }
        while(array[a][0] < array[i][1] && a < n){
            array[a][2] = 1;
            distance[a] = distance[i]+1;
            ++a;
        }
        /*for(int j=0;j<n;++j){
            printf("%d ",distance[j]);
        }
        printf("\n");*/
    }
    printf("%d\n",distance[flag]);

    return 0;
}
