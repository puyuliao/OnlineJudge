#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
int N, a[30010], top = 0;
struct treap{
	treap *l,*r;
	int data,sz,pri;
	treap(int d):l(NULL),r(NULL),data(d),sz(1),pri(0){}
	treap(){}
	void pull(){
		sz = 1;
		if(l) sz += l->sz;
		if(r) sz += r->sz;
	}
}mem[30010];
treap* make(int d){
	mem[top] = treap(d);
	return &mem[top++];
}
int size(treap *t){
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
void split(treap*t, int k,treap *&a,treap *&b){
	if(!t) return a = b = NULL,void();
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
void Init() {
    static unsigned int seed; 
    if(!N) seed = 5;//time(0) / 60;
	srand(seed);
}
struct cmp {
    int x;
    cmp(int x): x(x) {
    }
    inline bool operator()(int y) {
        return y < x;
    }
};
int ll,G;
void quicksort(int l, int r) {
    if (l + 1 >= r) return;
    cout << l << ' ' << r << '\n';
    for(int i=0;i<N;i++) cout << a[i] << ' '; cout << '\n';
    swap(a[l], a[ll = l + rand() % (r - l)]);
    if(a[l] != G) cout << "GG\n" << a[l] << ' ' << G << '\n';
    G++;
    int pivot = stable_partition(a + l + 1, a + r, cmp(a[l])) - a;
    swap(a[l], a[pivot - 1]);
    for(int i=0;i<N;i++) cout << a[i] << ' '; cout << '\n';
    quicksort(l, pivot), quicksort(pivot, r);
}
int x;
void build(treap *t){
	if(!t) return;
	build(t->l);
	a[x++] = t->data; 
	build(t->r);
}
void print(treap *t){
	if(!t) return;
	print(t->l);
	cout << t->data << ' '; 
	print(t->r);
}
int main()
{
	IOS;
	treap *t = NULL,*tl,*tr,*tt;
	Init();
    cin >> N; 
    vector<int> v;
    for (int i = 0; i < N; ++i) t = merge(t,make(i));
    for (int i = 0; i < N; ++i) v.push_back(rand() % (N-i));
    for(int i : v) cout << i << ' '; cout << '\n';
	for (int i = N-1; i >= 0; --i) {
		int r = v[i];
		split(t,i+1,t,tr);
		//cout << "D1: ";print(t); cout << '\n';
		//cout << "D2: ";print(tr); cout << '\n';
		split(t,i,tl,t);
		//cout << "D3: ";print(tl); cout << '\n';
		//cout << "D4: ";print(t); cout << '\n';
		split(tr,r,tt,tr);
		//cout << "D5: ";print(tt); cout << '\n';
		//cout << "D6: ";print(tr); cout << '\n';
		t = merge(merge(merge(tl,tt),t),tr);
		//print(t); cout << '\n';
		//cout << "_____\n";
	}	
	build(t); 
	cout << N << '\n';
	for(int i=0;i<N;i++) cout << a[i] << ' '; cout << '\n';
	
	Init();
	int ttt = clock();
    quicksort(0, N);
	cout << clock() - ttt << '\n';
   return 0;
}


