#include<iostream>
#include<time.h>
//#include"mergesort.h"
//#include"lomutoqsort.h"
//#include"dutchflagqsort.h"
//#include"hoareqsort.h"
#include"heapsort.h"

using namespace std;

int main(void){
    clock_t start,end;
    srand(time(NULL));
    int size = 1073741824,pow = 30;
    double time;

    //for(int i=0;i<2;++i){ 
        for(int j=0;j<10;++j){
            
            int *array = new int[size];
            for(int k=0;k<size;++k){
                array[k] = rand() % (1000) + 1;
            }
            
            start = clock();
            heapSort(array,size);
            end = clock();
            time = double(end-start)/double(CLOCKS_PER_SEC);
            cout << size << " heapsort" << "," << pow << "," << time << endl;
            
            delete []array;
        }
       // size *= 2;
        //++pow;
    //}
    return 0;
}
