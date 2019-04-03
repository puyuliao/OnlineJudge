#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 100002
#define MEM 6400000

int top = 0;
struct treap{
	treap *l,*r;
	int pri,key,sz;
	treap(){}
	treap(int k):pri(rand()),key(k),sz(1),l(NULL),r(NULL){}
	void pull(){
		sz = 1;
		if(l) sz+=l->sz;
		if(r) sz+=r->sz;
	}
}*root[N],node[MEM];

inline treap* create(treap *t){
	if(top > MEM - 6) cout << "MEMEXCEED", exit(0);
	node[top] = *t;
	return &node[top++];
}

inline int size(treap* t){
	return t?t->sz:0;
}

treap* merge(treap* a,treap *b,bool chg = true){
	if(!a) return chg?create(b):b;
	if(!b) return chg?create(a):a;
	treap* res;
	if(a->pri < b->pri){
		res = chg?create(a):a;
		res->r = merge(a->r,b,chg);
	}
	else{
		res = chg?create(b):b;
		res->l = merge(a,b->l,chg);
	}
	res->pull();
	return res;
}

void split(treap* t,int k,treap *&a,treap *&b,bool chg = true){
	if(!t) return a=b=NULL,void();
	if(t->key <= k){
		a = chg?create(t):t;
		split(t->r,k,a->r,b,chg);
		a->pull();
		return;
	}
	b = chg?create(t):t;
	split(t->l,k,a,b->l,chg);
	b->pull();
}

int main()
{
	IOS;
	treap *t,*tl,*tr,u; root[0] = NULL;
	int n,m,d,l,r,a,b,tmp;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> d; u = treap(d); t = &u;
		split(root[i-1],d,tl,tr);
		root[i] = merge(tl,t);
		root[i] = merge(root[i],tr);
	}
	while(m--){
		cin >> l >> r >> a >> b;
		split(root[r],a-1,tl,t,false);
		split(t,b,t,tr,false);
		tmp = size(t);
		root[r] = merge(tl,t,false);
		root[r] = merge(root[r],tr,false);
		split(root[l-1],a-1,tl,t,false);
		split(t,b,t,tr,false);
		cout << tmp - size(t) << '\n';
		root[l-1] = merge(tl,t,false);
		root[l-1] = merge(root[l-1],tr,false);
	}
   return 0;
}
