#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 100000

int n,k;
int in[N];

bool chk(int x){
	int ans = 0;
	for(int l=0,r=0;r < n || in[r] - in[l] >= x;){
		if(in[r] - in[l] <= x) r++;
		if(in[r] - in[l] > x) ans += n-r,l++;
	}
	return ans > k-1;
}

int main()
{
	IOS;
	cin >> n >> k;
	for(int i=0;i<n;i++) cin >> in[i];
	sort(in,in+n);
	int l = 0, r = in[n-1] - in[0];
	while(l != r){
		int m = l + (r-l>>1);
		if(chk(m)) l = m+1;
		else r = m;
	}
	cout << l;
   return 0;
}
