#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 300001
#define M 300001
#define MEM 21200000

int64_t *sum = new int64_t[MEM];
int64_t *chg = new int64_t[MEM];
int *ls = new int[MEM];
int *rs = new int[MEM];
int in[N],root[M];
int64_t pre[N];
int top = 1;

inline void push(int x,int l,int r,bool create = false){
	if(chg[x] && l != r){
		int m = l+r>>1,old;
		if(create){
			old = ls[x];
			ls[x] = top++;
			ls[ls[x]] = ls[old]; rs[ls[x]] = rs[old]; sum[ls[x]] = sum[old]; chg[ls[x]] = chg[old]; 
		}
		sum[ls[x]] += chg[x]*(m-l+1), chg[ls[x]] += chg[x];
		if(create){
			old = rs[x];
			rs[x] = top++;
			ls[rs[x]] = ls[old]; rs[rs[x]] = rs[old]; sum[rs[x]] = sum[old]; chg[rs[x]] = chg[old]; 
		}
		sum[rs[x]] += chg[x]*(r-m),chg[rs[x]] += chg[x];		
		chg[x] = 0;
	} 
}

inline void pull(int x){
	sum[x] = sum[ls[x]] + sum[rs[x]];
}

void add(int l,int r,int ql,int qr,int old,int &x,int v){
	if(!x) x = top++;
	push(old,l,r,true);
	sum[x] = sum[old]; chg[x] = chg[old]; 
	if(r < ql || l > qr) return ls[x] = ls[old],rs[x] = rs[old], void();
	if(ql <= l && r <= qr) return sum[x] += (int64_t)v*(r-l+1),chg[x] += v,ls[x] = ls[old],rs[x] = rs[old],void();
	int m = l+r>>1;
	add(l,m,ql,qr,ls[old],ls[x],v);
	add(m+1,r,ql,qr,rs[old],rs[x],v);
	pull(x);
}

int64_t query(int old,int x,int l,int r,int ql,int qr){
	push(old,l,r,true);
	push(x,l,r,true);
	if(r < ql || l > qr) return 0;
	if(ql <= l && r <= qr) return sum[x] - sum[old];
	int m = l+r>>1;
	return query(ls[old],ls[x],l,m,ql,qr) + query(rs[old],rs[x],m+1,r,ql,qr);
}

int main()
{
	IOS;
	int n,m,l,r,v,q,a,b;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> in[i],pre[i] = pre[i-1] + in[i];
	for(int i=1;i<=m;i++){
		cin >> l >> r >> v;
		add(1,n,l,r,root[i-1],root[i],v);
		if(top >= MEM *.90) return cout << "MEMEXCEED " << i,0;
	}
	cin >> q;
	while(q--){
		cin >> l >> r >> a >> b;	
		cout << pre[r] - pre[l-1] + query(root[a-1],root[b],1,n,l,r) << '\n';
	}
   return 0;
}

/*
void print(int x,int l,int r){
	if(!x) return;
	push(x,l,r);
	//cout << l << ' ' << r << ' ' << sum[x] << '\n';
	int m = l+r>>1;
	print(ls[x],l,m);
	print(rs[x],m+1,r);
}
//cout << query(root[a-1],root[b],1,n,l,r) << '\n';
//print(root[i],1,n); cout << "\n\n";
//cout << l << ' ' << r << ' ' << ql << ' ' << qr << ' ' << sum[old] << ' ' << sum[x] << '\n';
*/
