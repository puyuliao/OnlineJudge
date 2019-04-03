#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 40000
#define Q 5000
#define lowbit(x) (x&-x)

struct Fenwick{
	vector<int> v;
	int n;
	void init(int _n){
		n = _n;
		v.resize(n+1);
		fill(v.begin(),v.end(),0);
	}
	int add(int x,int c){
		for(;x<=n;x+=lowbit(x)) v[x] += c;
	}
	int qur(int x){
		int r = 0;
		for(;x;x-=lowbit(x)) r += v[x];
		return r;
	}
}bit;

struct query{
	int l,r,k,t;
	bool operator < (const query& b){
		t < b.t;
	}	
};
int in[N],ans[Q];
vector<int> de;

void GBS(int l,int r,vector<query> qur,vector<query> oper){
	if(l == r || !qur.size()){
		for(auto &i : qur) ans[i.t] = l;
		return;
	}
	int m = l+r>>1; 
	vector<query> lq,lo,rq,ro;
	for(auto &i : oper){
		if(i.r <= m) lo.push_back(i);
		else ro.push_back(i);
	}
	vector<query> ().swap(oper);
	int j = 0;
	fill(bit.v.begin(),bit.v.end(),0);
	for(auto &i : qur){
		while(j < lo.size() && lo[j].t < i.t){
			bit.add(lo[j].l,lo[j].k);
			j++;
		}
		int t = bit.qur(i.r) - bit.qur(i.l-1);
		if(i.k <= t) lq.push_back(i);
		else i.k -= t, rq.push_back(i);
	}
	vector<query> ().swap(qur);
	GBS(l,m,lq,lo);
	GBS(m+1,r,rq,ro);
}

int main()
{	
	vector<query> qur,oper;
	IOS;
	int n,q,l,r,k;
	char cmd;
	cin >> n >> q;
	bit.init(n);
	for(int i=1;i<=n;i++) cin >> in[i],de.push_back(in[i]),oper.push_back({i,in[i],1,0});
	for(int i=1;i<=q;i++){
		cin >> cmd;
		if(cmd == 'C'){
			cin >> l >> k;
			oper.push_back({l,in[l],-1,i});
			oper.push_back({l,k,1,i});			
			de.push_back(k);
		}
		else{
			cin >> l >> r >> k;
			qur.push_back({l,r,k,i});
		}
	}
	
	sort(de.begin(),de.end());
	de.resize(unique(de.begin(),de.end()) - de.begin());
	for(auto &i : oper) i.r = (int)(lower_bound(de.begin(),de.end(),i.r) - de.begin());
	
	memset(ans,-1,sizeof(ans));
	GBS(0,de.size()-1,qur,oper);
	for(int i=1;i<=q;i++) if(~ans[i]) cout << de[ans[i]] << '\n';
   return 0;
}


