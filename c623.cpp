#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1000000
#define int int64_t
const int MOD = 1000000007;

int powmo(int a,int b){
	int r = 1;
	for(;b;b>>=1) {
		if(b&1) r = r*a%MOD;
		a=a*a%MOD;
	}
	return r;
}

int C(int n,int r){
	r = max(r,n-r);
	int ans = 1;
	for(int i=n;i>r;i--) ans *= i;
	for(int i=2;i<=n-r;i++) ans /= i;
	return ans;
}

int32_t main()
{
	//IOS;
	string sn;
	int c,n = 0;
	while(cin >> sn >> c){
		n = 0;
		for(char i : sn) n = (n*10 + i-'0') % MOD; 
		int ans = 0;
		for(int i=0;i<=n;i++) ans = (ans + C(n,i) * powmo(i,c)) % MOD;
		cout << (double)ans/pow(2,n-c) << '\n';
	}

   return 0;
}


