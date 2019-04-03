#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define INF 0xffffffffffffffff

unordered_set<uint64_t> s;

uint64_t gcd(uint64_t a,uint64_t b){
	if(b) while((a%=b) && (b%=a)); return a+b;
}

uint64_t powmo(uint64_t a,uint64_t b,uint64_t n){
	uint64_t ans = 1;
	for(;b;b>>=1){
		if(b&1) ans = (__int128)ans*a%n;
		a = (__int128)a*a%n;
	}
	return ans;
}

bool isprime(uint64_t n){
	if(n < 2 || (n!=2 && n%2==0)) return false;
	uint64_t sprp[7] = {2,325,9375,28178,450775,9780504,1795265022};
	uint64_t u=n-1,t=0;
	for(;u%2==0;u>>=1) t++;
	unsigned __int128 a;
	for(int i=0;i<3;i++){
		if(sprp[i] >= n) return true;
		a = (unsigned __int128)powmo(sprp[i],u,n);
		if(a == 1 || a == n-1) continue;
		for(int i=0;i<t;i++){
			a = a*a%n;
			if(a == n-1) break;
			if(a == 1) return false;
		}
		if(a == n-1) continue;
		return false;
	}
	return true;
}

uint64_t rho(uint64_t n,uint64_t c){
	uint64_t x=2,y=2,d=1,i=0,k=1;
	while(d==1){
		x = (powmo(x,2,n)+c)%n;
		d = gcd(max(y,x)-min(y,x),n);
		if(++i == k) i=0,y=x,k<<=1;
	}
	return d;
}

void fact(uint64_t n){
	if(isprime(n)) {
		s.insert(n);
		return;
	}
	uint64_t d = n;
	for(uint64_t c=1;d==n;c++){
		d = rho(n,c);
	}
	fact(d); fact(n/d);
}

int main()
{
	uint64_t n,t,d,ans;
	IOS;
	while(cin >> n && n){
		s.clear();
		if(n==1){
			cout << 0 << '\n';
			continue;
		} 
		fact(n);
		for(uint64_t i : s){
			n = n/i*(i-1);
		}
		cout << n << '\n';
	}
   return 0;
}
