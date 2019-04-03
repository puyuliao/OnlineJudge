#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define MEM 3000000
#define N 50001
#define MOD 1000000007

struct node{
	int ls, rs, sum;
	int64_t mus;
}st[N];
int top;
int md[N];

int64_t powmo(int64_t a,int64_t b,int64_t n){
	int64_t r = 1;
	for(;b;b>>=1){
		if(b&1) r=r*a%n;
		a=a*a%n;
	}
	return r;
}

void add(int l,int r,int od,int &x,int k){
	x = ++top;	
	st[x] = st[od]; 
	if(r == l) return st[x].mus = st[x].mus*k%MOD, st[x].sum++, void();
	int m = l + r >> 1;
	if(k <= m) add(l,m,st[od].ls,st[x].ls,k);
	else add(m+1,r,st[od].rs,st[x].rs,k);
	st[x].sum = st[st[x].ls].sum + st[st[x].rs].sum;
	st[x].mus = st[st[x].ls].mus * st[st[x].rs].mus % MOD;
}

void qur(int l,int r,int od,int x,int k,int &a1,int64_t &a2){
	if(r == l) return a1 += st[x].sum - st[od].sum, a2 = a2*st[x].mus%MOD*powmo(st[od].mus,MOD-2,MOD)%MOD,void();
	int m = l + r >> 1;
	if(k <= m) return qur(l,m,st[od].ls,st[x].ls,k,a1,a2);
	else {
		a1 += st[st[x].ls].sum - st[st[od].ls].sum;
		a2 = a2 * st[st[x].ls].mus%MOD*powmo(st[st[od].ls].mus,MOD-2,MOD)%MOD;
		return qur(m+1,r,st[od].rs,st[x].rs,k,a1,a2);
	}
}

void print(int l,int r,int x){
	if(!x) return;
	cout << x << " : " << l << '~' << r << " : " << st[x].sum << ' ' << st[x].mus << '\n';
	int m = l+r>>1;
	print(l,m,st[x].ls);
	print(m+1,r,st[x].rs);
}

int main()
{
	//IOS;
	int n,q,nd,l,r,k,a1; int64_t a2;
	while(cin >> n >> q){
		md[0] = top = 1; memset(md,0,sizeof(md)); st[0].mus = st[1].mus = 1;
		for(int i=1;i<=n;i++) cin >> k,add(1,n,md[i-1],md[i],k);//,print(1,n,md[i]),cout << '\n';
		while(q--){
			cin >> l >> r >> k;
			a1 = 0,a2 = 1;
			qur(1,n+1,md[l-1],md[r],k,a1,a2);
			if(!a1) cout << "0 0\n";
			else cout << a1 << ' ' << a2 << '\n'; 
		}
	}

   return 0;
}


