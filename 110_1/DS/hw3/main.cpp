#include<iostream>
#include<time.h>
//#include"skiplist.h"
//#include"sortedarray.h"
//#include"treap.h"
#include"hashtable.h"

using namespace std;

int main(void){
    //int size = 1024,pow = 10;//,n,loc=0,key;
    int size = 67108864 ,pow = 26;
    clock_t start,end;
    srand(time(NULL));
    double time;

    for(int i=0;i<20;++i){ 
        for(int j=0;j<10;++j){
            
            //int *array = new int[size];
            
            //struct TreapNode *root = NULL;
            //n = 0;
            //SkipList lst(100000,0.5);
            //SkipList lst(100000,0.1);
            //SkipList lst(100000,0.9);
            HashTable table(size);
            
            start = clock();
            for(int k=0;k<size;++k){
                //root = insert(root,rand() % (1073741824) + 1);
                /*key = rand() % (1073741824) + 1;
                n = insertSorted(array,n,key,size);*/
                //lst.insertElement(rand() % (1073741824) + 1);
                //cout << "in" << endl;
                table.insert(rand() % (1073741824) + 1);
                //cout << "out" << endl;
            }
            end = clock();
            
            time = double(end-start)/double(CLOCKS_PER_SEC);
            //cout << size << " skiplist0.5_insert" << "," << "total_lvl=," << lst.total_lvl << ",max_lvl=<< ," << lst.max_lvl << "," << pow << "," << time << endl;
            //cout << size << " skiplist0.1_insert" << "," << "total_lvl=," << lst.total_lvl << ",max_lvl=<< ," << lst.max_lvl << "," << pow << "," << time << endl;
            //cout << size << " skiplist0.9_insert" << "," << "total_lvl=," << lst.total_lvl << ",max_lvl=<< ," << lst.max_lvl << "," << pow << "," << time << endl;
            //cout << size << " treap_insert" << "," << pow << "," << time << endl;
            //cout << size << " sortedarray_insert" << "," << pow << "," << time << endl;
            cout << size << "hashtable_search," << pow << ',' << time << endl;
            
            start = clock();
            for(int k=0;k<100000;++k){
                //root = search(root,rand() % (1073741824) + 1);
                /*key = rand() % (1073741824) + 1;
                loc = binarySearch(array,0,n-1,key);*/
                //lst.searchElement(rand() % (1073741824) + 1);
                table.search(rand() % (1073741824) + 1);
            }
            end = clock();
            
            time = double(end-start)/double(CLOCKS_PER_SEC);
            //cout << size << " skiplist0.5_find" << "," << pow << "," << time << endl;
            //cout << size << " skiplist0.1_find" << "," << pow << "," << time << endl;
            //cout << size << " skiplist0.9_find" << "," << pow << "," << time << endl;
            //cout << size << " treap_find" << "," << pow << "," << time << endl;
            //cout << size << " sortedarray_find" << "," << pow << "," << time << endl;
            cout << size << "hashtable_find," << pow << ',' << time << endl;
            
            //delete []array;
        }
        size *= 2;
        ++pow;
    }
    return 0;
}
