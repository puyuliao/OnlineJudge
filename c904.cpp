#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1005
#define eps 1e-4
typedef pair<double,double> pdd;

int val[N],w[N];
double at[N];

int main()
{
	IOS;
	int n,m,k,mx = 0;
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> w[i] >> val[i],mx = max(mx,val[i]);
	while(m--){
		cin >> k;
		double l = 0, r = mx;
		while(l+eps < r){
			double m = (l+r)*.5,t = 0;
			for(int i=0;i<n;i++) at[i] = -(val[i] - w[i]*m);
			nth_element(at,at+k,at+n);
			for(int i=0;i<k;i++) t -= at[i];
			if(t >= 0) l = m;
			else r = m;
		}
		cout << fixed << setprecision(2) << l << '\n';
	}
   return 0;
}
