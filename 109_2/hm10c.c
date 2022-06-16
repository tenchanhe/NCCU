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
int main(void){
    int a,b,c;
    scanf("%d\n",&a);
    int A[a+1];
    for(int i=1;i<=a;++i){
        scanf("%d ",&A[i]);
    }
    scanf("\n%d\n",&b);
    int B[b+1];
    for(int i=1;i<=b;++i){
        scanf("%d ",&B[i]);
    }
    scanf("\n%d\n",&c);

    int lA,lB,rA,rB,mid,midA,midB,total,n1,n2,ans,sindou;
    for(int i=0;i<c;++i){
        scanf("%d %d %d %d\n",&lA,&rA,&lB,&rB);
        n1 = rA-lA, n2 = rB-lB;
        total = n1+n2;
        mid = (total+1)/2;
        sindou = total%2;

        while(1){
            if(n1<mid && n2<mid){
                int p1=lA+1,p2=lB+1;
                for(int j=0;j<mid;++j){
                    if(p1==rA+1){
                        ans = B[p2];
                        ++p2;
                    }
                    else if(p2==rB+1){
                        ans = A[p1];
                        ++p1;
                    }
                    else if(A[p1]<=B[p2] && p1<rA+1){
                        ans = A[p1];
                        ++p1;
                    }
                    else if(B[p2]<A[p1] && p2<rB+1){
                        ans = B[p2];
                        ++p2;
                    }
                }
                if(sindou == 0){
                    printf("%d ",ans);
                    if(p1==rA+1){
                        printf("%d\n",B[p2]);
                    }
                    else if(p2==rB+1){
                        printf("%d\n",A[p1]);
                    }
                    else if(A[p1]<B[p2]){
                        printf("%d\n",A[p1]);
                    }
                    else{
                        printf("%d\n",B[p2]);
                    }
                }
                else if(sindou == 1){
                    printf("%d\n",ans);
                }
                break;
            }

            else if(n1 < mid){
                mid -= n1;
                if(sindou == 1){
                    printf("%d\n",B[lB+mid]);
                }
                else{
                    printf("%d %d\n",B[lB+mid],B[lB+mid+1]);
                }
                break;
            }
            else if(n2 < mid){
                mid -= n2;
                if(sindou == 1){
                    printf("%d\n",A[lA+mid]);
                }
                else{
                    printf("%d %d\n",A[lA+mid],A[lA+mid+1]);
                }
                break;
            }
            else if(A[lA+mid] <= B[lB+mid]){
                lA += mid;
                n1 -= mid;
                if(mid==1){
                    if(A[lA+1] <= B[lB+1]){
                        printf("%d",A[lA+1]);
                        ++lA;
                    }
                    else{
                        printf("%d",B[lB+1]);
                        ++lB;
                    }
                    if(sindou == 0){
                        printf(" %d\n",Min(A[lA+1],B[lB+1]));
                    }
                    else{
                        printf("\n");
                    }
                }
            }
            else if(B[lA+mid] < A[lB+mid]){
                lB += mid;
                n2 -= mid;
                if(mid==1){
                    if(A[lA+1] <= B[lB+1]){
                        printf("%d",A[lA+1]);
                        ++lA;
                    }
                    else{
                        printf("%d",B[lB+1]);
                        ++lB;
                    }
                    if(sindou == 0){
                        printf(" %d\n",Min(A[lA+1],B[lB+1]));
                    }
                    else{
                        printf("\n");
                    }
                }
            }
            mid = mid/2;
        }
    }

    return 0;
}
