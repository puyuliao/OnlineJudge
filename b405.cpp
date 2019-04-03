#include<iostream>
#include<algorithm>
#include<time.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 7400000
#define Q 60001
//#define DEBUG
struct treap;
inline treap *create(treap* t);

int top = 0;
struct treap{
	treap *l,*r;
	int pri,sz,rev,add;
	int64_t data,mn,mx,sum;
	treap(){}
	treap(int64_t d){
		pri = rand();
		data = mn = mx = sum = d;
		rev = 0,sz = 1;
		l = r = NULL;
	}
	void push(){
		if(add){
			if(l) {
				l = create(l);
				l->data += add,l->add += add,l->mn += add,l->mx += add;
				l->sum += (int64_t)add*l->sz;
			}
			if(r) {
				r = create(r);
				r->data += add,r->add += add,r->mn += add,r->mx += add;
				r->sum += (int64_t)add*r->sz;
			}
			add = 0;
		}
		if(rev){
			l = create(l);
			r = create(r);
			swap(l,r);
			if(l) l->rev ^= 1;
			if(r) r->rev ^= 1;
			rev = 0;
		}
	}
	void pull(){
		sz = 1; mn = mx = sum = data;
		if(l){
			sz += l->sz;
			mx = max(mx,l->mx);
			mn = min(mn,l->mn);
			sum += l->sum;
		}
		if(r){
			sz += r->sz;
			mx = max(mx,r->mx);
			mn = min(mn,r->mn);
			sum += r->sum;
		}
	}
}*root[Q],node[N];

inline treap *make(int64_t d){
	node[top] = treap(d);
	return &node[top++];
}

inline treap *create(treap* t){
	if(!t) return NULL;
	node[top] = *t;
	return &node[top++];
}

inline int size(treap* t){
	return (t?t->sz:0);
}

treap* merge(treap* a,treap* b,bool chg = true){
	if(!a) return chg?create(b):b;
	if(!b) return chg?create(a):a;
	treap* t;
	if(a->pri < b->pri){
		a->push();
		if(chg) t = create(a);
		else t = a;
		t->r = merge(a->r,b,chg);
	}
	else{
		b->push();
		if(chg) t = create(b);
		else t = b;
		t->l = merge(a,b->l,chg);
	}
	t->pull();
	return t;
}

void split(treap *t,int k,treap *&a,treap *&b,bool chg = true){
	if(!t) return a = b = NULL, void();
	
	t->push();
	if(size(t->l) < k){
		if(chg) a = create(t);
		else a = t;
		split(t->r, k - size(t->l) - 1, a->r, b,chg);
		a->pull();
		return;
	}
	if(chg) b = create(t);
	else b = t;
	split(t->l, k, a, b->l,chg);
	b->pull();
}

void print(treap* t){
	if(!t) return;
	t->push();
	print(t->l);
	cout << t->data << ' ';
	print(t->r);
}

int main()
{
	srand(time(0));
	#ifndef DEBUG
	IOS;
	#endif
	for(int i=0;i<Q;i++) root[i] = NULL;
	treap t,*pt,*tl,*tr;
	int n,q;
	int64_t x,y,v,cmd,ans = 0;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> v;
		root[0] = merge(root[0],make(v),false);
	}
	cin >> q;
	for(int ver=1;ver<=q;ver++){
		if(top > 7200000) return cout << "MEMEXCEED", 0;
		cin >> cmd; cmd ^= ans; if(cmd > 7 ) return cout << "WA", 0;
		if(cmd == 0){
			cin >> x; x ^= ans; 
			root[ver] = create(root[x]);
		}
		else if(cmd == 1){
			cin >> x >> v; x ^= ans; v ^= ans; 
			t = treap(v); pt = &t;
			split(root[ver-1],x,tl,tr);
			root[ver] = merge(tl,pt);
			root[ver] = merge(root[ver],tr);
		}
		else if(cmd == 2){
			cin >> x; x ^= ans;
			split(root[ver-1],x-1,tl,pt);
			split(pt,1,pt,tr);
			root[ver] = merge(tl,tr);
		}
		else if(cmd == 3){
			cin >> x >> y; x ^= ans; y ^= ans;
			split(root[ver-1],x-1,tl,pt);
			split(pt,y-x+1,pt,tr);
			pt->rev ^= 1;
			root[ver] = merge(tl,pt);
			root[ver] = merge(root[ver],tr);
		}
		else if(cmd == 4){
			cin >> x >> y >> v; x ^= ans; y ^= ans; v ^= ans;
			split(root[ver-1],x-1,tl,pt);
			split(pt,y-x+1,pt,tr);
			pt->data += v;
			pt->add += v;
			pt->sum += (int64_t)v*pt->sz;
			pt->mn += v;
			pt->mx += v;
			root[ver] = merge(tl,pt);
			root[ver] = merge(root[ver],tr);
		}
		else if(cmd == 5){
			root[ver] = create(root[ver-1]);
			cin >> x >> y; x ^= ans; y ^= ans; 
			split(root[ver],x-1,tl,pt,false);
			split(pt,y-x+1,pt,tr,false);
			ans = pt->mx;
			root[ver] = merge(tl,pt,false);
			root[ver] = merge(root[ver],tr,false);
			cout << ans << '\n';
		}
		else if(cmd == 6){
			root[ver] = create(root[ver-1]);
			cin >> x >> y; x ^= ans; y ^= ans; 
			split(root[ver],x-1,tl,pt,false);
			split(pt,y-x+1,pt,tr,false);
			ans = pt->mn;
			root[ver] = merge(tl,pt,false);
			root[ver] = merge(root[ver],tr,false);
			cout << ans << '\n';
		}
		else{
			root[ver] = create(root[ver-1]);
			cin >> x >> y; x ^= ans; y ^= ans; 
			split(root[ver],x-1,tl,pt,false);
			split(pt,y-x+1,pt,tr,false);
			ans = pt->sum;
			root[ver] = merge(tl,pt,false);
			root[ver] = merge(root[ver],tr,false);
			cout << ans << '\n';
		}
		#ifdef DEBUG
			cout << "ver " << ver << ": ";
			print(root[ver]); cout << '\n';
			pt = root[ver];
			cout << "-> " << pt->mx << ' ' << pt->mn << ' ' << pt->sum << '\n';
		#endif
	}
	//cout << "SZ : " << top << '\n';
  return 0;
}
