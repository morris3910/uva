#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

bool check_doublet(string a, string b){
	if(a.length() != b.length())	return false;
	int diff = 0;
	for(int i = 0;i < a.length();i++){
		if(a[i] != b[i]) diff++;
	}
	return diff == 1;
}

int main(){
    unordered_map<string, vector<string>> doublets;
	vector<string> dic;
	string s, first, end;
	bool first_input = 1;
	while(getline(cin, s) && !s.empty())	
		dic.push_back(s);
	for(int i = 0;i < dic.size();i++){
		for(int j = i+1; j < dic.size();j++){
            if(check_doublet(dic[i], dic[j])){
                doublets[dic[i]].push_back(dic[j]);
                doublets[dic[j]].push_back(dic[i]);
            }
        }
	}
	while(cin >> first >> end){
		if(!first_input)
			cout<<endl;
		else
			first_input = 0;
        queue<vector<string>> q;
        vector<string> ans;
        vector<vector<string>> store_ans;
        int shortest = 99999;
        q.push({first});

        while(!q.empty()){
            vector<string> path = q.front();
            q.pop();

            if(path.size() > shortest) continue;

            string cur = path.back();

            if(cur == end){
                store_ans.push_back(path);
                shortest = path.size();
                continue;
            }

            for(auto x : doublets[cur]){
            	if(find(path.begin(), path.end(), x) == path.end()){
	                vector<string> tmp = path;
                    tmp.push_back(x);
                    q.push(tmp);
                }
            }
        }
        if(store_ans.size() == 0)	cout<<"No solution."<<endl;
        else{
            sort(store_ans.begin(), store_ans.end());
            for(int i = 0;i < store_ans[0].size();i++)
            	cout<<store_ans[0][i]<<endl;
        }
	}
}