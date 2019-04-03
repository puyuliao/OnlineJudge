#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 500000

int sp[32 - __builtin_clz(N)][N];

void build(int L){
	for(int i=1;1<<i <= L;i++){
		for(int j=0;j+(1<<i) <= L;j++)
			sp[i][j] = max(sp[i-1][j],sp[i-1][j + (1<<i-1)]);
	}
}

int query(int l,int r){
	if(l > r) swap(l,r);
	l--;
	int p = __lg(r-l);
	//cout << l << ' ' <<r << ' ' << p << '\n';
	return max(sp[p][l],sp[p][r - (1<<p)]);
}

int main()
{
	IOS;
	int n,q,l,r;
	cin >> n;
	for(int i=0;i<n;i++) cin >> sp[0][i];
	build(n);
	cin >> q;
	while(q--){
		cin >> l >> r;
		cout << query(l,r) << '\n';
	}

   return 0;
}


