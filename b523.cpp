#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;

set<string> s;
string in;

int main()
{
	IOS;
	while(getline(cin,in)){
		if(s.count(in)){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
			s.insert(in);
		}
	}

   return 0;
}


