#include<iostream>
#include<sstream>
#include<queue>
using namespace std;

struct cmp{
	bool operator()(pair<int, char> p1, pair<int, char> p2){
		if(p1.first == p2.first) return p1.second > p2.second;
		else return p1.first < p2.first;
	}
};

int main(){
    int n;
    cin >> n;
    cin.ignore();
    priority_queue<pair<int, char>, vector<pair<int, char>>, cmp> pq;
    vector<int> v(26, 0);
    for(int i = 0;i < n;i++){
        string s;
        getline(cin, s);
        stringstream ss(s);
        string tmp;
        while(ss >> tmp){
            for(auto x : tmp){
                if(x >= 'a' && x <='z'){
                	v[x-'a']++;
                }
                else if(x >= 'A' && x <= 'Z')
                    v[x-'A']++;
            }
        }
    }
    for(int i = 0;i < 26;i++){
        if(v[i] > 0){
            pq.push({v[i], 'A'+i});
        }
    }
    while(!pq.empty()){
        pair<int, char> p;
        p = pq.top();
        cout<<p.second<<" "<<p.first<<endl;
        pq.pop();
    }
}