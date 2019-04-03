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

inline double chk(double x){
	double y = 0;
	for(int i=0;i<n;i++){
		y = max(y,in[i].a*x+in[i].b);
		if(y > ansy) break;	
	}
	return y;
}

int main()
{
	IOS;
	double tmp,t;
	while(cin >> n && n){
		for(int i=0;i<n;i++){
			cin >> in[i].a >> in[i].b;
		}
		ansy = 1e100;
		for(int i=0;i<n;i++){
			t = max(-in[i].b/in[i].a,0.0);
			tmp = chk(t); //x-intercept
			if(ansy > tmp) ansy = tmp,ansx = t;  
		}
		sort(in,in+n);
		if(abs(in[i].a - in[j].a) < eps) continue;
		t = max((in[j].b-in[i].b) / (in[i].a-in[j].a),0.0);
		tmp = chk(t);
		if(ansy > tmp) ansy = tmp,ansx = t;
		
		if(ansy <= 0+eps) cout << "0\n";
		else cout << fixed << setprecision(3) << ansy << ' ' << ansx << '\n';
	}

   return 0;
}


