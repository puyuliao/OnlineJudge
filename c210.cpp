#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;

int ans[1000001];
bool use[1000001];

void solve(int p,int64_t n,int64_t m){
	if(m == 0) return;
	if(m >= n-1) {
		ans[p] = n;
		use[n] = true;
		solve(p+1,n-1,m-n+1);
	}
	else{
		ans[p] = m+1;
		use[m+1] = true;
	}
}

int main()
{
	IOS;
	int64_t n,m;
	cin >> n >> m;
		memset(use,false,sizeof(use));
		solve(0,n,m);
		int top;
		for(top=0;ans[top];top++);
		for(int i=0;i<top;i++) cout << ans[i] << ' ';
		for(int i=top,j=1;i<n;i++){
			while(use[j]) j++;
			use[j] = true;
			cout << j << ' ';
		}
		cout << '\n';
	
		
   return 0;
}


