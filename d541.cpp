#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1234567

int powmo(int a,int b,int mod){
	if(b<0) return 0;
	int ans = 1;
	for(;b;b>>=1){
		if(b&1) ans = (int64_t)ans*a%mod;
		a = (int64_t)a*a%mod;
	} 
	return ans;
}

int main()
{
	IOS;
	int n;
	while(cin >> n){
		cout << powmo(2,n-1,N) <<'\n';
	}

   return 0;
}


