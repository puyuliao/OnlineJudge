#include<bits/stdc++.h>
#include<stdint.h>
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
using namespace std;
#define MAXN 1000001
#define INF 0x3fffffff

struct treap{
	static treap mem[MAXN],*pmem;
	treap *l, *r;
	int x,y,key,pri,mcg,ans;
	treap(){}
	treap(int _x,int _y,int _k):x(_x),y(_y),key(_k),pri(rand()),mcg(INF),
	l(NULL),r(NULL),ans(_x+_y){}
	inline void push(){
		if(mcg != INF){
			if(l) l->x=min(l->x,mcg),l->mcg=min(l->mcg,mcg);
			if(r) r->x=min(r->x,mcg),r->mcg=min(r->mcg,mcg);
			mcg = INF;
		}
	}
	inline void pull(){
		ans = x+y;
		if(l) ans = min(ans,l->ans);
		if(r) ans = min(ans,r->ans);
	}
}treap::mem[MAXN], *treap::pmem = treap::mem;

treap* merge(treap* a,treap* b){
	if(!a) return b;
	if(!b) return a;
	if(a->pri < b->pri){
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

void split(treap *m,int k,treap *&a,treap *&b){
	if(!m) {
		a = b = NULL;
		return;
	}
	if(m->key <= k){
		a = m;
		a->push();
		split(m->r,k,a->r,b);
		a->pull();
		return;	
	}
	b = m;
	b->push();
	split(m->l,k,a,b->l);
	b->pull();
}

inline treap* make(int x,int y,int k){
	return new(treap::pmem++) treap(x,y,k);
}

int inx[MAXN];

int main()
{
	srand(time(NULL));
	//IOS;
	treap *t = NULL,*tl,*tr;
	int n,y,q,l,r,d;
	char cmd;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> inx[i];
	}
	for(int i=1;i<=n;i++){
		cin >> y;
		t = merge(t,make(inx[i],y,i));
	}
	cin >> q;
	while(q--){
		cin >> cmd;
		if(cmd == 'c'){
			cin >> l >> r >> d;
			split(t,l-1,tl,t);
			split(t,r,t,tr);
			t->x = min(t->x,d);
			t->ans = t->x + t->y;
			t->mcg = min(t->mcg,d);
			t = merge(tl,t);
			t = merge(t,tr);
		}
		else{
			cin >> l >> r;
			split(t,l-1,tl,t);
			split(t,r,t,tr);
			cout << t->ans << '\n';
			t = merge(tl,t);
			t = merge(t,tr);
		}
	}
  return 0;
}
Close
CPP

