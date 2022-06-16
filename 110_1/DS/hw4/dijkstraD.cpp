#include <fstream>
#include <algorithm>
#include <climits>
#include <iostream>
#include <cmath>
using namespace std;

const int maxnodes = 200000;
const int maxedges = 1000000;

double distance(double x1,double y1,double x2,double y2){

    double d = ((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2));
    return sqrt(d);
}

// graph
int edges;
int last[maxnodes], head[maxedges], previous[maxedges], len[maxedges];
int prio[maxnodes], pred[maxnodes];

void graphClear() {
    fill(last, last + maxnodes, -1);
    edges = 0;
}

void addEdge(int u, int v, int length) {
    head[edges] = v;
    len[edges] = length;
    previous[edges] = last[u];
    last[u] = edges++;
}

// heap
int h[maxnodes];
int pos2Id[maxnodes];
int id2Pos[maxnodes];
int hsize;

void hswap(int i, int j) {
    swap(h[i], h[j]);
    swap(pos2Id[i], pos2Id[j]);
    swap(id2Pos[pos2Id[i]], id2Pos[pos2Id[j]]);
}

void moveUp(int pos) {
    while (pos > 0) {
        int parent = (pos - 1) >> 1;
        if (h[pos] >= h[parent]) {
            break;
        }
        hswap(pos, parent);
        pos = parent;
    }
}

void add(int id, int prio) {
    h[hsize] = prio;
    pos2Id[hsize] = id;
    id2Pos[id] = hsize;
    moveUp(hsize++);
}

void increasePriority(int id, int prio) {
    int pos = id2Pos[id];
    h[pos] = prio;
    moveUp(pos);
}

void moveDown(int pos) {
    while (pos < (hsize >> 1)) {
        int child = 2 * pos + 1;
        if (child + 1 < hsize && h[child + 1] < h[child]) {
            ++child;
        }
        if (h[pos] <= h[child]) {
            break;
        }
        hswap(pos, child);
        pos = child;
    }
}

int removeMin() {
    int res = pos2Id[0];
    int lastNode = h[--hsize];
    if (hsize > 0) {
        h[0] = lastNode;
        int id = pos2Id[hsize];
        id2Pos[id] = 0;
        pos2Id[0] = id;
        moveDown(0);
    }
    return res;
}

void dijkstra(int s) {
    fill(pred, pred + maxnodes, -1);
    fill(prio, prio + maxnodes, INT_MAX);
    prio[s] = 0;
    hsize = 0;
    add(s, 0);

    while (hsize) {
        int u = removeMin();
        for (int e = last[u]; e >= 0; e = previous[e]) {
            int v = head[e];
            int nprio = prio[u] + len[e];
            if (prio[v] > nprio) {
                if (prio[v] == INT_MAX)
                    add(v, nprio);
                else
                    increasePriority(v, nprio);
                prio[v] = nprio;
                pred[v] = u;
            }
        }
    }
}

int main() {
    graphClear();

    int V = 200;
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
        for(int j=i+1;j<n;++j){
            addEdge(i, j,distance(nodes[i][1],nodes[i][2],nodes[j][1],nodes[j][2]));
            //graph[i][j] = distance(nodes[i][1],nodes[i][2],nodes[j][1],nodes[j][2]); 
            //cout << graph[i][j] << ' ' ;
        }
        //cout << endl;
    }

    double time;
    clock_t start,end;

    start = clock();
    for(int i=0;i<n;i++){
        graphClear();
        dijkstra(i);
        cout << "i= " << i << endl;
        for (int j = 0; j < n; j++){
            cout << prio[j] << endl;
        }
    }
    end = clock();
    time = double(end-start)/double(CLOCKS_PER_SEC);

    cout << time << endl;
    return 0;
}
    /*addEdge(0, 1, 10);
    addEdge(1, 2, -5);
    addEdge(0, 2, 8);

    dijkstra(0);*/

