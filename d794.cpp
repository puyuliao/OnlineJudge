#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 100000

struct treap{
	static treap mem[N],*pmem;
	treap *l,*r;
	int pri,sz;
	int64_t key;
	treap(){}
	treap(int64_t k):key(k),pri(rand()),l(NULL),r(NULL),sz(1){}
	void pull(){
		sz = 1;
		if(l) sz+=l->sz;
		if(r) sz+=r->sz;
	}
}treap::mem[N],*treap::pmem;

int size(treap *t){
	return t?t->sz:0;
}

treap* merge(treap* a,treap* b){
	if(!a) return b;
	if(!b) return a;
	if(a->pri < b->pri){
		a->r = merge(a->r,b);
		a->pull();
		return a;
	}
	b->l = merge(a,b->l);
	b->pull();
	return b;
}

void split(treap *t,int k,treap *&a,treap *&b){
	if(!t){
		a = b = NULL;
		return;
	}
	if(t->key <= k){
		a = t;
		split(t->r,k,a->r,b);
		a->pull();
		return;
	}
	b = t;
	split(t->l,k,a,b->l);
	b->pull();
	return;
}

treap* make(int64_t k){
	return new(treap::pmem++) treap(k);
}

int main()
{
	IOS;
	srand(time(NULL));
	treap *t = NULL,*tl,*tr;
	int n;
	int64_t k;
	while(cin >> n){
		treap::pmem = treap::mem;
		t = NULL;
		while(n--){
			cin >> k;
			split(t,k,tl,t);
			cout << size(t) + 1 << '\n';
			t = merge(make(k),t);
			t = merge(tl,t);
		}
	}

   return 0;
}


