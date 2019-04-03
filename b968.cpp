/*input
24408308522758834075998738379
*/
#include <bits/stdc++.h>
#include <stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1000000
#pragma GCC optmize("Ofast");
//#define __int128 int64_t
map<__int128,int> mp;
vector<int> p;
int fac[N];
void build(){
	fac[0] = 0; fac[1] = 1;
	for(int i=2;i<N;i++){
		if(!fac[i]) fac[i] = i,p.push_back(i);
		for(int j=0;i*p[j] < N;j++){
			fac[i * p[j]] = p[j];
			if(i % p[j] == 0) break;
		}
	}
}

void print(__int128 x){
	vector<int> v;
	if(!x){
		cout << 0;
		return;
	}
	while(x){
		v.push_back(x%10);
		x/=10;
	}
	while(v.size()) cout << v.back(), v.pop_back();
}

__int128 gcd(__int128 a,__int128 b){
	if(b) while((a%=b) && (b%=a));
	return a+b;
}

__int128 mul(__int128 a,__int128 b,__int128 n){
	__int128 r = 0; a %= n;
	__int128 t;
	static __int128 h = 4294967295;
	if(!b) return r;
	if(t = (b&h)){
		r += a*t;
		if(r >= n) r%=n;
	}
	a = (a << 32) % n;
	if(a >= n) a %= n;
	b>>=32;
	if(!b) return r;
	if(t = (b&h)){
		r += a*t;
		if(r >= n) r%=n;
	}
	a = (a << 32) % n;
	if(a >= n) a %= n;
	b>>=32;
	if(!b) return r;
	if(t = (b&h)){
		r += a*t;
		if(r >= n) r%=n;
	}
	a = (a << 32) % n;
	if(a >= n) a %= n;
	b>>=32;
	if(!b) return r;
	if(t = (b&h)){
		r += a*t;
		if(r >= n) r%=n;
	}
	a = (a << 32) % n;
	if(a >= n) a %= n;
	b>>=32;
	return r;
}

__int128 powmo(__int128 a,__int128 b,__int128 n){
	__int128 r = 1;
	for(;b;b>>=1){
		if(b&1) r = mul(r,a,n);
		a = mul(a,a,n);
	}
	return r;
}

bool isprime(__int128 n){
	if(n % 2 == 0 || n < 2) return n == 2;
	mt19937 rd(time(NULL));
	__int128 u = n-1,t = 0;
	for(;!(u&1);u>>=1) t++;
	for(int i=0;i<9;i++){
		__int128 a = powmo(rd()%n,u,n);
		if(a == 0 || a == n-1 || a == 1) continue;
		for(int j=0;j<t;j++){
			a = mul(a,a,n);
			if(a == 1) return false;
			if(a == n-1) break;
		}
		if(a == n-1) continue;
		return false;
	}
	return true;
}

__int128 rho(__int128 n,int c){
	__int128 x,y;
	x = y = 0;
	while(true){
		x = mul(x,x,n) + c;
		if(x >= n) x -= n;
		x = mul(x,x,n) + c;
		if(x >= n) x -= n;
		y = mul(y,y,n) + c;
		if(y >= n) y -= n;
		__int128 d = x-y;
		if(d < 0) d = -d;
		__int128 g = gcd(d,n);
		if(g != 1) return g;
	}
}

void factor(__int128 n){
	if(n < 2) return;
	if(n < N){
		if(fac[n] == n) return mp[n]++, void();
		mp[fac[n]] ++;
		factor(n / fac[n]);
		return;
	}
	if(isprime(n)) return mp[n]++, void();
	__int128 d = n;
	mt19937 xd(time(NULL));
	for(int c = 1; d == n; c = xd()) d = rho(n,c);
	factor(d);
	factor(n/d); 
}

int main()
{
	IOS;
	build();
	string n;
	cin >> n;
	__int128 a = 0;
	for(char i : n) a = a*10 + (i-'0');
	factor(a);
	cout << (int)mp.begin()->first << '\n'; 
	return 0;
}


