#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1000005
#define lowbit(x) ((x)&-(x))
template<typename T>
class bit{
public:
	void init(int _n){
		n = _n;
		bt.resize(n+1);
		fill(bt.begin(),bt.end(),(T)0);
	}
	void add(int x,T c){
		for(;x<=n;x+=lowbit(x)) bt[x]^=c;
	}
	T qur(int x){
		T r = (T)0;
		for(;x;x-=lowbit(x)) r ^= bt[x];
		return r;
	}
	vector<T> bt;
	int n;
};

int now[N];

int main()
{
	IOS;
	int n,q,c,l,r; cin >> n >> q;
	bit<int> b;
	b.init(n);
	for(int i=1;i<=n;i++) cin >> now[i],b.bt[i] = now[i] ^ b.bt[i-1];
	for(int i=n;i>=1;i--) b.bt[i] ^= b.bt[i-lowbit(i)];
	while(q--){
		cin >> c >> l >> r;
		if(c == 1) {
			b.add(l,now[l]^r);
			now[l] = r;
		}
		else cout << (b.qur(r) ^ b.qur(l-1)) << '\n';
	}
   return 0;
}


