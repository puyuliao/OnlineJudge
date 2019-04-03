#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 100020
#define MEM 2000000

int deep[MEM],fa[MEM],ls[MEM],rs[MEM];
int root[N];
int top = 1,n;

void copy(int f,int s){
	ls[f] = ls[s];
	rs[f] = rs[s];
	deep[f] = deep[s];
	fa[f] = fa[s];
}

int build(int l,int r){
	int x = top++;
	if(l == r) return deep[x] = 1,fa[x] = l, x;
	int m = l + r >> 1;
	ls[x] = build(l,m);
	rs[x] = build(m+1,r);
	return x;
}

int qur(int x,int l,int r,int a){
	while(l!=r){
		int m = l+r>>1;
		if(m < a) l = m+1,x = rs[x];
		else r = m,x = ls[x];
	}
	return x;
}

int find(int x,int a){
	int t = qur(x,1,n,a);
	if(a == fa[t]) return a;
	return find(x,fa[t]);
}

int modify(int old,int l,int r,int a,int v){ // fa
	int x = top++;
	copy(x,old);
	if(l == r) return fa[x] = v, x;
	int m = l+r>>1;
	if(m < a) rs[x] = modify(rs[old],m+1,r,a,v);
	else ls[x] = modify(ls[old],l,m,a,v);
	return x;
}

int add(int old,int l,int r,int a,int v){ // deep
	int x = top++;
	copy(x,old);
	if(l == r) return deep[x] = deep[old]+v, x;
	int m = l+r>>1;
	if(m < a) rs[x] = add(rs[old],m+1,r,a,v);
	else ls[x] = add(ls[old],l,m,a,v);
	return x;
}
int main()
{
	//IOS;
	int m,cmd,x,y,ans = 0;
	cin >> n >> m;
	root[0] = build(1,n);
	for(int i=1;i<=m;i++){
		cin >> cmd; cmd ^= ans;
		if(cmd == 0){
			cin >> x; x ^= ans;
			root[i] = top++;
			copy(root[i],root[x]);
		}
		else if(cmd == 1){
			cin >> x >> y; x ^= ans; y ^= ans;
			x = find(root[i-1],x); y = find(root[i-1],y); 
			if(x == y) continue;
			if(deep[x] < deep[y]) swap(x,y);
			root[i] = modify(root[i-1],1,n,y,x);
			if(deep[x] == deep[y]) root[i] = add(root[i],1,n,x,1);
		}
		else{
			cin >> x >> y; x ^= ans; y ^= ans;
			root[i] = root[i-1];
			x = find(root[i-1],x); y = find(root[i-1],y); 
			if(x == y) ans = 1; else ans = 0;
			cout << ans << '\n';
		}
		cout << i << " :"; for(int j=1;j<=n;j++) cout << ' ' << find(root[i],j); cout << '\n'; ans = 0;
	}

   return 0;
}


