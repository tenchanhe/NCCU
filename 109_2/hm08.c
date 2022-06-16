#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int main(void){
    char input[200],stack[200],array[2000][20],in;
    for(int i=0;i<2000;++i){
        array[1][i]=' ';
    }
    int a=1,b=1,c,n=0;
    array[0][0]='0';
    stack[0]=' ';
    while(scanf("%c",&input[n])!=EOF){
        ++n;
    }
    /*for(int i=0;i<n;++i){
        printf("%c",input[i]);
    }*/
    for(int k=0;k<n;++k){ 
        if(input[k]=='-' && input[k-1]=='('){
            //printf("grg");
            array[a][0]=input[k];
            c=1;
            while(input[k+1]>=48 && input[k+1]<=57){
                array[a][c]=input[k+1];
                ++c;
                ++k;
            }
            ++a;
        }
        else if(input[k]>=48 && input[k]<=57){
            c=0;
            while(input[k]>=48 && input[k]<=57){
                array[a][c]=input[k];
                ++c;
                ++k;
            }
            --k;
            ++a;
        }
        else if(input[k]=='+' || input[k]=='-'){
            while(stack[b-1]!=' ' && stack[b-1]!='('){
                array[a][0]=stack[b-1];
                --b;
                ++a;
            }
            stack[b]=input[k];
            ++b;
        }
        else if(input[k]=='*' || input[k]=='/'){
            //while(stack[b-1]!=' ' && stack[b-1]!='(' && stack[b-1]!='+' && stack[b-1]!='-'){
            while(stack[b-1]=='*' || stack[b-1]=='/'){  
              array[a][0]=stack[b-1];
                --b;
                ++a;
            }
            stack[b]=input[k];
            ++b;
        }
        else if(input[k]=='('){
            stack[b]=input[k];
            ++b;
        }
        else if(input[k]==')'){
            while(stack[b-1]!='('){
                array[a][0]=stack[b-1];
                --b;
                ++a;
            }
            --b;
        }
    }
    for(int i=b-1;i>=0;--i){
        if(stack[i]!='('){
            array[a][0]=stack[i];
            ++a;
        }
    }

    for(int i=0;i<n+1;++i){
      for(int j=0;j<20;++j){
      printf("%c",array[i][j]);
      }
      printf("\n");
      }
    int num[200],ans,s=0,x,y;
    char oper[200];
    for(int i=0;i<n+1;++i){
        oper[i]=' ';
    }
    for(int i=0;i<n+1;++i){
        if(array[i][0]=='-' && array[i][1]!=' '){
            num[i]=atoi(array[i]);
            //printf("%d %d\n",i,num[i]);
        }
        else if(array[i][0]!='+' && array[i][0]!='-' && array[i][0]!='*' && array[i][0]!='/'){
            num[i]=atoi(array[i]);
        }
        else{
            oper[i]=array[i][0];
        }
    }
    for(int i=0;i<n+1;++i){
        if(oper[i]=='+'){
            x=i-1;
            /*while(oper[x]!=' '){
              --x;
              }*/
            y=x-1;
            while(oper[y]!=' '){
                --y;
            }
            //printf("%d %d\n",num[x],num[y]);
            oper[x]='+';
            oper[y]='+';
            num[i]=num[x]+num[y];
            oper[i]=' ';
            ans=i;
        }
        else if(oper[i]=='-'){
            x=i-1;
            /*while(oper[x]!=' '){
              --x;
              }*/
            y=x-1;
            while(oper[y]!=' '){
                --y;
            }
            //printf("%d %d\n",num[x],num[x-1]);
            oper[x]='+';
            oper[y]='+';
            num[i]=num[y]-num[x];
            oper[i]=' ';
            ans=i;
        }
        else if(oper[i]=='*'){
            x=i-1;
            /*while(oper[x]!=' '){
              --x;
              }*/
            y=x-1;
            while(oper[y]!=' '){
                --y;
            }
            //printf("%d %d\n",num[x],num[x-1]);
            oper[x]='+';
            oper[y]='+';
            num[i]=num[y]*num[x];;
            oper[i]=' ';
            ans=i;
        }
        else if(oper[i]=='/'){
            x=i-1;
            /*while(oper[x]!=' '){
              --x;
              }*/
            y=x-1;
            while(oper[y]!=' '){
                --y;
            }
            //printf("%d %d\n",num[x],num[x-1]);
            oper[x]='+';
            oper[y]='+';
            num[i]=num[y]/num[x];
            oper[i]=' ';
            ans=i;
        }
        //printf("i=%d\n",i);
        /*for(int j=0;j<n+1;++j){
          printf("%d %c\n",num[j],oper[j]);
          }
          printf("\n");*/
    }
    printf("%d\n",num[ans]);
    return 0;
}
