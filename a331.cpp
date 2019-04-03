#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 100000
#define ND 20*N

int sum[ND],ls[ND],rs[ND],root[N+1],in[N],top;
vector<int> dc;

inline void cpy(int nw,int od){
	sum[nw] = sum[od];
	ls[nw] = ls[od];
	rs[nw] = rs[od];
}

int add(int old,int l,int r,int v){
	//cout << old << ' ' << l << ' ' << r << '\n';
	int x = top++;
	cpy(x,old);
	if(l == r) return sum[x]++, x;
	int m = l+r>>1;
	if(v <= m) ls[x] = add(ls[old],l,m,v);
	else  rs[x] = add(rs[old],m+1,r,v);
	sum[x] = sum[ls[x]] + sum[rs[x]];
	return x;
}

int qur(int ql,int qr,int l,int r,int k){
	while(l != r){
		int m = l+r>>1, lsum = sum[ls[qr]] - sum[ls[ql]];
		if(lsum >= k){
			ql = ls[ql]; qr = ls[qr];
			r = m;
		}
		else {
			ql = rs[ql]; qr = rs[qr];
			l = m+1;
			k-=lsum;
		}
	}
	return l;
}

int main()
{
	IOS;
	int n,q,l,r,k;
	while(cin >> n >> q){
		dc.clear();
		for(int i=0;i<n;i++) cin >> in[i],dc.push_back(in[i]);
		dc.resize(unique(dc.begin() , dc.end()) - dc.begin());
		sort(dc.begin(),dc.end());
		for(int i=0;i<n;i++) in[i] = (int)(lower_bound(dc.begin(),dc.end(),in[i]) - dc.begin());
		root[0] = 1; top = 2; 
		for(int i=1;i<=n;i++) {root[i] = add(root[i-1],0,dc.size()-1,in[i-1]);}
		while(q--){
			cin >> l >> r >> k;
			cout << dc[qur(root[l-1],root[r],0,dc.size()-1,k)] << '\n';
		}	
	}
   return 0;
}


