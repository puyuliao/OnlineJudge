#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 100000ll

int64_t k = 0;

struct node{
	vector<int64_t> arr;
	int64_t l,r;
	int64_t sum;
}st[262144];

int64_t in[N];

void build(int64_t l,int64_t r,int64_t n){
	if(l == r-1){
		st[n].arr.push_back(in[l]);
		st[n].l = l; st[n].r = r;
		st[n].sum = in[l];
		return;
	}
	
	int64_t mid = l+r>>1;
	build(l,mid,n+n+1);
	build(mid,r,n+n+2);
	st[n].l = l; st[n].r = r;
	st[n].sum = st[n+n+1].sum + st[n+n+2].sum;
	st[n].arr.resize(st[n+n+1].arr.size() + st[n+n+2].arr.size());
	merge(st[n+n+1].arr.begin(),st[n+n+1].arr.end(),
		  st[n+n+2].arr.begin(),st[n+n+2].arr.end(),
	st[n].arr.begin());
}

int64_t query(int64_t l,int64_t r,int64_t n){
	if(st[n].r <= l || st[n].l >= r) return 0;
	if(st[n].l >= l && st[n].r <= r){
		int64_t p = (int64_t)(st[n].arr.end() - upper_bound(st[n].arr.begin(),st[n].arr.end(),N-k));
		return st[n].sum + (int64_t)st[n].arr.size() * k - p*N;;
	}
	
	return query(l,r,n+n+1) + query(l,r,n+n+2);
}

int main()
{
	IOS;
	int64_t n,m,cmd,l,r;
	cin >> n >> m;
	for(int64_t i=0;i<n;i++) cin >> in[i];
	build(0,n,0);
	while(m--){
		cin >> cmd;
		if(cmd == 1){
			cin >> l;
			k += l;
			if(k > N){
				k %= N;
				if(k == 0) k = N;
			}
		}
		else{
			cin >> l >> r;
			cout << query(l-1,r,0) << '\n';
		}
	}
  return 0;
}


