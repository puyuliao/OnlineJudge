#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

int myrand(){
	static int64_t mod = 2147483647;
	static int64_t seed = time(NULL)%mod;
	if(seed&7 > 5) return seed = rand();
	return (int)(seed = (seed*seed+1)%mod);
}

void radix_sort(int* l,int *r,bool sign = false){
	if(l == r) return;
	int* ind;
	static vector<int> *v = NULL;
	if (v == NULL) {
		v = new vector<int> [0x10000];
	};
	for(int* i=l;i!=r;i++){v[0xffff&*i].push_back(*i); }
	ind = l;
	for(int i=0;ind != r;i++){for(int j : v[i]) *ind++ = j; v[i].clear(); }
	for(int* i=l;i!=r;i++){v[(0xffff0000ul&*i) >> 16].push_back(*i); }
	ind = l;
	if(sign){
		for(int i=0x8000;i<=0xffff;i++){for(int j : v[i]) *ind++ = j; v[i].clear();}
		for(int i=0;ind != r;i++){for(int j : v[i]) *ind++ = j; v[i].clear();}	
		return;
	}
	for(int i=0;ind != r;i++){for(int j : v[i]) *ind++ = j; v[i].clear();}
}

const int sz = 1000000;
int *a = new int[sz];
int main()
{
	IOS;
	int n;
	while(cin >> n){
		for(int i=0;i<n;i++) cin >> a[i];
		radix_sort(a,a+n);
		for(int i=0;i<n;i++) cout << a[i] << ' ';
	}
	delete a;
   return 0;
}


