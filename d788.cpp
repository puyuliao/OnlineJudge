#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 100000
#define lowbit(x) (x&-x)

int n;
int in[N];
int bt[N+1];

void add(int x,int k){
	for(;x<=n;x+=lowbit(x))
		bt[x] += k;
}

int query(int x){
	int ans = 0;
	for(;x;x-=lowbit(x))
		ans += bt[x];
	return ans;
}

int main()
{
	IOS;	
	while(cin >> n){
		for(int i=0;i<n;i++) cin >> in[i];
		memset(bt,0,sizeof(bt));
		for(int i=0;i<n;i++){
			int k = n - in[i] + 1;
			cout << query(k) + 1 << '\n';
			add(k,1);
		}
	}

   return 0;
}


