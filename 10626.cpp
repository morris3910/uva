#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while (n--){
        int num, one, five, ten;
        cin >> num >> one >> five >> ten;
        int count = 0;        
        
        if(ten >= num)
            count += num;
        else{
            num -= ten;
            count += ten;
            if(num > five){
                count += five*4;
                num -= five;
                if(ten >= num) count += num*7;
                else {
                    count += ten*7;
                    num -= ten;
                    count += num*8;
                }

            }else if(five/2 >= num){
                count += num*2;
            }else{
                while(num && five/2 < num){
                    count += 4;
                    num--;
                    five--;
                }
                if(num){
                    count += num*2;
                }
            }
        }
        cout<<count<<endl;
    }
}