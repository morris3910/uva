#include<iostream>
#include<vector>
using namespace std;

bool checkPrime(long long int n){
	for(long long int i = 2;i*i <= n;i++){
		if(n%i == 0)
			return false;
	}	
	return true;
}

int main(){
	int n;
	long long int head, tail;
	cin >> n;
	while(cin >> head >> tail){
		int count = 0;
		for(long long int i = head;i <= tail;i++){
			if(checkPrime(i))
				continue;
			int primeNums = 0;
			for(long long int j = 2;j*j <= i;j++){
				if((!(i%j)) && checkPrime(j))
					primeNums++;
				if((!(i%j)) && checkPrime(i/j) && (j != i/j))
					primeNums++;
				if(primeNums > 1)
					break;
			}
			if(primeNums == 1) 
				count++;
		}
		cout<<count<<endl;
	}
}