#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_map<string, string> umap;
	umap["HELLO"] = "ENGLISH";
	umap["HOLA"] = "SPANISH";
	umap["HALLO"] = "GERMAN";
	umap["BONJOUR"] = "FRENCH";
	umap["CIAO"] = "ITALIAN";
	umap["ZDRAVSTVUJTE"] = "RUSSIAN";
    string s;
    int pos = 1;
    cin >> s;
    while(s != "#"){
    	auto it = umap.find(s);
    	if(it == umap.end())
    		cout<< "Case " << pos++ << ": " << "UNKNOWN" <<endl;
    	else
    		cout<< "Case " << pos++ << ": " <<(*it).second <<endl;
    	cin >> s;
    }
    return 0;
}
