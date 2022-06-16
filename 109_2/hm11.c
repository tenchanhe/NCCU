#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int main(void){
    int n1=0,n2=0,i=0,j=0;
    char array1[100],array2[100];
    gets(array1);
    gets(array2);
    n1=strlen(array1);
    n2=strlen(array2);

    //printf("n1=%d n2=%d\n",n1,n2);
    if(n1==0){
        for(int i=0;i<n2;++i){
            if(array2[i]!='*'){
                if(array2[i+1]=='*'){
                    ++i;
                }
                else{
                    printf("false\n");
                    return 0;
                }
            }
            else{
                printf("false\n");
                return 0;
            }
        }
        printf("true\n");
        return 0;
    }

    if(n2==0 && n1!=0){
        printf("false\n");
        return 0;
    }

    while(1){
        if(array2[j]=='.' && array2[j+1]=='*'){
            if(j+1==n2-1){
                printf("true\n");
                return 0;
            }
            else{
                j = j+2;
                ++i;
                while(array1[i]!=array2[j]){
                    ++i;
                }
            }
        }
        else if(i==n1 && j!=n2){
            while(1){
                if(array2[j]=='.' && array2[j+1]=='*'){
                    j = j+2;
                }
                else{
                    printf("false\n");
                    return 0;
                }
                if(j==n2){
                    printf("true\n");
                    return 0;
                }
            }
        }
        else if(array1[i]==array2[j]){
            ++i;
            ++j;
        }
        else if(array2[j]=='.'){
            array2[j] = array1[i];
            ++i;
            ++j;
        }
        else if(array2[j]=='*'){
            array2[j]=' ';
            char flag=array2[j-1];
            //printf("%c\n",flag);
            while(array1[i]==flag){
                ++i;
            }
            ++j;
            while(array2[j]==flag){
                ++j;
            }
            //printf("%c %c\n",array1[i],array2[j]);
        }
        else if(array2[j+1]=='*'){
            char flag;
            int a=j-1;
            while(array2[a]==' '){
                --a;
            }
            flag=array2[a];
            if(array1[i-1]==flag && array1[i]==array2[j+2]){
                array2[j]=' ';
                array2[j+1]=' ';
                ++i;
                j=j+3;
            }
            else{
                printf("false\n");
                break;
            }
        }
        else{
            //printf("%d %d %d %d\n",n1,n2,i,j);
            printf("false\n");
            break;
        }
        if(i==n1 && j==n2){
            printf("true\n");
            break;
        }
    }
    return 0;
}
