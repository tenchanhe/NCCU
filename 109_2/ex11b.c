#include<stdlib.h>
#include<string.h>
#include<stdio.h>
typedef struct{
    int value;
    int line[500];
}Line;

Line graph[500];

int issame(int busline1[],int n1,int busline2[],int n2){
    int i=0,j=0;
    while(i < n1 && j < n2){
        if(busline1[i] == busline2[j]){
            return 1;
        }
        else if(busline1[i] > busline2[j]){
            ++j;
        }
        else{
            ++i;
        }
    }
    return 0;
}

int isinside(int busline[],int n1,int source){
    int i=0,j=n1-1,mid;
    while(i<=j){
        mid = (i+j)/2;
        if(busline[mid] > source){
            return 1;
        }
        else if(busline[mid] > source){
            j = mid-1;
        }
        else{
            i = mid+1;
        }
    }
    return 0;
}

int main(void){
    int source,target,linenum,a=0,bottom=0,bus=1,queue[500],l,k;
    scanf("%d %d\n%d\n",&source,&target,&linenum);
    int busline[linenum][100000],stopnum[linenum],already[linenum];
    for(int i=0;i<linenum;++i){
        scanf("%d\n",&stopnum[i]);
        for(int j=0;j<stopnum[i];++j){
            scanf("%d ",&busline[i][j]);
        }
        scanf("\n");
    }
    for(int i=0;i<linenum;++i){
        for(int j=i+1;j<linenum;++j){
            if(issame(busline[i],stopnum[i],busline[j],stopnum[j])==1){
                graph[i].line[graph[i].value++] = j;
                graph[j].line[graph[j].value++] = i;
            }
        }
        //printf("\n");
    }
    for(int i=0;i<linenum;++i){
        if(isinside(busline[i],stopnum[i],source)==1){
            queue[a] = i;
            already[i] = 1;
            ++a;
        }
    }
    while(bottom != a){
        l=a-bottom; 
        for(int i=0;i<l;++i){
            k=queue[bottom];
            ++bottom;
            if(isinside(busline[k],stopnum[k],target) == 1){
                printf("%d\n",bus);
                return 0;
            }
            for(int j=0;j<graph[k].value;++j){
                if(already[graph[k].line[j]] == 0){
                    queue[a] = graph[k].line[j];
                    already[graph[k].line[j]] = 1;
                }
            }
        }
        ++bus;
    }
    printf("-1\n");
    return 0;
}

/*for(int i=0;i<linenum;++i){
  for(int j=0;j<stopnum[i];++j){
  printf("%d ",busline[i][j]);
  }
  printf("\n");
  }*/
