#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

unordered_map<string,string> maap;

int main()
{
	IOS;
	maap["HELLO"] = "ENGLISH";
	maap["HOLA"] = "SPANISH";
	maap["HALLO"] = "GERMAN";
	maap["BONJOUR"] = "FRENCH";
	maap["CIAO"] = "ITALIAN";
	maap["ZDRAVSTVUJTE"] = "RUSSIAN";
	string s;int cnt = 0;
	while(cin >> s && s != "#"){
		cout << "Case " << (++cnt) << ": ";
		if(!maap.count(s)) cout << "UNKNOWN\n";
		else cout << maap[s] << '\n';
	}

   return 0;
}


