#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1000000
#define int uint_fast64_t

int powmo(int a,int b,int n){
	int r = 1;
	for(;b;b>>=1){
		if(b&1) r = r*a%n;
		a = a*a%n;
	}
	return r;
}

bool isprime(int n){
	if(n < 2 || n % 2 == 0) return n == 2;
	int u = n-1,t=0;
	for(;u%2==0;u>>=1)t++;
	for(int x : {2,7,61}){
		int a = powmo(x,u,n);
		if(a == 0 || a == 1 || a == n-1) continue;
		for(int i=0;i<t;i++){
			a = a*a % n;
			if(a == 1 || a == n-1) break; 
		}
		if(a == n-1) continue;
		return false;
	}
	return true;
}

int32_t main()
{
	IOS;
	int t,mn,mx,x;
	cin >> t >> mn >> mx;
	while(t--){
		cin >> x; x++;
		int t = x;
		while(t % 3 == 0 || t % 5 == 0 || t % 7 == 0 || !isprime(t)) t++;
		cout << t << '\n';
	}
   return 0;
}
