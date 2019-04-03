#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

vector<int> v;

int main()
{
	IOS;
	int n,t;
	while(cin >> n){
		v.clear();
		while(n--){
			cin >> t;
			v.push_back(t);
		}
		sort(v.begin(),v.end());
		v.resize(unique(v.begin(),v.end()) - v.begin());
		for(int i : v) cout << i << ' ';
		cout << '\n';
	}

   return 0;
}


