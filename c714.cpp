#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 50006
#define int int64_t

const int INF = 1e6;

struct treap{
	treap *l,*r;
	int key,pri,sz,data,keytag,datatag;
	treap(int _k,int _d):key(_k),data(_d),sz(1),pri(rand()),keytag(0),datatag(0),l(NULL),r(NULL){}
	treap(){}
	void push(){
		if(keytag){
			if(l) l->key += keytag, l->keytag += keytag;
			if(r) r->key += keytag, r->keytag += keytag;	
			keytag = 0;	
		}
		if(datatag){
			if(l) l->data += datatag, l->datatag += datatag;
			if(r) r->data += datatag, r->datatag += datatag;	
			datatag = 0;	
		}
	}
	void pull(){
		sz = 1;
		if(l) sz += l->sz;
		if(r) sz += r->sz;
	}
}mem[N];

int memcnt = 0;
treap *make(int k,int d){
	mem[memcnt] = treap(k,d);
	return &mem[memcnt++];
}

int size(treap *t){
	if(t) {
		t->push();
		return t->sz;
	}
	return 0;
}

treap *merge(treap *a,treap *b){
	if(!a) return b;
	if(!b) return a;
	a->push();
	b->push();
	if(a->pri < b->pri){
		a->r = merge(a->r,b);
		a->pull();
		return a;
	}
	b->l = merge(a,b->l);
	b->pull();
	return b;
}

void splitbykey(treap *t,int k,treap*&a,treap*&b){
	if(!t) return a=b=NULL,void();
	t->push();
	if(t->key <= k){
		a = t;
		splitbykey(t->r,k,a->r,b);
		a->pull();
		return;
	}
	b = t;
	splitbykey(t->l,k,a,b->l);
	b->pull();
}

void splitbysize(treap *t,int k,treap*&a,treap*&b){
	if(!t) return a=b=NULL,void();
	t->push();
	if(size(t->l) < k){
		a = t;
		splitbysize(t->r,k - size(t->l) - 1,a->r,b);
		a->pull();
		return;
	}
	b = t;
	splitbysize(t->l,k,a,b->l);
	b->pull();
}


treap *t = NULL, *tl, *tr,*tt;

void addkey(int k){
	if(t) t->key += k, t->keytag += k; 
}

void adddata(int k){
	if(t) t->data += k, t->datatag += k; 
}

void insert(int k,int d){
	splitbykey(t,k-1,tl,tr);
	t = make(k,d);
	while(tr){
		splitbysize(tr,1,tt,tr);
		if(tt->data >= d) continue;
		else{
			if(tt->key != t->key) t = merge(tl,merge(t,merge(tt,tr)));
			else t = merge(tl,merge(tt,tr));
			return;
		}
	}
	t = merge(tl,t);
	return;
}

int getdp(int k){
	splitbykey(t,k-1,t,tr);
	splitbysize(t,size(t)-1,tl,t);
	if(t == NULL){
		cout << "GG";
	}
	int r = t->data;
	t = merge(tl,merge(t,tr));
	return r;
}

int l[N],r[N],v[N],w[N],in[N];
int cnt;

void dfs(int x){
	if(!x) return;
	dfs(l[x]); 
	in[++cnt] = x;
	dfs(r[x]);
}

void print(treap *tt){
	if(!tt) return;
	print(tt->l);
	cout << tt->key << ' ' << tt->keytag << ' ' << tt->data << ' ' << tt->datatag << ' ' << tt->sz << '\n';
	print(tt->r);
}

int32_t main()
{
	srand(time(NULL));
	IOS;
	int T,n;
	cin >> T;
	while(T--){
		t = NULL;
		memcnt = cnt = 0;
		cin >> n;
		for(int i=1;i<=n;i++) cin >> l[i] >> r[i];
		for(int i=1;i<=n;i++) cin >> v[i];
		for(int i=1;i<=n;i++) cin >> w[i];		
		dfs(1);
		insert(-INF,0);
		for(int j=1;j<=n;j++){
			int i = in[j];
			int rr = getdp(v[i]);
			addkey(1);
			adddata(w[i]);
			insert(v[i],rr);
			//print(t);
			//cout << j << ' ' << i << ' ' << getdp(INF) << '\n';
		}
		cout << getdp(INF) << '\n';
	}
   return 0;
}


