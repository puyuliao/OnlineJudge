#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 50000

int n,k;
int in[N];

bool chk(int x){
	int t = k-1,lst = in[0]; 
	for(int i=1;i<n;i++){
		if(in[i] - lst > x) lst = in[i],t--;
	}
	return t>=0;
}

int main()
{
	IOS;
	cin >> n >> k;
	for(int i=0;i<n;i++) cin >> in[i];
	sort(in,in+n);
	int l = 0, r = 1 << 30;
	while(l != r){
		int mid = l + ((r - l)>>1);
		if(!chk(mid)) l = mid+1;
		else r = mid;
	}
	cout << l << '\n';
   return 0;
}


