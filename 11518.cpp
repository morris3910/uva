#include<bits/stdc++.h>
using namespace std;

int main(){
    int times;
    cin >> times;
    while(times--){
        int n, m, l;
        unordered_map<int, vector<int>> umap;
        set<int> ans;
        cin >> n >> m >> l;
        while(m--){
            int first, second;
            cin >> first >> second;
            umap[first].push_back(second);
        };
        stack<int> s;
        while(l--){
            int domino;
            cin >> domino;
            s.push(domino);
        }
        while(!s.empty()){
            int tmp = s.top();
            s.pop();
            ans.insert(tmp);
            if(umap.count(tmp)){
                for(auto x : umap[tmp])
                    s.push(x);
            }
        }
        cout<<ans.size()<<endl;
    }
}