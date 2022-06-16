#include<stdio.h>
int main(){
    int n = 0, all = 0;
    int array[200000];

    while(scanf("%d ",&array[n]) != EOF){
        all += array[n];
        ++n;
    }

    if(n == 1){
        if(array[0] < 0){
            printf("0\n");
            return 0;
        }
        
        printf("%d\n",array[0]);
        return 0;
    }
    
    int r = n;
    for(int i=0;i<n;++i){
        array[r] = array[i];
        ++r;
    }

    int a = 0, b = 0, c = 0, d = 0, max = 0, min = 0, sum_a = 0, sum_b = 0;
    while(array[a] < 0){
        ++a;
    }
    b = a;
    c = a;
    d = a;
    
    for(int i=0;i<r;++i){
        sum_a += array[b];
        sum_b += array[d];
        
        if(sum_a < 0){
            sum_a = 0;
            a = b+1;
        }
        else if(sum_a > max && b-n < a){
            max = sum_a;
        }
        
        if(sum_b > 0){
            sum_b = 0;
            c = d+1;
        }
        else if(sum_b < min && d-n < c){
            min = sum_b;
        }
        ++b;
        ++d;
    }

    if(max > all-min){
        printf("%d\n",max);
    }
    else{
        printf("%d\n",all-min);
    }

    return 0;
}
