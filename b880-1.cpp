#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000
#define INF 0x7fffffff
//const int sz = 1 << (int)ceil(log2(N)) + 1;

struct node{
	int data,ydata,l,r,chg;
};

node st[2097152];
int inx[N];
int iny[N];

void build(int l,int r,int ind){
	if(l == r-1){
		st[ind].l = l; 
		st[ind].r = r;
		st[ind].data  = inx[l] + iny[l];
		st[ind].ydata = iny[l];
		st[ind].chg = INF;
		return;
	}
	st[ind].l = l; 
	st[ind].r = r;
	int mid = l+r >> 1;
	build(l,mid,ind+ind+1);
	build(mid,r,ind+ind+2);
	
	st[ind].chg = INF;
	st[ind].data  = min(st[ind+ind+1].data , st[ind+ind+2].data);
	st[ind].ydata = min(st[ind+ind+1].ydata,st[ind+ind+2].ydata);
}

void push(int ind){
	if(st[ind].chg!=INF){
		//cout << "push " << ind << "to " << ind+ind+1 << " " << ind+ind+2;
		st[ind].data = min(st[ind].data,st[ind].ydata + st[ind].chg);
		if(st[ind].l != st[ind].r-1){
			st[ind+ind+1].chg = min(st[ind].chg,st[ind+ind+1].chg);
			st[ind+ind+2].chg = min(st[ind].chg,st[ind+ind+2].chg); 
		}	
		st[ind].chg = INF;
	}
}

void modify(int l,int r,int d,int ind){
	push(ind); // must push first line 50 ,51 must not change;
	if(st[ind].r <= l || st[ind].l >= r) return;
	if(st[ind].l >= l && st[ind].r <= r){
		st[ind].chg = min(st[ind].chg,d);
		st[ind].data = min(st[ind].data,st[ind].ydata + st[ind].chg);
		return;
	}
	
	modify(l,r,d,ind+ind+1);
	modify(l,r,d,ind+ind+2);
	st[ind].data  = min(st[ind+ind+1].data , st[ind+ind+2].data);
}

int query(int l, int r ,int ind){
	push(ind); //same as modify;
	if(st[ind].r <= l || st[ind].l >= r) return INF;
	if(st[ind].l >= l && st[ind].r <= r) return st[ind].data;
	
	return min(query(l,r,ind+ind+1),query(l,r,ind+ind+2));
}

int main()
{
	IOS;
	int n,l,r,d,q;
	char cmd;
	cin >> n;
	for(int i=0;i<n;i++) cin >> inx[i]; 
	for(int i=0;i<n;i++) cin >> iny[i];
	build(0,n,0);
	cin >> q;
	while(q--){
		cin >> cmd;
		if(cmd == 'c'){
			cin >> l >> r >> d;
			modify(l-1,r,d,0);
		}
		else{
			cin >> l >> r;
			cout << query(l-1,r,0) << '\n';
		}
	}
   return 0;
}


