#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define eps 1e-10
#pragma GCC target("avx")

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

poli<double> p;

int main()
{
	mt19937 rd(time(NULL));
	IOS;
	int n;
	while(cin >> n){
		p.set(n+1);
		for(int i=n;i>=0;i--) cin >> p.v[i];
		double mn = 1.0/0.0,x;
		for(double i = -10.0; i <= 10.0 ; i += 0.01){
			double f = p.f(i);
			if(mn > fabs(f)) mn = fabs(f), x = i;
		}
		while(true){
			double fx = p.f(x);
			//cout << fabs(fx) << '\n';
			if(fabs(fx) < eps) break;
			double dx = p.df(x);
			x = x - fx/dx;
		}
		cout << fixed << setprecision(15) << x << '\n'; 
	}
   return 0;
}
