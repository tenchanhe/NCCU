#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int cmp(const void *a,const void *b){
    return (*(int*)a-*(int*)b);
}
int main(void){
    int source,target,busnum,n=0;
    scanf("%d %d\n%d\n",&source,&target,&busnum);
    int busline[busnum][100000],allstop[100000],stopnum[busnum],already[busnum];
    for(int i=0;i<busnum;++i){
        scanf("%d\n",&stopnum[i]);
        for(int j=0;j<stopnum[i];++j){
            scanf("%d ",&busline[i][j]);
            allstop[n]=busline[i][j];
            ++n;
        }
        scanf("\n");
    }
    qsort(allstop,n,sizeof(allstop[0]),cmp);
    int graph[n][100000],a=1,clm[600];
    graph[0][0]=allstop[0];
    for(int i=0;i<busnum;++i){
        for(int j=0;j<stopnum[i];++j){
            if(busline[i][j]==allstop[0]){
                for(int k=0;k<stopnum[i];++k){
                    if(busline[i][k]!=allstop[0]){
                        graph[0][a]=busline[i][k];
                        ++a;
                    }
                }
                break;
            }
        }
    }
    clm[0]=a;
    int b=1,r=1;;
    while(b!=n){
        if(allstop[b]!=allstop[b-1]){
            graph[r][0]=allstop[b];
            a=1;
            for(int i=0;i<busnum;++i){
                for(int j=0;j<stopnum[i];++j){
                    if(busline[i][j]==allstop[b]){
                        for(int k=0;k<stopnum[i];++k){
                            if(busline[i][k]!=allstop[b]){
                                graph[r][a]=busline[i][k];
                                ++a;
                            }
                        }
                        break;
                    }
                }
            }
            clm[r]=a;
            ++r;
        }
        ++b;
    }
    int queue[100000],step=1,flag[100000]={0},add=0;
    for(int i=0;i<r;++i){
        if(graph[i][0]==source){
            for(int j=0;j<clm[i];++j){
                if(graph[i][j]!=target){
                    queue[add]=graph[i][j];
                    flag[queue[add]]=1;
                    ++add;
                }
                else{
                    printf("1\n");
                    return 0;
                }
            }
            queue[add]=-1;
            ++add;
            break;
        }
    }
    /*for(int i=0;i<r;++i){
        for(int j=0;j<clm[i];++j){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<10;++i){
        printf("%d ",queue[i]);
    }printf("\n");*/
    int point=1,fail=1,stop=0;
    while(1){
        ++step;
        while(queue[point]!=-1){
            //printf("%d %d\n",queue[point],fail);
            ++fail;
            for(int i=0;i<r;++i){
                if(graph[i][0]==queue[point]){
                    for(int j=1;j<clm[i];++j){
                        if(graph[i][j]!=target){
                            if(flag[graph[i][j]]!=1){
                                queue[add]=graph[i][j];
                                flag[queue[add]]=1;
                                ++add;
                            }
                        }
                        else{
                            printf("%d\n",step);
                            return 0;
                        }
                    }
                    ++point;
                    break;
                }
            }
            /*for(int i=0;i<10;++i){
                printf("%d ",queue[i]);
            }printf("\n");*/
        }
        //printf("%d %d\n",point,queue[point]);
        if(queue[point]==-1){
            ++stop;
        }
        ++point;
        queue[add]=-1;
        ++add;
        if(fail==r || stop==2){
            printf("-1\n");
            return 0;
        }
    }
    /*for(int i=0;i<10;++i){
      printf("%d ",queue[i]);
      }*/
    printf("-1\n");
    return 0;
}
