#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;

unordered_map<int64_t,int64_t> maap;

int64_t powmo(int64_t a,int64_t b,int64_t n){
	int64_t ans = 1;
	for(;b;b>>=1){
		if(b&1) ans = (__int128)ans*a%n;
		a = (__int128)a*a%n;
	}
	return ans;
}

int64_t rho(int64_t n,int64_t c){
	int64_t x = 2,y = 2,d = 1,i=0,k=1;
	while(d==1){
		x = ((__int128)x*x+c)%n;
		if(y > x) d = __gcd(y-x, n);
		else d = __gcd(x-y, n);
		if(d!=1) break;
		if(++i == k) y = x,k<<=1;
	}
	return d;
}

bool isprime(int64_t n){
	static int64_t sprp[] = {2,325,9375,28178,450775,9780504,1795265022};
	if(n < 2 || n!=2 && !(n&1)) return false;
	__int128 a; int64_t u = n-1,t = 0;
	for(;(u&1)==0;u>>=1)t++;
	for(int64_t i : sprp){
		a = powmo(i,u,n); 
		if(a <= 1 || a == n-1) continue;
		for(int i=1;i<t;i++){
			a = a*a%n;
			if(a == 1) return false;
			if(a == n-1) break;
		} 
		if(a == n-1) continue;
		return false;
	}
	return true;
}

void fact(int64_t n){
	stack<int64_t> s;
	s.push(n);
	while(!s.empty()){
		n = s.top(); s.pop();
		if(isprime(n)){
			maap[n]++;
			continue;
		}
		int64_t d=n;
		d = rho(n,-1);
		if(d==n) d = rho(n,1);
		while(d==n) d = rho(n,rand()%(n-1)+1);
		s.push(d); s.push(n/d);
	}
}

int main()
{
	IOS;
	int64_t n,ans,cnt = 0;
	while(cin >> n && n){
		while(!(n&1)) n >>= 1;
		ans = 1;
		maap.clear();
		if(n!=1) fact(n);
		for(auto i : maap){
			ans *= (i.second+1);
		}
		cout << ans-1 << '\n';
	}
   return 0;
}
