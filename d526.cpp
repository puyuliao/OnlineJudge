#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define MX 1000

struct bst{
	static bst mem[MX],*pmem;
	int data;
	bst *l,*r;
	bst(){}
	bst(int _d):data(_d),l(NULL),r(NULL){}
}bst::mem[MX],*bst::pmem = bst::mem;

bst* create(int t){
	return new(bst::pmem++) bst(t);
}

void insert(bst *&b,int t){
	if(!b) {
		b = create(t);
		return;
	}
	if(b->data > t) insert(b->l,t);
	else insert(b->r,t);
}

void print(bst* b){
	if(!b) return;
	cout << b->data << ' ';
	print(b->l);
	print(b->r);
}

int main()
{
	bst *b = NULL;
	IOS;
	int n,t; 
	while(cin >> n){
		bst::pmem = bst::mem;
		b = NULL;
		while(n--){
			cin >> t;
			insert(b,t);
		}
		print(b);
		cout << '\n';
	}
   return 0;
}
