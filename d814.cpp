#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define MAXN 130020

struct treap{
	static treap mem[MAXN], *pmem;
	treap *l,*r;
	int data,pri,sz,rchg;
	treap(){}
	treap(int d):data(d),sz(1),pri(rand()),rchg(0),l(NULL),r(NULL){}
	void push(){
		if(rchg){
			if(l) l->rchg^=1;
			if(r) r->rchg^=1;
			swap(l,r);
			rchg = 0;
		}
	}
	void pull(){
		sz = 1;
		if(l) sz+=l->sz;
		if(r) sz+=r->sz;
	}
}treap::mem[MAXN],*treap::pmem = treap::mem;

int size(treap* a){
	return a?a->sz:0;
}

treap* merge(treap *a,treap *b){
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

void split(treap* t,int k,treap*&a,treap*&b){
	if(!t){
		a = b = NULL;
		return;
	}
	t->push();
	if(size(t->l) < k){
		a = t;
		//a->push();
		split(t->r,k-size(t->l)-1,a->r,b);
		a->pull();
		return;
	}
	b = t;
	//b->push();
	split(t->l,k,a,b->l);
	b->pull();
	return;
}

treap* make(int data){
	return new(treap::pmem++) treap(data);
}

void print(treap *t){
	if(!t) return;
	t->push();
	print(t->l);
	//t->pull();
	cout << t->data <<' ';
	print(t->r);
} 

int main()
{
	IOS;
	srand(time(NULL));
	treap *t = NULL,*tl,*tr;
	int n,m,x,y;
	while(cin >> n >> m){
		t = NULL; treap::pmem = treap::mem;
		for(int i=1;i<=n;i++)
			t = merge(t,make(i));
		while(m--){
			cin >> x >> y;
			split(t,x-1,tl,t);
			split(t,y-x+1,t,tr);
			if(t) t->rchg^=1;
			else 
				cout << "NO\n";
			t = merge(tl,t);
			t = merge(t,tr);
		}
		print(t);
		cout << '\n';
	}
  return 0;
}
