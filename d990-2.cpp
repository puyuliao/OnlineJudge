#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 100002

char M[N+N],in[N];
int n;
int SA[N],RK[2][N+N],RSA[N],LCP[17][N],C[N];

inline bool cmp(int *f, int x, int y, int w){
    return f[x] == f[y] && f[x + w] == f[y + w];
}

void build(){
	n = strlen(M);
	int m = 'z'+1;
	int *rk = RK[0], *nrk = RK[1];
	for(int i=0;i<m;i++) C[i] = 0;
	for(int i=0;i<n;i++) C[rk[i] = M[i]]++;
	for(int i=1;i<m;i++) C[i] += C[i-1];
	for(int i=n-1;i>=0;i--) SA[--C[rk[i]]] = i;
	for(int k=1;k<=n;k<<=1){
		int p = 0;
		for(int i=n-k;i<n;i++) nrk[p++] = i;
		for(int i=0;i<n;i++) if(SA[i] >= k) nrk[p++] = SA[i]-k;
		for(int i=0;i<m;i++) C[i] = 0;
		for(int i=0;i<n;i++) C[rk[nrk[i]]]++;
		for(int i=1;i<m;i++) C[i] += C[i-1];
		for(int i=n-1;i>=0;i--) SA[--C[rk[nrk[i]]]] = nrk[i];
		swap(rk,nrk);
		p = 1; rk[SA[0]] = 0;
		for(int i=1;i<n;i++) 
			rk[SA[i]] = (nrk[SA[i-1]] == nrk[SA[i]] && 
						SA[i-1] + k < n 			&&
					 	nrk[SA[i-1] + k] == nrk[SA[i] + k]) ? p-1 : p++;
		if(p >= n) break;
		m = p;
	}
	
	for(int i=0;i<n;i++) rk[SA[i]] = i;
	for(int i=0,lcp=0;i<n;i++){
		if(rk[i] == 0) continue;
		int j = SA[rk[i]-1]; if(lcp) lcp--;
		while(M[i+lcp] == M[j+lcp]) lcp++;
		LCP[0][rk[i]] = lcp;
	}
	
	int d;
	for(int i=1;(d = 1 << i) <= n;i++)
		for(int j=0;j + d <= n;j++){
			LCP[i][j] = min(LCP[i-1][j],LCP[i-1][j + (d>>1)]);
		}
}

inline int RMQ(int l,int r){
	int k = __lg(r-l+1);
	return min(LCP[k][l],LCP[k][r - (1<<k) + 1]);
}

int scount(){
	int l = 0, r = n-1,rin = 0;
	while(true){
		while(in[rin] && in[rin] == M[SA[r] + rin]) rin++;
		if(in[rin] > M[SA[r]+rin]) return 0;
		if(l == r) break;
		int m = l+r>>1, d = RMQ(m+1,r);
		if(rin > d || rin == d && strcmp(in+rin,M + SA[m] + rin) > 0) l = m+1;
		else r = m;
	}
	if(in[rin]) return 0;
	int s = l; r = n-1;
	while(l!=r){
		int m = l+r+1>>1;
		if(RMQ(l+1,m) >= rin) l = m;
		else r = m-1;
	}
	return l-s+1;
}

int main()
{
	//IOS;
	int q;
	cin >> M >> q;
	build();
	for(int i=0;i<n;i++) cout << M+SA[i] << '\n';
	while(q--){
		cin >> in;
		cout << scount() << '\n';
	}

   return 0;
}
