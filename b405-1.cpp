#include<bits/stdc++.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 60001
#define Q 60001
#define DEBUG

int top;
struct treap{
	treap *l,*r;
	int pri,sz,rev;
	int64_t data,mn,mx,sum,add;
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
				l->data += add,l->add += add,l->mn += add,l->mx += add;
				l->sum += add*l->sz;
			}
			if(r) {
				r->data += add,r->add += add,r->mn += add,r->mx += add;
				r->sum += add*r->sz;
			}
			add = 0;
		}
		if(rev){
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
}node[N*10];

treap *make(int64_t d){
	node[top] = treap(d);
	return &node[top++];
}

treap *create(treap* t){
	return t;
}

inline int size(treap* t){
	return (t?t->sz:0);
}

treap* merge(treap* a,treap* b){
	if(!a) return create(b);
	if(!b) return create(a);
	treap* t;
	if(a->pri < b->pri){
		a->push();
		t = create(a);
		t->r = merge(a->r,b);
	}
	else{
		b->push();
		t = create(b);
		t->l = merge(a,b->l);
	}
	t->pull();
	return t;
}

void split(treap *t,int k,treap *&a,treap *&b){
	if(!t) return a = b = NULL, void();
	
	t->push();
	if(size(t->l) < k){
		a = create(t);
		split(t->r, k - size(t->l) - 1, a->r, b);
		a->pull();
		return;
	}
	b = create(t);
	split(t->l, k, a, b->l);
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
	treap *t = NULL,*tl,*tr;
	int n,q,cmd,x,y,v,ans = 0;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> v;
		t = merge(t,make(v));
	}
	cin >> q;
	for(int ver=1;ver<=q;ver++){
		if(top > N*9) return cout << "MEMEXCEED", 0;
		cin >> cmd; cmd ^= ans;
		if(cmd == 0){
			return 0;
		}
		else if(cmd == 1){
			cin >> x >> v; x ^= ans; v ^= ans;
			split(t,x,tl,tr);
			t = merge(tl,make(v));
			t = merge(t,tr);
		}
		else if(cmd == 2){
			cin >> x; x ^= ans;
			split(t,x-1,tl,t);
			split(t,1,t,tr);
			t = merge(tl,tr);
		}
		else if(cmd == 3){
			cin >> x >> y; x ^= ans; y ^= ans;
			split(t,x-1,tl,t);
			split(t,y-x+1,t,tr);
			t->rev ^= 1;
			t = merge(tl,t);
			t = merge(t,tr);
		}
		else if(cmd == 4){
			cin >> x >> y >> v; x ^= ans; y ^= ans; v ^= ans;
			split(t,x-1,tl,t);
			split(t,y-x+1,t,tr);
			t->data += v;
			t->add += v;
			t->sum += v*t->sz;
			t->mn += v;
			t->mx += v;
			t = merge(tl,t);
			t = merge(t,tr);
		}
		else if(cmd == 5){
			cin >> x >> y; x ^= ans; y ^= ans; 
			split(t,x-1,tl,t);
			split(t,y-x+1,t,tr);
			ans = t->mx;
			cout << ans << '\n';
			t = merge(tl,t);
			t = merge(t,tr);
		}
		else if(cmd == 6){
			cin >> x >> y; x ^= ans; y ^= ans; 
			split(t,x-1,tl,t);
			split(t,y-x+1,t,tr);
			ans = t->mn;
			cout << ans << '\n';
			t = merge(tl,t);
			t = merge(t,tr);
		}
		else{
			cin >> x >> y; x ^= ans; y ^= ans; 
			split(t,x-1,tl,t);
			split(t,y-x+1,t,tr);
			ans = t->sum;
			cout << ans << '\n';
			t = merge(tl,t);
			t = merge(t,tr);
		}
		#ifdef DEBUG
			cout << "ver " << ver << ": ";
			print(t); cout << '\n';
			
			cout << "-> " << t->mx << ' ' << t->mn << ' ' << t->sum << '\n';
		#endif
	}
  return 0;
}
