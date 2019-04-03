#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define eps 0.000001

inline bool iszero(double a){
	return abs(a) < eps;
}

int main()
{
	IOS;
	double a,b,c,d;
	while(cin >> a >> b >> c >> d){
		if(iszero(a) && iszero(b) && iszero(c) && iszero(d) ) break;
		double det = a*d-b*c;
		if(iszero(det)){
			cout << "cheat!\n";
			continue;
		}
		cout << fixed << setprecision(5) << d/det << ' ' << -b/det << '\n' << -c/det << ' ' << a/det << '\n';
	}

   return 0;
}


