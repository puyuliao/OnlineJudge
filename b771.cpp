#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 600000

int top = 0;
struct treap{
	treap *l,*r;
	int pri,sz;
	char data;
	treap(){}
	treap(char d):l(NULL),r(NULL),pri(rand()),sz(1),data(d){}
	inline void pull(){
		sz = 1;
		if(l) sz += l->sz;
		if(r) sz += r->sz;
	}
}node[N];

inline treap* make(char d){
	if(top > N-6) cout << "MEMEXCEED",exit(0);
	node[top] = treap(d);
	return &node[top++];
}

inline int size(treap* t){
	return t?t->sz:0;
}

treap* merge(treap *a,treap *b){
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

void split(treap *t,int k,treap*&a,treap*&b){
	if(!t) return a=b=NULL,void();
	if(size(t->l) < k){
		a = t;
		split(t->r,k-size(t->l)-1,a->r,b);
		a->pull();
		return;
	}
	b = t;
	split(t->l,k,a,b->l);
	b->pull();
}

void print(treap *t){
	if(!t) return;
	print(t->l);
	cout << t->data << ' ';
	print(t->r);
}

int main()
{
	treap *t = NULL,*tl,*tr;
	IOS;
	int x;
	char cmd1[10],cmd2[10],c;
	while(cin >> cmd1 >> cmd2){
		if(cmd1[0] == 'i'){
			cin >> c;
			if(cmd2[0] == 'l') t = merge(make(c),t);
			else if(cmd2[0] == 'r') t = merge(t,make(c));
			else{
				x = atoi(cmd2);
				split(t,x-1,tl,tr);
				t = merge(tl,make(c));
				t = merge(t,tr);
			}
		}
		else{
			if(cmd2[0] == 'l') split(t,1,tl,t);
			else if(cmd2[0] == 'r') split(t,size(t)-1,t,tr);
			else{
				x = atoi(cmd2);
				split(t,x-1,tl,t);
				split(t,1,t,tr);
				t = merge(tl,tr);
			}
		}
		//print(t); cout << '\n';
	}
	for(char i : ans) cout << i << ' '; cout << '$' << '\n';
   return 0;
}


