#include<bits/stdc++.h>
using namespace std;

int main(){
    string haab_month[19] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
    string tzolkin_month[20] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
    int N;
    cin>>N;
    cout<<N<<endl;
    while(N--){
        int number, year, days = 0;
        string str;
        cin>>number;
        cin.ignore();
        cin>>str>>year;
        days += year*365 + number;
        for(int i=0; i<19; i++){
            if(haab_month[i] == str)
                days += 20*i;
        }

        int ans_year = days/260, ans_day;  
        string ans_month;
        days %= 260;
        ans_month = tzolkin_month[days%20];
        ans_day = days%13;
        cout<<ans_day+1<<" "<<ans_month<<" "<<ans_year<<endl;
    }
}