#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 100000

int fa[N],deep[N];

struct road{
	int a,b,c;
	bool operator<(const road &r)const{
		return c < r.c;
	}
}in[N<<1];


int find(int a){
	return (a==fa[a])?a:(fa[a] = find(fa[a]));
}

bool uin(int a,int b){
	a = find(a); b = find(b);
	if(a != b){
		if(deep[a] < deep[b]) swap(a,b);
		fa[b] = a;
		deep[a] += (deep[a] == deep[b])?1:0;
		return true;
	} 
	return false;
}

int main()
{
	IOS;
	int n,m,a,b,c;
	int64_t ans = 0;
	while(cin >> n >> m){
		ans = 0;
		for(int i=0;i<n;i++) fa[i] = i, deep[i] = 1;
		for(int i =0;i<m;i++){
			cin >> in[i].a >> in[i].b >> in[i].c;
		}
		sort(in,in+m);
		for(int i=0;i<n;i++){
			if(!uin(in[i].a,in[i].b)) continue;
			ans += in[i].c;
			if(--n == 1) break;
		}
		if(n > 1) cout << -1 << '\n';
		else cout << ans << '\n';
	}
}


