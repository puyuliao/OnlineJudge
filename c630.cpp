#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1000000
#define eps 1e-12

struct pw{
	int a,n;
	double xd;
	pw(int _a,int _n):a(_a),n(_n),xd(log(a)*n){}
	bool operator<(const pw &b)const{
		if(xd + eps < b.xd || xd - eps > b.xd) return xd > b.xd;
		return a > b.a;
	}
};

vector<pw> v;

int main()
{
	IOS;
	int a,n;
	while(cin >> a >> n){
		v.push_back(pw(a,n));
	}	
	sort(v.begin(),v.end());
	for(auto i : v) cout << i.a << ' ' << i.n << '\n';
   return 0;
}


