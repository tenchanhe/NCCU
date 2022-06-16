#include<stdlib.h>
#include<string.h>
#include<stdio.h>
typedef struct XY{
    int x;
    int y;
}xy;
int Max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int waiji(xy a,xy b){
    return (a.x*b.y-b.x*a.y);
}
int cmp(const void *a,const void *b){
    return waiji(*(xy*)a,*(xy*)b);
}
double xielv(double x1,double y1,double x2,double y2){
    //printf("%lf\n",((y1-y2)/(x1-x2)));
    return ((y1-y2)/(x1-x2));
}
int main(void){
    int n;
    scanf("%d\n",&n);
    double array[n][2];
    for(int i=0;i<n;++i){
        scanf("%lf %lf\n",&array[i][0],&array[i][1]);
    }
    /*for(int i=0;i<n-2;++i){
        for(int j=i+1;j<n-1;;++j){
            for(int k=j+1;k<n;++k){
                waiji(array[i][0],array[i][1],array[j][0],array[j][1],array[k][0],array[k][1]);
            }
        }
    }*/
    int max=0,a;
    for(int i=0;i<n;++i){
        xy book[n];
        a=0;
        for(int j=0;j<n;++j){
            if(i!=j){
            book[a].x = array[i][0]-array[j][0];
            book[a].y = array[i][1]-array[j][1];
            a++;
            }
        }
        
        qsort(book,a,sizeof(book[0]),cmp);
        int count=0;
        for(int j=1;j<a;++j){
            if(waiji(book[j],book[j-1])==0){
                count++;
            }
            else{
                count++;
                max=Max(max,count);
                count=0;
            }
        }
       // max = Max(max,max);
    }
    printf("%d\n",max+1);
    return 0;
}
