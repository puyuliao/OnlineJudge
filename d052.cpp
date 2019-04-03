#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 2000

int in[N];

int LIS(int n){
	vector<int> v;
	v.push_back(in[0]);
	for(int i=1;i<n;i++){
		if(in[i] > v.back()) v.push_back(in[i]);
		*lower_bound(v.begin(),v.end(),in[i]) = in[i];
	}
	//for(int i : v) cout << i << ' '; 
	return v.size();
}

int main()
{
	IOS;
	int n,T;
	cin >> T;
	while(T--){
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> in[i];
		}
		cout << LIS(n) << '\n';
	}

   return 0;
}


