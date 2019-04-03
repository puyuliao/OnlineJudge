#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 500000

int st[1048576];  //1 << (int)ceil(log2(N+2)) + 1;
int M;

int query(int l,int r){ // [l,r]
	if(l > r) swap(l,r);
	int ans = 0;
	for(l = l+M-1, r = r+M+1; l^r^1; l>>=1,r>>=1){
		if(~l&1) ans = max(ans,st[l^1]);
		if( r&1) ans = max(ans,st[r^1]);
	}
	return ans;
}

//void modify(int x,int k){
//	for(st[x+=M] = k,x>>=1;x;x>>=1){
//		st[x] = max(st[x+x],st[x+x+1]);
//	}
//}

void build(){
	for(int i=M;i>0;i--){
		st[i] = max(st[i+i],st[i+i+1]);
	}
}

int main()
{
	IOS;
	int n,q,a,b;
	cin >> n;
	for(M=1;M<n+2;M<<=1);   //M = 1 << (int)ceil(log2(n+2));
	for(int i=M+1;i<M+n+1;i++) cin >> st[i];
	build();
	cin >> q;
	while(q--){
		cin >> a >> b;
		cout << query(a,b) << '\n';
	}

   return 0;
}


