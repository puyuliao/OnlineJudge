#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1000000
#define int int64_t

template<typename T>
struct poli{
	int n;
	vector<T> v;
	void set(int _n){
		n = _n;
		v.resize(n);
	}
	T f(T x){
		T ans = 0,r = 1;
		for(int i=0;i<n;i++) ans += r * v[i],r *= x;
		return ans;
	}
	T df(T x){
		T ans = 0,r = 1;
		for(int i=1;i<n;i++) ans += r * v[i] * i,r *= x;
		return ans;
	}
};

poli<int> p;

int32_t main()
{
	IOS;
	int w = 0;
	p.set(6); 
	for(int i=5;i>=0;i--) cin >> p.v[i],w += abs(p.v[i]);
	if(!w) return cout << "Too many... = =\"\n", 0;
	w = 0;
	for(int x=-39;x<=39;x++){
		int f1 = p.f(x), f2 = p.f(x-1);
		if(f1 && f2 && (f1^f2) >> 63) cout << x-1 << ' ' << x << '\n',w++; 
		if(f1 == 0) cout << x << ' ' << x << '\n',w++;
	}
	if(!w) cout << "N0THING! >\\\\\\<\n";
   return 0;
}


