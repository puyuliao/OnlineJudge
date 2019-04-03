#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

int st[N];
int ed[N];

int main()
{
	IOS;
	int n,x,r;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> x >> r;
		st[i] = x-r;
		ed[i] = x+r;
	}
	sort(ed,ed+n);
	int ans = 0;
	for(int i=0;i<n;i++){
		if(st[i] <= ed[0]) continue;
		ans += (int)(upper_bound(ed,ed+n,st[i]-1) - ed) - 1;
	}
	cout << ans << '\n'; 
   return 0;
}


