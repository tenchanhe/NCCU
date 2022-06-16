#include<iostream>
#include<string>
using namespace std;

int main(){
	string array;
	int len,ans,count;
	while(cin >> array){
		//cout << array << endl;
		len = array.size();
		ans=0,count=0;
		for(int i=0;i<len;++i){
			if(array[i] == 'R')
				++count;
			else
				--count;
			if(count == 0)
				++ans;
		}
		cout << ans << endl;
	}

	return 0;
}

