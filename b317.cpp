#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 100000

pair<int,int> in[N];

int main()
{
	IOS;
	int n,k,mn = N << 10;
	cin >> n >> k;
	for(int i=0;i<n;i++) cin >> in[i].first >> in[i].second;
	sort(in,in+n);
	for(int h=1;h<=100;h++){
		int mxr = 0,j=0;
		for(int i=0;i<n&&j<k;i++) if(in[i].second <= h) mxr = max(mxr,in[i].first), j++;
		if(j < k) continue;
		mn = min(mn,mxr*mxr*h*4);
	}
	cout << mn << '\n';
   return 0;
}
