#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

int gcd(int a, int b){
	if(a % b == 0)	return b;
	else return gcd(b, a%b);
}

int main(){
	int test_cases, cows, eaten_cows = 0;
	int produce, days = 0, no_eat_days = 0;
	vector<vector<int>> v;
	vector<int> tmp;
	vector<int> c;
	string cycle;
	
	cin >> test_cases;
	while(test_cases){
		v.clear();
		c.clear();
		tmp.clear();
		cin >> cows;
		cin.ignore();
		eaten_cows = 0;
		days = 0;
		no_eat_days = 0;
		
		for(int i = 0;i < cows;i++){
			getline(cin, cycle);
			stringstream ss(cycle);
			ss >> produce;
			c.push_back(produce);
			while(ss >> produce)
				tmp.push_back(produce);
			v.push_back(tmp);
			tmp.clear();
		}
		int lcm = c[0];
		for(auto x : c){
			lcm = lcm * x / gcd(lcm, x);
		}
		
		for(int i = 0;i < 2520;i++){
			int min = 251, flag = -1, count = 0, min_flag = -1;
			for(int j = 0;j < cows-eaten_cows;j++){
				if(v[j][days%c[j]] < min){
					min = v[j][days%c[j]];
					min_flag = j;
				}
			}
			for(int j = 0;j < cows-eaten_cows;j++){
				if(v[j][days%c[j]] == min){
					count++;
					if(count == 2){
						flag = j;
						no_eat_days++;
						break;
					}
					
				}
			}
			if(flag == -1){
				eaten_cows++;
				no_eat_days = 0;
				v.erase(v.begin()+min_flag);
				c.erase(c.begin()+min_flag);
			}
			days++;
			if(eaten_cows == cows){
				break;
			}
		}
		cout << cows - eaten_cows << " " << days-no_eat_days << endl;
		test_cases--;
	}
	return 0;
}