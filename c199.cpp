#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}

vector<int> v;

int main()
{
	IOS;
	int n,t,ans = 0;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> t;
		v.push_back(t);
	}
	v.resize(unique(v.begin(),v.end()) - v.begin());
	int sz = v.size();
	for(int i=1;i<sz-1;i++){
		if(v[i] > v[i-1] && v[i] > v[i+1]) ans++;
	}
	cout <<  ans << '\n';
   return 0;
}


