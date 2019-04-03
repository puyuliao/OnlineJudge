#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;
#define MAXN 100001

struct ques{
	int cmd;
	int l,r;
};

struct treap{
	static treap mem[MAXN], *pmem;
	treap *l, *r;
	int sz,data,pri,rchg;
	treap(int d):sz(1),data(d),rchg(0),pri(rand()),l(NULL),r(NULL){}
	treap(){}
	void push(){
		if(rchg){
			data = rchg - data;
			
		}
	}
	void pull(){
		sz = 1;
		if(l) sz+=l->sz;
		if(r) sz+=r->sz;
	}
}treap::mem[MAXN], *treap::pmem = treap::mem;

ques in[MAXN];

int main()
{
	srand(time(NULL));
	//IOS;
	int n,q,tmp;
	while(cin >> n >> q){
		for(int i=0;i<q;i++){
			cin >> in[i].cmd;
			if(in[i].cmd == 0) cin >> in[i].l >> in[i].r;
			else {
				cin >> in[i].l;
			}
		}
		for(int i=0,j = 0;i<q;i++,j++){
			tmp = in[i].l + in[i].r;
			if(in[i].cmd == 0){
				
			}
			else {
					
			}
		}
	}
	
   return 0;
}

/*
//map<int,int> maap;
//map<int,int>::iterator it;
	for(it = maap.lower_bound(in[i].l); it->first <= in[i].r && it != maap.end(); it++){
					it->second = tmp - it->second;
				}
				it = maap.find(in[i].l);
				cout << it->second << '\n';
				maap.erase(it);
*/

