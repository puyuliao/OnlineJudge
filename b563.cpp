#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1000000

map<pair<int,int>,int > mp;

int main()
{
	IOS;
	int n,a,b;
	while(cin >> n){
		int ans=0; mp.clear();
		for(int i=0;i<n;i++){
			cin >> a >> b; 
			if(mp[{b,a}]>0) ans++,mp[{b,a}]--;
			else mp[{a,b}]++; 
		}
		cout << ans << '\n';
	}

   return 0;
}


