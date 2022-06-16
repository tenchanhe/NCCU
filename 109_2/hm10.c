#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int main(void){
    int a,b,c,l1,l2,r1,r2,mid,total,p1,p2,ans;
    scanf("%d\n",&a);
    int A[a];
    for(int i=0;i<a;++i){
        scanf("%d ",&A[i]);
    }
    scanf("\n%d\n",&b);
    int B[b];
    for(int i=0;i<b;++i){
        scanf("%d ",&B[i]);
    }
    scanf("\n%d\n",&c);
    for(int i=0;i<c;++i){
        scanf("%d %d %d %d\n",&l1,&r1,&l2,&r2);
        total = r1-l1+r2-l2;
        mid = (total+1)/2;
        p1=l1,p2=l2;

        for(int j=0;j<mid;++j){
            if(p1==r1){
                ans = B[p2];
                ++p2;
            }
            else if(p2==r2){
                ans = A[p1];
                ++p1;
            }
            else if(A[p1]<=B[p2] && p1<r1){
                ans = A[p1];
                ++p1;
            }
            else if(B[p2]<A[p1] && p2<r2){
                ans = B[p2];
                ++p2;
            }
        }
        if(total%2 == 0){
            printf("%d ",ans);
            if(p1==r1){
                printf("%d\n",B[p2]);
            }
            else if(p2==r2){
                printf("%d\n",A[p1]);
            }
            else if(A[p1]<B[p2]){
                printf("%d\n",A[p1]);
            }
            else{
                printf("%d\n",B[p2]);
            }
        }
        else if(total%2 == 1){
            printf("%d\n",ans);
        }
    }

    return 0;
}
