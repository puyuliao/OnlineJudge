#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;

int64_t exgcd(int64_t p,int64_t q,int64_t &x,int64_t &y){
	if(q == 0) return x=1, y=0, p;
	int64_t d = exgcd(q,p%q,x,y);
	int64_t t = x;
	x = y;
	y = t - p/q*y;
	return d;
}

vector<int64_t> v;
int64_t m;

inline void push(int64_t p,int64_t q){
	int64_t x,y;
	int64_t d = exgcd(p,q,x,y);
	cout << p << '*' << x << ' ' << q << '*' << y << '\n'; 
	if((x*p - q*y)%d) return;
	v.push_back(((x*p - q*y)/d%m+m)%m);
}

int main()
{
	cin >> m;
	for(int64_t i=1;i*i <= m;i++) if(m % i == 0){
		push(i,m/i);
		push(m/i,i);
	}
	sort(v.begin(),v.end());
	cout << v.size() << '\n';
	for(int64_t i : v) cout << i << '\n';
  return 0;
}
