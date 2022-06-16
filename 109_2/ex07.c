#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int Min(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}
int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}
int main(void){
    int n,min=2147483647;
    scanf("%d\n",&n);
    int array[n][5000],point[n],num[n];
    char string[5000],delim[]=" ",*token;

    for(int i=0;i<n;++i){
        gets(string);

        int j=0;
        token=strtok(string,delim);
        while(token!=NULL){
            array[i][j]=atoi(token);
            token = strtok(NULL,delim);
            ++j;
        }
        min = Min(min,array[i][0]);
        num[i]=j;
        qsort(array[i],j,sizeof(array[0][0]),cmp);
    }

    int count,stop=0,tmp=2147483647;
    while(1){
        count=0;
        for(int i=0;i<n;++i){
            if(array[i][point[i]]==min){
                ++count;
                ++point[i];
                if(point[i]==num[i]){
                    stop=1;
                }
            }
        }
        if(count==n){
            if(tmp!=min){
                printf("%d ",min);
                tmp=min;
            }
            else if(tmp==min){
                continue;
            }
        }
        if(stop==1){
            printf("\n");
            break;
        }
        min=2147483647;
        for(int i=0;i<n;++i){
            min = Min(min,array[i][point[i]]);
        }

    }

    return 0;
}
