#include<iostream>
using namespace std;

int main(){
    char a[] = "abc";
    char b[] = "def";
    int l1 = sizeof(a);
    int l2 = sizeof(b);
    int n=0;
    for(int i=0,j=0;i<l1 || j<l2;++i,++j){
        int x = (long)a[i];
        x += (long)b[j];
        char sum = x;
        cout << sum;
        ++n;
    }
    return 0;
}
