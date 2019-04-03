#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 500008

struct treap{
	static treap mem[N],*pmem; 
	treap *l,*r;
	int key,sz,pri;
	int64_t sum,chg,data;
	treap(){}
	treap(int k,int64_t d):key(k),data(d),sum(d)
	,pri(rand()),sz(1),chg(0),l(NULL),r(NULL){}
	inline void push(){
		if(chg){
			if(l) l->chg+=chg,l->data+=chg,l->sum+=l->chg*l->sz;
			if(r) r->chg+=chg,r->data+=chg,r->sum+=r->chg*r->sz;
			chg=0;
		}
	}
	inline void pull(){
		sz = 1; sum = data;
		if(l) sz+=l->sz,sum+=l->sum;
		if(r) sz+=r->sz,sum+=r->sum;
	}
}treap::mem[N],*treap::pmem = treap::mem;

treap* merge(treap *a,treap *b){
	if(!a) return b;
	if(!b) return a;
	if(a->pri > b->pri){
		a->push();
		a->r = merge(a->r,b);
		a->pull();
		return a;
	}
	b->push();
	b->l = merge(a,b->l);
	b->pull();
	return b;
}

int size(treap *m){
	if(m) return m->sz;
	return 0; 
}

int64_t sum(treap *m){
	if(m) return m->sum;
	return 0;
}

void split(treap *t,int k,treap *&a,treap *&b){
	if(!t){
		a = b = NULL;
		return;
	} 
	if(size(t->l) < k){
		a=t;
		a->push();
		split(t->r,k-size(t->l)-1,a->r,b);
		a->pull();
		return;
	}
	b=t;
	b->push();
	split(t->l,k,a,b->l);
	b->pull();
	return;
}

treap* make(int k,int d){
	int64_t tmp = d;
	return new(treap::pmem++) treap(k,tmp); 
}

int main()
{
	srand(time(NULL));
	treap *t = NULL,*tl,*tr;
	//IOS;
	int n,q,in,x,y,k;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> in;
		t = merge(t,make(i,in));
	}
	cin >> q;
	while(q--){
		cin >> in;
		if(in == 1){
			cin >> x >> y >> k;
			split(t,x-1,tl,t);
			split(t,y-x+1,t,tr);
			t->data += k;
			t->chg += k;
			t->sum += t->sz*k;
			t = merge(tl,t);
			t = merge(t,tr);
		}
		else{
			cin >> x >> y;
			split(t,x-1,tl,t);
			split(t,y-x+1,t,tr);
			cout << t->sum << '\n';
			t = merge(tl,t);
			t = merge(t,tr);
		}
	}
	treap::pmem = treap::mem;
  return 0;
}

