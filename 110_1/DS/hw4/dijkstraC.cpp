#include<iostream>
#include<fstream>
#include<cmath>
#include<time.h>
using namespace std;

int V = 200;

double distance(double x1,double y1,double x2,double y2){

    double d = ((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2));
    return sqrt(d);
}

void dijkstra(int graph[V][V],int src){
    int table[V][]
}

int main(){

    int x, y, dis;
    int nodes[V][3];
    int n =0;
    char z[20];
    int graph[V][V];

    ifstream infile;
    infile.open("node200.txt");
    while(infile >> x >> y >> z){
        //cout << x << ' ' << y << endl;
        nodes[n][0] = n;
        nodes[n][1] = x;
        nodes[n][2] = y;
        ++n;
    }
    infile.close();
    
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            graph[i][j] = distance(nodes[i][1],nodes[i][2],nodes[j][1],nodes[j][2]); 
            //cout << graph[i][j] << ' ' ;
        }
        //cout << endl;
    }

    /*double time;
    clock_t start,end;

    start = clock();
    for(int i=0;i<n;i++){
        dijkstra(graph, i);
    }
    end = clock();
    time = double(end-start)/double(CLOCKS_PER_SEC);

    cout << time << endl;*/
    return 0;
}
