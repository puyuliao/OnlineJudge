#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;

pair<int,int> in[200004];

int main()
{
	IOS;
	int n,m,l,r;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> l >> r;
		in[i].first = l;
		in[i].second = 1;
		in[m+i].first = r+1;
		in[m+i].second = -1;
	}
	m<<=1;
	sort(in,in+m);
	int val = 0, pos = 0, ans = 0;
	for(int i=0; i<m; i++){
		ans += (in[i].first - pos)*(val&1);
		pos = in[i].first;
		val += in[i].second;
	}
	cout << n-ans << '\n';
   return 0;
}


