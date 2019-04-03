#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 200000

int top;
struct treap{
	treap *l,*r;
	int pri,sz,key,chg;
	treap(){}
	treap(int k):l(NULL),r(NULL),pri(rand()),sz(1),key(k),chg(0){}
	inline void pull(){
		sz = 1;
		if(l) sz+=l->sz;
		if(r) sz+=r->sz;
	}
	inline void push(){
		if(chg){
			if(l) l->key+=chg,l->chg+=chg;
			if(r) r->key+=chg,r->chg+=chg;
			chg = 0;	
		}
	}
}node[N];

inline treap* make(int k){
	node[top] = treap(k);
	return &node[top++];
}

inline int size(treap *t){
	return t?t->sz:0;
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

void split(treap *t, int k, treap *&a, treap *&b){
	if(!t) return a=b=NULL,void();
	t->push();
	if(t->key < k){
		a = t;
		split(t->r,k,a->r,b);
		a->pull();
		return;
	}
	b = t;
	split(t->l,k,a,b->l);
	b->pull();
}

int kth(treap *t,int k){
	t->push();
	if(k == size(t->l) + 1) return t->key;
	if(size(t->l) < k) return kth(t->r,k-size(t->l)-1);
	else return kth(t->l,k);
}

void print(treap *t){
	if(!t) return;
	t->push();
	print(t->l);
	cout << t->key << ' ';
	print(t->r);
}

int main()
{
	IOS;
	treap *t = NULL,*tl,*tr;
	int n,mn,x,kill=0;
	char cmd;
	cin >> n >> mn;
	while(n--){
		cin >> cmd >> x;
		if(cmd == 'I'){
			if(x < mn) {
				//kill++;
				continue;
			}
			split(t,x,tl,tr);
			t = merge(tl,make(x));
			t = merge(t,tr); 
		}
		else if(cmd == 'S'){
			if(!t) continue;
			t->key -= x;
			t->chg -= x;
			split(t,mn,tl,t);
			kill += size(tl);
		}
		else if(cmd == 'A'){
			if(!t) continue;
			t->key += x;
			t->chg += x;
		}
		else{
			if(x > size(t)) cout << "-1\n";
			else cout << kth(t,size(t)-x+1) << '\n';
		}
		//cout << "t: ";print(t); cout << '\n';
	}
	cout << kill << '\n';
   return 0;
}


