#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 32768
#define lowbit(x) (x&-x)

int bt[N<<1];
int L[N];
int R[N];
int sn;
vector<int> v[N];

void dfs(int x,int p){
	L[x] = sn++; 
	for(int i : v[x]) if(i != p) dfs(i,x);
	R[x] = sn;
}

void add(int l,int r,int c){
	for(;l<=sn;l+=lowbit(l)) bt[l] += c;
	for(;r<=sn;r+=lowbit(r)) bt[r] -= c;
}

int val(int q){
	int sum = 0;
	for(;q;q-=lowbit(q)) sum += bt[q];
	return sum;
}

int main()
{
	IOS;
	int n,q,a,b;
	while(cin >> n){
		for(int i=0;i<n;i++) v[i].clear(); sn = 1;
		for(int i=1;i<n;i++){
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		dfs(0,0);
		memset(bt,0,sn+1<<2);
		cin >> q;
		while(q--){
			cin >> a >> b;
			add(L[a],R[a],b);
			cout << val(L[a]) << '\n';
		}
	}
   return 0;
}
