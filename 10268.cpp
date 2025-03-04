#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

int main(){
	int a, tmp;
	vector<int> b;
	string s;
	
	while(cin >> a){
		int ans = 0;
		cin.ignore();
		getline(cin, s);
		stringstream ss(s);
		
		while(ss >> tmp){
			b.push_back(tmp);
		}
		for(int i = 0;i < b.size()-1;i++){
			int mul_a = 1;
			if((b.size()-i-1) > 1){
				for(int j = 0;j < b.size()-i-2;j++)
					mul_a *= a;
				ans += mul_a * b[i] * (b.size()-i-1);
			}else
				ans += (b[i])*(b.size()-i-1);
		}
		cout << ans << endl;
		b.clear();
	}
	return 0;
}