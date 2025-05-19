#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    while(N--){
        string input;
        cin>>input;
        int n = input.length();
        
        vector<vector<bool>> isPalindrome(n, vector<bool> (n, false));
        for(int r=0; r<n; r++){
            for(int l=0; l<=r; l++){
                if(input[l] == input[r] && (r-l <= 2 || isPalindrome[l+1][r-1]))
                    isPalindrome[l][r] = true;
            }
        } 

        vector<int> dp(n, 0);
        for(int i=0; i<n; i++){
            if(isPalindrome[0][i])
                dp[i] = 0;
            else{
                dp[i] = i;
                for(int j=1; j<=i; j++){
                    if(isPalindrome[j][i])
                        dp[i] = min(dp[i], dp[j-1]+1);
                }
            }
        }
        cout<<dp[n-1]+1<<endl;
    }
}