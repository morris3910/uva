#include<iostream>
using namespace std;

int main(){
	int input;
	cout<<"PERFECTION OUTPUT"<<endl;
	while(cin >> input){
		if(input == 0)
			break;
			
		int count = 1;
		for(int i = 2;i < input;i++){
			if(!(input - (input/i)*i))
				count += i;
		}
		
		printf("%5d  ", input);
		if(count == input)
			cout<<"PERFECT"<<endl;
		else if(count < input)
			cout<<"DEFICIENT"<<endl;
		else
			cout<<"ABUNDANT"<<endl;
	
	}
	cout<<"END OF OUTPUT"<<endl;
	return 0;
}