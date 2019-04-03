#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1000000
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

int hh(string &s){
	int64_t r = 0;
	for(char i : s)	r = r*31+i-'a';
	return (int)(r % 1000000007);
}

cc_hash_table<int,int> mp;

int main()
{
	IOS;
	string s;
	int n;
	while(cin >> n){
		int cnt = 1;
		mp.clear();
		for(int i=1;i<=n;i++){
			cin >> s; int h = hh(s);
			if(mp.find(h) != mp.end()) cout << "Old! " << mp[h] << "\n";
			else mp[h] = cnt,cout << "New! "<< cnt++ << "\n";
		}
	}
	
   return 0;
}


