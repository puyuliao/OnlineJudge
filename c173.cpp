#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 120010

char ms[N+1];
int sa[N];
int rsa[N];
int lcpa[N+1];
int L;

struct CMP{
	int n,l,*rank;
	bool operator()(const int &i,const int &j){
		if(rank[i] != rank[j]) return rank[i] < rank[j];
		
		int a = (i+n>=l?-1:rank[i+n]);
		int b = (j+n>=l?-1:rank[j+n]);
		return a < b; 
	}
};

void Suffix(){
	static int rk[2][N];
	for(int i=0;i<L;i++){
		sa[i] = i;
		rk[0][i] = ms[i];
	}
	
	for(int i = 1;i <= L;i<<=1){
		CMP cmp{i,L,rk[0]};
		sort(sa,sa+L,cmp);
		
		int r = 0;
		rk[1][sa[0]] = 0;
		for(int j=1;j<L;j++){
			if(cmp(sa[j-1],sa[j])) r++;
			rk[1][sa[j]] = r;
		}
		
		if(r == L-1) break;
		swap(rk[0],rk[1]);
	}
}

void Lcp(){
	for(int i=0;i<L;i++) rsa[sa[i]] = i;
	
	for(int i=0, lcp=0;i<L;i++){
		if(rsa[i] == 0){
			lcpa[0] = 0;
			continue;
		}
		
		int j = sa[rsa[i] - 1];
		if(lcp > 0) lcp--;
		while(ms[i+lcp] == ms[j+lcp]) lcp++;
		lcpa[rsa[i]] = lcp;
	}
}

int main()
{
	IOS;
	int n;
	while(cin >> ms){
		n = strlen(ms);
		ms[n] = '$'; 
		cin >> ms + n + 1;
		L = n + strlen(ms+n);
		Suffix();
		for(int i=0;i<L;i++) cout << ms+sa[i] << '\n';
		Lcp();
		int mx = 0;
		for(int i=0;i<L;i++){
			mx = max(mx,lcpa[i]);
		}
		cout << mx << '\n';
	}
	
   return 0;
}


