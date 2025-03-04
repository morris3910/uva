#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	long int input, n = 1;
	vector< long long int > v;
	while(cin >> input){
		v.push_back(input);
		sort(v.begin(), v.end());
		if(n%2)
			cout<<v[n/2]<<endl;
		else
			cout<<(v[n/2]+v[(n/2)-1])/2<<endl;
		n++;
	}
}