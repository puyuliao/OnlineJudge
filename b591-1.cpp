#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;
#define MAXN 2000
#define eps 1e-6

struct fun{
	double a,b;
	bool operator<(const fun &s){
		return a<s.a || (a == s.a && b<s.b);
	}
};
int n;
fun in[2000];
double ansy,ansx;

inline double f(double x){
	double y = 0;
	for(int i=0;i<n;i++) y = max(y,in[i].a*x+in[i].b);
	return y;
}

double search3(double l,double r){
	double m1,m2;
	double fl,fm1,fm2,fr;
	while(l+eps < r){
		m1 = l + (r-l)/3.0;
		m2 = r - (r-l)/3.0;
		fl = f(l); fr = f(r); fm1 = f(m1); fm2 = f(m2);
		if(fl < fm1+eps && fm1 < fm2+eps && fm2 < fr+eps) r = m2;
		else if(fl+eps > fm1 && fm1+eps > fm2 && fm2+eps > fr) l = m1;
		else if(fl+eps > fm1 && fm1 < fm2+eps && fm2 < fr+eps) r = m2;
		else if(fl+eps > fm1 && fm1+eps > fm2 && fm2 < fr+eps) l = m1;
		else {
			cout << l << ' ' <<m1 << ' '<< m2<< ' ' << r << '\n';
			cout << fl<<' ' << fm1 << ' ' << fm2 << ' ' << fr << '\n';
			break;
		}
	}
	return l;
}
/*if(fl < fm1 && fm1 < fm2 && fm2 < fr) r = m2;
		else if(fl > fm1 && fm1 > fm2 && fm2 > fr) l = m1;
		else if(fl > fm1 && fm1 < fm2 && fm2 < fr) r = m2;
		else if(fl > fm1 && fm1 > fm2 && fm2 < fr) l = m1;

*/
int main()
{
	IOS;
	while(cin >> n && n){
		for(int i=0;i<n;i++){
			cin >> in[i].a >> in[i].b;
		}
		ansx = search3(0,200);
		ansy = f(ansx);
		if(ansy <= 0+eps) cout << "0\n";
		else cout << fixed << setprecision(3) << ansy << ' ' << ansx << '\n';
	}

   return 0;
}


