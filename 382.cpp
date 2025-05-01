#include<iostream>
#include<vector>
using namespace std;

int main(){
	int input;
	vector<int> v;
	
	while(cin >> input){
		if(input == 0)
			break;
		v.push_back(input);
	}	
	cout<<"PERFECTION OUTPUT"<<endl;
	for(int i=0; i<v.size(); i++){
		int count = 0;
		for(int j = 1;j < v[i];j++){
			if(v[i]%j == 0)
				count += j;
		}
		printf("%5d  ", v[i]);
		if(count == v[i])
			cout<<"PERFECT"<<endl;
		else if(count < v[i])
			cout<<"DEFICIENT"<<endl;
		else
			cout<<"ABUNDANT"<<endl;
	}	
	cout<<"END OF OUTPUT"<<endl;
	return 0;
}