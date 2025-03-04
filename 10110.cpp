#include<iostream>
using namespace std;

int main(){
	long long int input;
	while(cin >> input){
		if(!input)
			return 0;
		int count = 0;
		for(long long int i = 1;i * i <= input;i++){
			if(!(input%i) && i != input/i)
				count+=2;
			else if(!(input%i))
				count++;
		}
		if(count%2)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
}