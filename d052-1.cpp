#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 2000

int in[N];
int lis[N];
int lds[N];

bool cmp(int a,int b){
	return a > b;
}

void build(int n){
	vector<int> v;
	vector<int>::iterator it;
	v.push_back(-1);
	for(int i=0;i<n;i++){		
		if(in[i] > v.back()) {
			v.push_back(in[i]);
			lis[i] = v.size() - 1;
		}
		else {
			it = lower_bound(v.begin(),v.end(),in[i]);
			lis[i] = it - v.begin();
			*it = in[i];
		}
	}
	
	v.clear();
	v.push_back(0x7fffffff);
	for(int i=0;i<n;i++){
		if(in[i] < v.back()){
			v.push_back(in[i]);
			lds[i] = v.size() - 1;
		}
		else{
			it = lower_bound(v.begin(),v.end(),in[i],cmp);
			lds[i] = it - v.begin();
			*it = in[i];
		}
	} 
}

int main()
{
	IOS;
	int T,n;
	cin >> T;
	while(T--){
		cin>>n;
		for(int i=n-1;i>=0;i--) cin >> in[i];
		
		build(n);
		int ans = 0;
		for(int i=0;i<n;i++) ans = max(ans,lis[i] + lds[i] - 1);
		cout << ans << '\n';
	}

   return 0;
}


