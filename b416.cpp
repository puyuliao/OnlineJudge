//TLE test5;

#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 100000
#define SZ 289

int n;
int in[N];
int block[N/SZ+2][SZ];
int top,topsz;

void build(){
	for(int i=0;i<n;i++){
		block[top][topsz++] = in[i];
		if(topsz == SZ) top++,topsz = 0;
	}
	for(int i=0;i<top;i++) sort(block[i],block[i]+SZ);
	if(topsz) sort(block[top],block[top]+SZ);
}

int qur(int l,int r,int a,int b){
	int bl = (l+SZ-1)/SZ; int br = (r+1)/SZ;
	int ans = 0;
	if(bl >= br){
		for(int i=l;i<=r;i++) if(a <= in[i] && in[i] <= b) ans++;
		return ans;
	}
	int e = bl*SZ; 
	for(int i=l;i<e;i++) if(a <= in[i] && in[i] <= b) ans++;
	for(int i=br*SZ;i<=r;i++) if(a <= in[i] && in[i] <= b) ans++;
	for(int i=bl;i<br;i++){ 
		ans += (int)(upper_bound(block[i],block[i]+SZ,b) - lower_bound(block[i],block[i]+SZ,a));
	}
	return ans;	
}

int main()
{
	IOS;
	int m,l,r,a,b;
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> in[i];
	build();
	while(m--){
		cin >> l >> r >> a >> b;
		cout << qur(l-1,r-1,a,b) << '\n';
	}
   return 0;
}

