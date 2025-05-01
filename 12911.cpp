#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll N, T;
    while(cin>>N>>T){
        vector<ll> v(N, 0);
        unordered_map<ll, int> umap1, umap2;
        for(int i=0; i<N; i++)
            cin>>v[i];

        int N2 = N/2;
        for(int i=1; i<(1 << N2); i++){
            ll sum = 0;
            for(int j=0; j<N2; j++){
                if(i & (1<<j))
                    sum += v[j];
            }
            umap1[sum]++;
        }
        for(int i=1; i<(1 << (N-N2)); i++){
            ll sum = 0;
            for(int j=0; j<(N-N2); j++){
                if(i & (1<<j))
                    sum += v[j+N2];
            }
            umap2[sum]++;
        }
        int ans = 0;
        for(auto x : umap1){
            if(umap2.count(T-x.first)){
                ans += (x.second*(umap2[(ll)T-x.first]));
            }
        }
        cout<<ans+umap1[T]+umap2[T]<<endl;
    }
}