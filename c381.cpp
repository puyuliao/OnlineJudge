#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

int main()
{
	IOS;
	string s,in;
	int n,m,t;
	while(cin >> n >> m && (n||m)){
		s = "";
		while(n--) {
			cin >> in;
			s += in;
		}
		while(m--){
			cin >> t;
			cout << s[t-1];
		}
		cout << '\n';
	}
	

   return 0;
}


