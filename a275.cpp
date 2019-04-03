#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

int main()
{
	IOS;
	string a,b;
	while(cin >> a && a != "STOP!!"){
		cin >> b;
		if(a.size() != b.size()){
			cout << "no\n";
		}
		else{
			sort(a.begin(),a.end());
			sort(b.begin(),b.end());
			cout << (a==b?"yes\n":"no\n");
		}
	}

   return 0;
}


