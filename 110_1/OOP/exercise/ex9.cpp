#include<iostream>
using namespace std;

template <class T>
T add(T a,T b){
    return (a+b);
}

template <class T>
T divide(T a){
    return a/2;
}

int main(){
    string command;
    cin >> command;
    while(command != "-1"){
        if(command == "int"){
            int x,y;
            cin >> x >> y;
            int sum = add(x,y);
            sum = divide(sum);
            cout << "Mean: " << sum << endl;
        }
        else if(command == "float"){
            float c,d;
            cin >> c >> d;
            float Sum = add(c,d);
            Sum = divide(Sum);
            cout << "Mean: " << Sum << endl;
        }
        else if(command == "char"){
            char e,f;
            cin >> e >> f;
            int a = (long)e;
            int b = (long)f;
            int sUm = add(a,b);
            sUm = divide(sUm);
            char ans = sUm;
            cout << "Mean: " << ans << endl;
        }
        cin >> command;
    }
    return 0;
}
