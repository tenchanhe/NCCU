#include<iostream>
#include<fstream>
#include<set>
#include<vector>
#include<cmath>
using namespace std;

double slope(double x1,double y1,double x2,double y2){

    double xielv = (y1-y2)/(x1-x2);
    return xielv;
}
double max(double a,double b){
    if(a>b)
        return a;
    else
        return b;
}
double min(double a,double b){
    if(a<b)
        return a;
    else
        return b;
}

bool isInside(double x,double y){

    double borderX[9] = {0,110,130,390,520,450,440,230,110};
    double borderY[9] = {870,790,370,80,120,450,640,820,999};
    double s[8] = {-0.727273,-21,-1.11538,0.30769,-4.71429,-19,-0.857143,-1.49167};
    double m;

    if((x<=100 && y<=790 && y>=370) || (x<=130 && y<=370 && y>=80) || y<=80 || (x>=520 && y<=450 && y>=80) || (x>=450 && y<=820 && y>=450) || (x>=230 && y>=820)){
        return false;
    }
    for(int i=0;i<8;++i){
        if(x>=min(borderX[i],borderX[i+1]) && x<=max(borderX[i],borderX[i+1]) && y>=min(borderY[i],borderY[i+1]) && y<=max(borderY[i],borderY[i+1])){
            m = slope(x,y,borderX[i],borderY[i]);
            if(m < s[i]){
                return false;
            }
        }
    }

    return true;
}

double distance(double x1,double y1,double x2,double y2){
    double d = ((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2));
    return sqrt(d);
}

int main(){

    int n=100;
    double map[1000][600];
    set<vector<double>> node;

    srand(time(NULL));
    double x,y;
    string name[100];

    while(node.size() < n){

        y = rand() % 1000;
        x = rand() % 600;
        if(isInside(x,y) == true){

            node.insert(vector<double>{x,y});
        }
    }
    
    vector<vector<double>> nodes;
    for(vector<double>s:node){
        nodes.push_back(s);
    }

    /*for(int i=0;i<100;++i){
        cout << i << ' ' << nodes[i][0] << ' ' << nodes[i][1] << endl;
    }*/

    ofstream no;
    no.open("node100.txt");
    for(int i=0;i<n;++i){
        no << nodes[i][0] << ' ' << nodes[i][1];
        if(distance(300,400,nodes[i][0],nodes[i][1])<=100 || distance(200,700,nodes[i][0],nodes[i][1])<=100){
            no << " city" << endl;
            name[i] = "city";
        }
        else{
            no << " country" << endl;
            name[i] = "country";
        }
    }
    no.close();

    int numEdge = 0;
    ofstream ed;
    ed.open("edge100.txt");
    for(int i=0;i<n-1;++i){
        for(int j=i+1;j<n;++j){        
            if(name[i]=="city" && name[j]=="city"){
                if(distance(nodes[i][0],nodes[i][1],nodes[j][0],nodes[j][1]) <= 300){
                    ed << i << ' ' << j << endl;
                    ++numEdge;
                }
            }
            else if(name[i]=="city" && name[j]=="country"){
                if(distance(nodes[i][0],nodes[i][1],nodes[j][0],nodes[j][1]) <= 200){
                    ed << i << ' ' << j << endl;
                    ++numEdge;
                }
            }
            else if(name[i]=="country" && name[j]=="country"){
                if(distance(nodes[i][0],nodes[i][1],nodes[j][0],nodes[j][1]) <= 100){
                    ed << i << ' ' << j << endl;
                    ++numEdge;
                }
            }
        }
    }
    ed.close();

    double sumDis=0;
    ifstream infile;
    infile.open("edge100.txt");
    while(infile >> x >> y){
        sumDis += distance(nodes[x][0],nodes[x][1],nodes[y][0],nodes[y][1]);
    }
    double cn2 = n*(n-1)/2;
    cout << "m = " << numEdge << endl;
    cout << "average distance = " << sumDis/cn2 << endl;

    return 0;
}
