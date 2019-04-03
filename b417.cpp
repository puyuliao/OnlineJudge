#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 100000
#define M 1000000

int sq;

struct query{
	int l,r,ind; // [l,r];
	bool operator <(const query &b){
		return l/sq < b.l/sq || l/sq == b.l/sq && r < b.r;
	} 
}qr[M];

int in[N+1];
int ans1[M],ans2[M];
int ap[N+1]; //num appear cnt;
int S[N+1];  //same appear cnt kind;
int mx = -1,nl,nr;

inline void add(int k){
	S[ap[in[k]]]--;
	ap[in[k]]++;
	S[ap[in[k]]]++;
	if(mx < ap[in[k]]) mx = ap[in[k]];
}

inline void sub(int k){
	S[ap[in[k]]]--;
	if(S[ap[in[k]]] == 0 && ap[in[k]] == mx) mx--;
	ap[in[k]]--;
	S[ap[in[k]]]++;
}

int main()
{
	IOS;
	int n, q;
	cin >> n >> q;
	sq = sqrt(q) + 1;
	for(int i=1;i<=n;i++) cin >> in[i];
	for(int i=0;i<q;i++) {
		cin >> qr[i].l >> qr[i].r;
		qr[i].ind = i;
	}
	sort(qr,qr+q);
	S[0] = n;
	nl = 1,nr = 0,mx = 1;
	for(int i=0;i<q;i++){
		while(nl < qr[i].l) sub(nl++);
		while(nl > qr[i].l) add(--nl);
		while(nr < qr[i].r) add(++nr);
		while(nr > qr[i].r) sub(nr--);
		ans1[qr[i].ind] = mx,ans2[qr[i].ind] = S[mx];
	}
	for(int i=0;i<q;i++) cout << ans1[i] << ' ' << ans2[i] << '\n';
  return 0;
}
