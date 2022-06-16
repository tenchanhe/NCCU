#include<stdio.h>
int row,clm;
int count = 0;

int recurse(int array[row][clm],int r,int c,int target){
    array[r][c] = 2;
    ++count;
    //printf("%d %d %d\n",r,c,count);
    if(r > 0 && array[r-1][c] == target){ //up
        recurse(array,r-1,c,target);
    }

    if(c > 0 && array[r][c-1] == target){ //left
        recurse(array,r,c-1,target);
    }

    if(r < row-1 && array[r+1][c] == target){ //down
        recurse(array,r+1,c,target);
    }

    if(c < clm-1 && array[r][c+1] == target){ //right
        recurse(array,r,c+1,target);
    }
    //printf("count=%d\n",count);
    //return count;
}

int main(){
    scanf("%d %d\n",&row,&clm);
    int array[row][clm];
    int max=0;

    for(int i=0;i<row;++i){
        for(int j=0;j<clm;++j){
            scanf("%d ",&array[i][j]);
        }
        scanf("\n");
    }
    /*for(int i=0;i<row;++i){
        for(int j=0;j<clm;++j){
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }*/

    for(int i=0;i<row;++i){
        for(int j=0;j<clm;++j){
            if(array[i][j] == 0){
                count = 0;
                recurse(array,i,j,0);
                //printf("main_count=%d i=%d j=%d\n",count,i,j);
                if(count > max){
                    max = count;
                }
            }
            else if(array[i][j] == 1){
                count = 0;
                recurse(array,i,j,1);
                //printf("main_count=%d i=%d j=%d\n",count,i,j);
                if(count > max){
                    max = count;
                }
            }
        }
    }
    /*printf("\n");
    for(int i=0;i<row;++i){
        for(int j=0;j<clm;++j){
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }*/
    printf("%d\n",max);

    return 0;
}
