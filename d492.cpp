#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

map<string,int> maap;

int main()
{
	IOS;
	int T,sz;
	string in;
	cin >> T;
	getline(cin,in);
	getline(cin,in);
	while(T--){
		maap.clear();
		sz = 0;
		while(true){
			getline(cin,in);
			if(in == "") break;
			maap[in] ++; sz ++;
		}
		for(auto i : maap){
			cout << i.first << ' ' << fixed << setprecision(4) <<(double)i.second/sz*100 << '\n';
		}
		cout << '\n';
	}

   return 0;
}


