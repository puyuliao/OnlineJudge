#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}

unsigned int st[16777216];  //1 << (int)ceil(log2(N+2)) + 1;
int M,N;

unsigned int seed = 0;
unsigned int p_random() {return seed = (seed*9301+49297);}


unsigned int query(int l,int r){ // [l,r]
	if(l > r) swap(l,r);
	unsigned int ans = 0;
	for(l = l+M-1, r = r+M+1; l^r^1; l>>=1,r>>=1){
		if(~l&1) ans = max(ans,st[l^1]);
		if( r&1) ans = max(ans,st[r^1]);
	}
	return ans;
}

void build(){
	for (int i = M+1; i <= M+N; i++)
		st[i] = p_random();
	for(int i=M;i>0;i--){
		st[i] = max(st[i+i],st[i+i+1]);
	}
}


int main() {
	int m, S, x, y;
	unsigned int hash = 0;
	scanf("%d %d %d", &N, &m, &S);
	seed = S;
	M = 1 << (int)ceil(log2(N+2));
	build();
	for (int i = 0; i < m; i++) {
		x = p_random()%N+1, y = p_random()%N+1;
		if (x > y)	swap(x, y);
		hash ^= query(x,y);
	}
	printf("%lu\n", hash);
	return 0;
}
