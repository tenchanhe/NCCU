#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int main(void){
    int a,b,c;
    scanf("%d\n",&a);
    int A[a+1];
    for(int i=1;i<=a;++i){
        scanf("%d ",&A[i]);
        //printf("%d ",A[i]);
    }
    scanf("\n%d\n",&b);
    //printf("%d %d\n",a,b);
    int B[b+1];
    for(int i=1;i<=b;++i){
        scanf("%d ",&B[i]);
        //printf("%d ",B[i]);
    }
    scanf("\n%d\n",&c);
    //printf("%d\n",c);

    int lA,lB,rA,rB,mid,midA,midB,total,n1,n2,ans,sindou;
    for(int i=0;i<c;++i){
        scanf("%d %d %d %d\n",&lA,&rA,&lB,&rB);
        //printf("%d %d %d %d\n",lA,rA,lB,rB);
        n1 = rA-lA, n2 = rB-lB;
        total = n1+n2;
        midA = (n1+1)/2, midB = (n2+1)/2, mid = (total+1)/2;
        //printf("%d %d\n",midA+lA,midB+lB);
        sindou = total%2;

        while(1){
            //printf("midA+midB=%d mid=%d\n",midA+midB,mid);
            if(total<=4 || midA==1 || midB==1){
                //printf("%d\n",total);
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

            if(midA+midB >= mid){
                //printf("%d %d %d %d\n",midA,midB,rA,rB);
                if(A[midA+lA] > B[midB+lB]){
                    total = total-(rA-lA-midA);
                    rA = rA-midA;
                    midA = (rA-lA+1)/2;
                }
                else if(B[midB+lB] > A[midA+lA]){
                    total = total-(rB-lB-midB);
                    //printf("%d\n",(rB-lB-midB));
                    rB = rB-midB;
                    midB = (rB-lB+1)/2;
                }
                else{
                    total = total-(rA-lA-midA)-(rB-lB-midB);
                    rA = rA-midA;
                    midA = (rA-lA+1)/2;
                    rB = rB-midB;
                    midB = (rB-lB+1)/2;
                }
                //printf("aa%d \n",total);
            }
            else if(midA+midB < mid){
                if(A[midA+lA] < B[midB+lB]){
                    total = total - midA + 1;
                    mid = mid - midA + 1;
                    lA = lA+midA-1;
                    midA = (rA-lA+1)/2;
                }
                else if(B[midB+lB] < A[midA+lA]){
                    total = total - midB + 1;
                    mid = mid - midB + 1;
                    lB = lB+midB-1;
                    midB = (rB-lB+1)/2;
                }
                else{
                    total = total - midA+1 - midB+1;
                    mid = mid - midA+1 - midB+1;
                    lA = lA+midA-1;
                    midA = (rA-lA+1)/2;
                    lB = lB+midB-1;
                    midB = (rB-lB+1)/2;
                }
                //printf("bb%d \n",total);
                /*if(midA == 1 && total>4){
                    if(n1>2){
                        --mid;
                    }
                    if(A[rA]<=B[lB+mid] && A[rA]>=B[lB+mid-1]){
                        ans = A[rA];
                    }
                    else if(A[rA]<B[lB+mid-1]){
                        ans = B[lB+mid-1];
                    }
                    else{
                        ans = B[lB+mid];
                    }

                    if(sindou == 0){
                        printf("%d ",ans);
                        if(A[rA]<=B[lB+mid-1]){
                            printf("%d\n",B[lB+mid]);
                        }
                        else{
                            printf("%d\n",A[rA]);
                        }
                    }
                    else{
                        printf("%d\n",ans);
                    }
                    break;
                }
                if(midB == 1 && total>4){
                    //printf("CC\n");
                    if(n2>2){
                        --mid;
                    }
                    if(B[rB]<=A[lA+mid] && B[rB]>=A[lA+mid-1]){
                        ans = B[rB];
                    }
                    else if(B[rB]<A[lA+mid-1]){
                        ans = A[lA+mid-1];
                    }
                    else{
                        ans = A[lA+mid];
                    }

                    if(sindou == 0){
                        printf("%d ",ans);
                        if(B[rB]<=A[lA+mid-1]){
                            printf("%d\n",A[lA+mid]);
                        }
                        else{
                            printf("%d\n",B[rB]);
                        }
                    }
                    else{
                        printf("%d\n",ans);
                    }
                    break;
                }*/
            }
        }
    }
    return 0;
}
